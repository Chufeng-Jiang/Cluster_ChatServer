#ifndef PUBLIC_H
#define PUBLIC_H

/*
The public file for Servers and Clients
*/

enum EnMsgType{
    LOGIN_MSG = 1, // Login message
    LOGIN_MSG_ACK,
    REG_MSG, // Registration message
    REG_MSG_ACK, // ack for registration 
    ONE_CHAT_MSG, // 1-1 TALK
};

#endif
