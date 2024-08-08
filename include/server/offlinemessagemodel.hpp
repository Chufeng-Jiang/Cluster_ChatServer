#ifndef OFFLINEMESSAGEMODEL_H
#define OFFLINEMESSAGEMODEL_H

#include <string>
#include <vector>

using namespace std;

class OfflineMsgModel
{
public:
    // store the user offline msg
    void insert(int userid, string msg);

    // delete the user offline msg
    void remove(int userid);

    // query the user offline msg
    vector<string> query(int userid);

private:
};

#endif