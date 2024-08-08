#include "UserModel.hpp"
#include "db.h"

// process the data in database for User Object
// insert, delete, query, modify

// insert new users
bool UserModel::insert(User &user)
{
    // combine the components for a sql
    char sql[1024] = {0};
    sprintf(sql, "insert into user(name, password, state) values('%s','%s','%s')",
            user.getName().c_str(), user.getPwd().c_str(), user.getState().c_str());

    MySQL mysql;
    /************************************************************
    Connect to DB
    -> execute the sql insert a new user
    -> get the promary keyof the user
    -> update the user id using the primary key in user db
    ************************************************************/
    if (mysql.connect())
    {
        if (mysql.update(sql))
        {
            // get the primary key of the user who has been successfully inserted.
            user.setId(mysql_insert_id(mysql.getConnection()));
            return true;
        }
    }

    return false;
}

// query user info by primary key
User UserModel::query(int id)
{
    char sql[1024] = {0};
    sprintf(sql, "select * from user where id = %d", id);

    MySQL mysql;

    if (mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql);
        if (res != nullptr)
        {
            MYSQL_ROW row = mysql_fetch_row(res);
            if (row != nullptr)
            {
                User user;
                user.setId(atoi(row[0]));
                user.setName(row[1]);
                user.setPwd(row[2]);
                user.setState(row[3]);

                mysql_free_result(res); // otherwise will cause memory leak
                return user;
            }
        }
    }

    return User();
}

// query user info by primary key
bool UserModel::updateState(User user)
{
    char sql[1024] = {0};

    sprintf(sql, "update user set state = '%s' where id = %d", user.getState().c_str(), user.getId());

    MySQL mysql;

    if (mysql.connect())
    {
        if (mysql.update(sql))
        {

            return true;
        }
    }

    return false;
}