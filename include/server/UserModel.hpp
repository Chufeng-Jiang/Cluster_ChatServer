#ifndef USERMODEL_H
#define USERMODEL_H

#include "user.hpp"

// process the data in database for User Object
// insert, delete, query, modify
class UserModel
{
public:
    // insert new users
    bool insert(User &user);

    // query user info by primary key
    User query(int id);

    // update user info
    bool updateState(User user);

private:
};

#endif