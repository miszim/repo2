#include "main.h"

User Controller::userRegistery() {
    User user;
    try {
        userID(user);
        registrationInterface();
        insertUserName(user);
        insertUserPassword(user);
        insertUserEmail(user);
        service.isUserValid(user);
    } catch (std::invalid_argument& e) {
        std::cerr << "User creation failed. Error: " << e.what() << std::endl;
        userRegistery();
    }
    grantID(user);
    service.addUserToList(user, service.userList);
    return user;
}

void Controller::userID(User &user)
{
    user.setID(0);
};
void Controller::insertUserName(User &user)
{
    std::string insertedName;
    std::cout<<"Insert User Name :\n";
    std::cin.sync();
    getline(std::cin, insertedName);
    user.setName(insertedName);
};
void Controller::insertUserPassword(User &user)
{
    std::string insertedPassword;
    std::cout<<"Insert User Password :\n";
    std::cin.sync();
    getline(std::cin, insertedPassword);
    user.setPassword(insertedPassword);
};
void Controller::insertUserEmail(User &user)
{
    std::string insertedEmail;
    std::cout<<"Insert User Email :\n";
    std::cin.sync();
    getline(std::cin, insertedEmail);
    user.setEmail(insertedEmail);
};
void Controller::grantID(User &user) {
    user.setID(authorizationService::lastId++);
};

void Controller::registrationInterface(){
    std::cout<<"Welcome!\n To registry a user insert :\n - a username without special characters\n - a password between 9 and 20 characters long with at least one uppercase letter and one special character\n - a email\n";
};






Controller::Controller(){};