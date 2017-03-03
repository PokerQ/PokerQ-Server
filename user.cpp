#include "user.h"
#include <QString>

User::User(int id, QString username)
{
    this->id = id;
    this->username = username;
}

int User::getId() const
{
    return id;
}

void User::setId(int value)
{
    id = value;
}

QString User::getUsername() const
{
    return username;
}

void User::setUsername(const QString &value)
{
    username = value;
}
