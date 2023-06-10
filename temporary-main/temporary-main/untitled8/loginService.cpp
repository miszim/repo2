
#include "main.h"



void Service::loginSystem(User &user){
    try {
        loginInterface();
        insertLoginData(user);
        loginValidation(user);
    }catch (std::invalid_argument& e) {
        std::cerr << e.what();
        loginSystem(user);
    }
};

void Service::loginInterface(){
    std::cout<<"Insert email and password to log in\n";
};

void Service::insertLoginData(User& user)
{
    controller.insertUserEmail(user);
    controller.insertUserPassword(user);
};

void Service::loginValidation(User insertedUser){
    bool credentialsMatch = false;
    User tmp;
    for(int i = 0;i<AuthorizationService.userList.size();i++)
    {
        tmp = AuthorizationService.userList[i];
        if(loginEmailMatch(insertedUser, tmp))
            if(loginPasswordMatch(insertedUser, tmp))
                credentialsMatch=true;
    }
    if(!credentialsMatch)
        throw std::invalid_argument("Incorrect Email or Password, try again\n");
};

bool Service::loginEmailMatch(User insertedUser, User existingUser)
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

bool Service::loginPasswordMatch(User insertedUser, User existingUser)
{
    std::string insertedPassword;
    std::string existingPassword;
    insertedPassword = insertedUser.getPassword();
    existingPassword = existingUser.getPassword();
    if(insertedPassword==existingPassword)
        return true;
    return false;
};



void Service::passwordSystem() {
    passwordChangeInterface();
    loginSystem(user);
    changePassword(AuthorizationService.userList);
    passwordChangeAfirmation();
};

void Service::passwordChangeInterface() {
    std::cout<<"Hello to change your password you must log in : "<<std::endl;
}

void Service::passwordRequirements(){
    std::cout<<"Add new password to change your old one, the new password must be between 9 and 20 characters long\n and should contain at least one uppercase letter and one special character and be different than the old one\n";
};

void Service::newPasswordInsert(User &user){
    std::string newPassword;
    std::cin.sync();
    getline(std::cin, newPassword);
    user.setPassword(newPassword);
};

void Service::changePassword(std::vector<User> &userList) {
    passwordRequirements();
    newPasswordInsert(userList[AuthorizationService.findUser(user.getEmail())]);
    try {
        AuthorizationService.passwordValidation(userList[AuthorizationService.findUser(user.getEmail())]);
    }catch (std::invalid_argument& e) {
        std::cerr << "User creation failed. Error: " << e.what() << std::endl;
        changePassword(userList);
    }
};
void Service::passwordChangeAfirmation(){
    std::cout<<"The password has been sucesfully changed"<<std::endl;
};

void Service::exit(){
    std::exit(0);
};



Service::Service(){}

