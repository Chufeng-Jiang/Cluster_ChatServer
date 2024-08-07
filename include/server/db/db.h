#ifndef DB_H
#define DB_H

#include <mysql/mysql.h>
#include <string>

using namespace std;

// DB class
class MySQL
{
public:
    MySQL();

    ~MySQL();

    // DB connection
    bool connect();

    // DB update
    bool update(string sql);

    // DB Qquery
    MYSQL_RES *query(string sql);

    // get DB connection
    MYSQL * getConnection();

private:
    MYSQL *_conn;
};

#endif