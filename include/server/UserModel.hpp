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

private:
};

#endif