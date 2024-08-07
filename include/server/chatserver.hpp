#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>

using namespace muduo;
using namespace muduo::net;

// main class for the chat sever
class ChatServer
{
public:
    // initialize the chatserver object
    ChatServer(EventLoop *loop,
               const InetAddress &listenAddr,
               const string &nameArg);

    // start the service
    void start();

private:
    // the callback for connection event
    void onConnection(const TcpConnectionPtr &);
    // the callback for read and write event
    void onMessage(const TcpConnectionPtr &,
                   Buffer *,
                   Timestamp);

    TcpServer _server;
    EventLoop *_loop;
};

#endif