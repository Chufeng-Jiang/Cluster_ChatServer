#include "db.h"
#include <muduo/base/Logging.h>

// configuration for Database
static string server = "127.0.0.1";
static string user = "root";
static string password = "root";
static string dbname = "chat";


MySQL::MySQL()
{
    _conn = mysql_init(nullptr);
}

MySQL::~MySQL()
{
    if (_conn != nullptr)
    {
        mysql_close(_conn);
    }
}

// DB connection
bool MySQL::connect()
{
    MYSQL * p = mysql_real_connect(_conn, server.c_str(), user.c_str(), password.c_str(), dbname.c_str(), 3306, nullptr, 0);

    if (p != nullptr)
    {
        mysql_query(_conn, "set names gbk");
    }

    return p;
}

// DB update
bool MySQL::update(string sql)
{

    if (mysql_query(_conn, sql.c_str()))
    {
        LOG_INFO << __FILE__ << ":" << __LINE__ << ":" << sql << "update FAILED!!!";

            return false;
    }

    return true;
}

// DB Qquery
MYSQL_RES * MySQL::query(string sql)
{

    if (mysql_query(_conn, sql.c_str()))
    {
        LOG_INFO << __FILE__ << ":" << __LINE__ << ":" << sql << "query FAILED!!!";

            return nullptr;
    }

    return mysql_use_result(_conn);
}