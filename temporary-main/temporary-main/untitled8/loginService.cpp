
#include "main.h"



void loginService::loginData(){
    User user;
    try {
        loginInterface();
        insertLoginData(user);
        loginValidation(user);
    }catch (std::invalid_argument& e) {
        std::cerr << e.what();
        loginData();
    }
};

void loginService::loginInterface(){
    std::cout<<"Insert email and password to log in\n";
};

void loginService::insertLoginData(User& user)
{
    controller.insertUserEmail(user);
    controller.insertUserPassword(user);
};

void loginService::loginValidation(User insertedUser){
    bool credentialsMatch = false;
    User tmp;
    for(int i = 0;i<user.userList1.size();i++)
    {
        tmp = user.userList1[i];
        if(loginEmailMatch(insertedUser, tmp))
            if(loginPasswordMatch(insertedUser, tmp))
                credentialsMatch=true;
    }
    if(!credentialsMatch)
        throw std::invalid_argument("Incorrect Email or Password, try again\n");
};

bool loginService::loginEmailMatch(User insertedUser, User existingUser)
{
    std::string insertedEmail;
    std::string existingEmail;
    insertedEmail = insertedUser.getEmail();
    existingEmail = existingUser.getEmail();
    if(insertedEmail==existingEmail){
        return true;
    }
    return false;
};

bool loginService::loginPasswordMatch(User insertedUser, User existingUser)
{
    std::string insertedPassword;
    std::string existingPassword;
    insertedPassword = insertedUser.getPassword();
    existingPassword = existingUser.getPassword();
    if(insertedPassword==existingPassword)
        return true;
    return false;


};



loginService::loginService(){};
