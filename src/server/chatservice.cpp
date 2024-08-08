#include "chatservice.hpp"
#include "public.hpp"
#include "offlinemessagemodel.hpp"

#include <string>
#include <vector>
#include <muduo/base/Logging.h>

using namespace muduo;
using namespace std;

ChatService *ChatService::instance()
{
    static ChatService service;
    return &service;
}

// function of registration message and the Handler callback operation
ChatService::ChatService()
{
    _msgHandlerMap.insert({LOGIN_MSG, std::bind(&ChatService::login, this, _1, _2, _3)});
    _msgHandlerMap.insert({REG_MSG, std::bind(&ChatService::reg, this, _1, _2, _3)});
    _msgHandlerMap.insert({ONE_CHAT_MSG, std::bind(&ChatService::oneChat, this, _1, _2, _3)});
}

// functionality for login. Only when the user login, and this function will be called. But itself dosen't know when (this is responsibled by Network Layer).
void ChatService::login(const TcpConnectionPtr &conn, json &js, Timestamp)
{
    int id = js["id"].get<int>();
    string pwd = js["password"];

    User user = _userModel.query(id);

    if (user.getId() == id && user.getPwd() == pwd)
    {
        // user already login, and duplicat login is not allowed
        if (user.getState() == "online")
        {
            json response;
            response["msgid"] = LOGIN_MSG_ACK;
            response["errno"] = 2;
            response["errmsg"] = "User already logged in, please re-enter a new account user.";
            conn->send(response.dump());
        }
        else
        {
            // once login, store the user info -> will be called by multiple threads -> thread safety prblem -> mutex
            // keep the lock range as small as possible.
            {
                lock_guard<mutex> lock(_connMutex);
                _userConnMap.insert({id, conn});
            }

            // login sucessfully -> update state
            user.setState("online");
            _userModel.updateState(user);
            json response;
            response["msgid"] = LOGIN_MSG_ACK;
            response["errno"] = 0;
            response["id"] = user.getId();
            response["name"] = user.getName();

            // check and process the offline messages. If there's offline msg, transfer it.
            vector<string> vec = _offlineMsgModel.query(id);
            if (!vec.empty())
            {
                response["offlinemsg"] = vec;

                // once checked, remove the offlinemsg from the db.
                _offlineMsgModel.remove(id);
            }

            conn->send(response.dump());
        }
    }
    else
    {
        // if user doesn't exist, login failed
        json response;
        response["msgid"] = LOGIN_MSG_ACK;
        response["errno"] = 1;
        response["errmsg"] = "User name or password doesn't match.";
        conn->send(response.dump());
    }
}

// functionality for registration
void ChatService::reg(const TcpConnectionPtr &conn, json &js, Timestamp)
{
    string name = js["name"];
    string pwd = js["password"];

    User user;
    user.setName(name);
    user.setPwd(pwd);
    bool state = _userModel.insert(user);
    if (state)
    {
        // register successfully
        json response;
        response["msgid"] = REG_MSG_ACK;
        response["errno"] = 0;
        response["id"] = user.getId();
        conn->send(response.dump());
    }
    else
    {
        // register fail
        json response;
        response["msgid"] = REG_MSG_ACK;
        response["errno"] = 1;
        response["id"] = user.getId();
        conn->send(response.dump());
    }
}

// function to get the handler accoording to the message id
MsgHandler ChatService::getHandler(int msgid)
{
    // logger: error, if msgid doesn't have the accordingly  callback
    auto it = _msgHandlerMap.find(msgid);
    if (it == _msgHandlerMap.end())
    {
        // return a default null Handler, null operation with error msg
        return [=](const TcpConnectionPtr &conn, json &js, Timestamp)
        {
            LOG_ERROR << "msgid:" << msgid << " can not find handler!";
        };
    }
    else
    {
        return _msgHandlerMap[msgid];
    }
}

// function to handle client logout abnormallly
void ChatService::clientCloseException(const TcpConnectionPtr &conn)
{
    User user;

    {
        // may be some other user is trying to login and the _userConnMap will be update cncurrently
        // use a mutex to avoid the above case
        lock_guard<mutex> lock(_connMutex);

        // find the id by conn
        for (auto it = _userConnMap.begin(); it != _userConnMap.end(); it++)
        {
            if (it->second == conn)
            {
                user.setId(it->first);
                _userConnMap.erase(it);
                break;
            }
        }
    }

    // update the user state
    if (user.getId() != -1)
    {
        user.setState("offline");
        _userModel.updateState(user);
    }
}

// 1-1 talk
void ChatService::oneChat(const TcpConnectionPtr &conn, json &js, Timestamp)
{
    int toid = js["to"].get<int>();

    {
        lock_guard<mutex> lock(_connMutex);

        auto it = _userConnMap.find(toid);

        if (it != _userConnMap.end())
        {
            // toid is online, and then tranfer the msgs
            it->second->send(js.dump());
            return;
        }
    }

    // toid is not online, store offline msg
    _offlineMsgModel.insert(toid, js.dump());
}

// reset the server for its exception
void ChatService::reset()
{
    // set online user as offline
    _userModel.resetState();
}