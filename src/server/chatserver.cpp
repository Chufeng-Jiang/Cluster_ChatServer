#include "chatserver.hpp"
#include "chatservice.hpp"
#include <json.hpp>
#include <functional>
#include <string>
#include <iostream>

using namespace std;
using namespace placeholders;
using json = nlohmann::json;

ChatServer::ChatServer(EventLoop *loop,
                       const InetAddress &listenAddr,
                       const string &nameArg)
    : _server(loop, listenAddr, nameArg), _loop(loop)
{
    // register for connection callback
    _server.setConnectionCallback(std::bind(&ChatServer::onConnection, this, _1));

    // register for Message callback
    _server.setMessageCallback(std::bind(&ChatServer::onMessage, this, _1, _2, _3));

    // set the number of threads
    _server.setThreadNum(4);
}

void ChatServer::start()
{
    _server.start();
}

// the callback for connection event
void ChatServer::onConnection(const TcpConnectionPtr &conn)
{
    // when client disconnected from server
    if (!conn->connected())
    {
        cout << "is disconnected......." << endl;
        ChatService::instance()->clientCloseException(conn);
        cout << "is shutting down...." << endl;
        conn->shutdown();
    }
}

// the callback for read and write event
void ChatServer::onMessage(const TcpConnectionPtr &conn,
                           Buffer *buffer,
                           Timestamp time)
{
    string buf = buffer->retrieveAllAsString();

    // data decode
    json js = json::parse(buf);

    // decoupling the code of the network module from the code of the business module
    // js["msgid"] -> business handler -> conn js time
    auto msgHandler = ChatService::instance()->getHandler(js["msgid"].get<int>());

    // callback the Handler of the binded event and messages, to execute the business service.
    msgHandler(conn, js, time);
}
