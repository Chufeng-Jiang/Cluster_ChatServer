#include "chatservice.hpp"
#include "public.hpp"
#include <string>
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
    _msgHandlerMap.insert({REG_MSG, std::bind(&ChatService::login, this, _1, _2, _3)});
}

// functionality for login. Only when the user login, and this function will be called. But itself dosen't know when (this is responsibled by Network Layer).
void ChatService::login(const TcpConnectionPtr &conn, json &js, Timestamp)
{
    LOG_INFO << "do login service";
}

// functionality for registration
void ChatService::reg(const TcpConnectionPtr &conn, json &js, Timestamp)
{
    LOG_INFO << "do reg service";
}

// function to get the handler accoording to the message id
MsgHandler ChatService::getHandler(int msgid)
{
    // logger: error, if msgid doesn't have the accordingly  callback
    auto it = _msgHandlerMap.find(msgid);
    if (it == _msgHandlerMap.end())
    {
        // return a default null Handler, null operation with error msg
        return [=] (const TcpConnectionPtr &conn, json &js, Timestamp){
             LOG_ERROR << "msgid:" << msgid << " can not find handler!";
        };
    }
    else
    {
        return _msgHandlerMap[msgid];
    }
}