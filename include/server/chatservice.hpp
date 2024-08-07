#ifndef CHATSERVICE_H
#define CHATSERVICE_H

#include <muduo/net/TcpConnection.h>
#include <unordered_map>
#include <functional>
#include <json.hpp>

using namespace std;
using namespace muduo;
using namespace muduo::net;
using namespace placeholders;

using json = nlohmann::json;

// The callback type to process the messages events
using MsgHandler = std::function<void(const TcpConnectionPtr &conn, json &js, Timestamp)>;

// Singleton Pattern
class ChatService
{
public:
    // function to get the only instance from the Singleton Class
    static ChatService *instance();

    // functionality for login
    void login(const TcpConnectionPtr &conn, json &js, Timestamp);

    // functionality for registration
    void reg(const TcpConnectionPtr &conn, json &js, Timestamp);

    // function to get the handler accoording to the message id
    MsgHandler getHandler(int msgid);

private:
    ChatService();

    // this map is to get the message id and the according method of the Handlers
    unordered_map<int, MsgHandler> _msgHandlerMap;
};

#endif