#include "main.h"


int User::getID()
{
    return userID;
};
void User::setID(int ID)
{
    userID = ID;
};
std::string User::getName()
{
    return name;
};
void User::setName(std::string Name)
{
    name = Name;
};
std::string User::getEmail()
{
    return email;
};
void User::setEmail(std::string Email)
{
    email=Email;
};
std::string User::getPassword()
{
    return password;
};
void User::setPassword(std::string Password)
{
    password = Password;
};
User::User() {
    userID = 0;
}