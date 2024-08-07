#include "UserModel.hpp"
#include "db.h"

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
    if(mysql.connect()){
        if(mysql.update(sql)){
            //get the primary key of the user who has been successfully inserted.
            user.setId(mysql_insert_id(mysql.getConnection()));
            return true;
        }
    } 

    return false;
}