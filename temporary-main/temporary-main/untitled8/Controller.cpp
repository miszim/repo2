#include "main.h"

void Controller::createUser(User user){

    try {
        userID(user);
        insertUserName(user);
        insertUserEmail(user);
        insertUserPassword(user);
        service.isUserValid(user);
    } catch (std::invalid_argument& e) {
        std::cerr << "Login failed. Error: " << e.what() << std::endl;
        createUser(user);
    }
};

void Controller::userID(User user)
{
    user.setID(0);
};
void Controller::insertUserName(User user)
{
    std::string insertedName;
    std::cin.sync();
    getline(std::cin, insertedName);
    user.setName(insertedName);
};
void Controller::insertUserPassword(User user)
{
    std::string insertedPassword;
    std::cin.sync();
    getline(std::cin, insertedPassword);
    user.setPassword(insertedPassword);
};
void Controller::insertUserEmail(User user)
{
    std::string insertedEmail;
    std::cin.sync();
    getline(std::cin, insertedEmail);
    user.setEmail(insertedEmail);
};
void Controller::grantID(User user) {
    for (int i = 0; i < usersIDList.size(); i++) 
    {
        if (usersIDList[i] == 0) {
            user.setID(i+1);
            usersIDList[i] = i+1;
        }
        if (usersIDList[i] != 0||usersIDList.size()==(i+1)) {
            user.setID(i + 1);
            usersIDList[i+1] = i + 1;
        };
    }
};