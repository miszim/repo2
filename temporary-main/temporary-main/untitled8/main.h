#ifndef UNTITLED8_MAIN_H
#define UNTITLED8_MAIN_H

#include <iostream>
#include <string>
#include <istream>
#include <regex>
#include <vector>
#include <cctype>


//extern int ID = 0;
class User {
private:
    int userID;
    std::string name;
    std::string email;
    std::string password;

public:
    static std::vector<User> userList1;
    User();
    int getID();
    void setID(int ID);
    std::string getName();
    void setName(std::string Name);
    std::string getEmail();
    void setEmail(std::string Email);
    std::string getPassword();
    void setPassword(std::string Password);
};

class authorizationService{
public:

    authorizationService();
    static int lastId;


    void nameValidation (User &user);
    bool isValidName(std::string str);
    void passwordValidation(User &user);
    bool isValidPassword(bool hasCorrectLength, bool isUpperCase, bool hasSpecialChar);
    bool hasCorrectLength(std::string password);
    bool hasSpecialCharacter(std::string password);
    bool isUpperCase(std::string password);
    void emailValidation(User &user);
    bool emailCheck(std::string email);
    void isUserValid(User &user);
    void isEmailUnique(User user);

    void addUserToList(User user, std::vector<User>& userList);
    void displayUserFromList(int number);


};


class Controller{
public:
    Controller();
    authorizationService service;
    User userRegistery();

    void registrationInterface();
    void userID(User &user);
    void insertUserName(User &user);
    void insertUserPassword(User &user);
    void insertUserEmail(User &user);
    void grantID(User &user);

    void changePassword(std::vector<User>& userList);
};

class loginService{
public:
    loginService();
    User user;
    Controller controller;
    authorizationService AuthorizationService;
    void loginData();
    void loginInterface();
    void insertLoginData(User& user);
    void loginValidation(User insertedUser);
    bool loginEmailMatch(User insertedUser, User existingUser);
    bool loginPasswordMatch(User insertedUser, User existingUser);
};


class graphicalInterface{

public:
    Controller controller;
    loginService loginservice;
    authorizationService AuthorizationService;
    void userGreetings();
    void displayFunctions();
    void userAction(int action);

};




#endif