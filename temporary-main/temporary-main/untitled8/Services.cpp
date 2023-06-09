#include "main.h"


int authorizationService::lastId = 0;
std::vector<User> authorizationService::userList;

void authorizationService::nameValidation(User &user){
    std::string nameToValidate = user.getName();
    if (!isValidName(nameToValidate))
    {
        throw std::invalid_argument("Inappropriate Name, do not use any special character\n");
    }
}

bool authorizationService::isValidName(std::string str) {
    for (char c : str) {
        if (!std::isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

void authorizationService::passwordValidation(User &user) {
    std::string passwordToValidate= user.getPassword();
    bool hasValidLength = hasCorrectLength(passwordToValidate);
    bool isUppercase = isUpperCase(passwordToValidate);
    bool hasSpecialChar = hasSpecialCharacter(passwordToValidate);

    if (!isValidPassword(hasValidLength, isUppercase, hasSpecialChar)) {
        throw std::invalid_argument("The password must be between 9 and 20 characters long and should contain at least one uppercase letter and one special character.\n");
    }
}

bool authorizationService::isValidPassword(bool hasCorrectLength, bool isUpperCase, bool hasSpecialChar) {
    return hasCorrectLength && isUpperCase && hasSpecialChar;
}

bool authorizationService::hasCorrectLength(std::string password) {
    if (password.length() >= 9 && password.length() <= 20) {
        return true;
    }
    return false;
}

bool authorizationService::hasSpecialCharacter(std::string password) {
    for (int i = 0; i < password.length(); i++) {
        if (((password[i] >= 33) && (password[i] <= 64)) || ((password[i] >= 91) && (password[i] <= 96)) ||
            ((password[i] >= 123) && (password[i] <= 126)))
        {
            return true;
        }
    }
    return false;
}

bool authorizationService::isUpperCase(std::string password) {
    for (int i = 0; i < password.length(); i++) {
        if ((password[i] >= 65) && (password[i] <= 90)) {
            return true;
        }
    }
    return false;
}

void authorizationService::emailValidation(User &user) {
    std::string emailToValidate = user.getEmail();
    bool isEmailCorrect = emailCheck(emailToValidate);
    if (!isEmailCorrect) {
        throw std::invalid_argument("Incorrect email");
    }
}

bool authorizationService::emailCheck(std::string email) {
    const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return std::regex_match(email, pattern);
}


void authorizationService::isUserValid(User &user) {
    nameValidation(user);
    passwordValidation(user);
    emailValidation(user);
    isEmailUnique(user);

}

void authorizationService::addUserToList(User user, std::vector<User>& userList)
{
     userList.push_back(user);
};


void authorizationService::isEmailUnique(User user)
{
    std::string nameToInsert=user.getEmail();
    User userFromList;
    std::string existingUserName;

    if(userList.size()>0){
        for(int i = 0; i <=userList.size();i++){
            userFromList = userList[0];
            existingUserName = userFromList.getEmail();
            if(nameToInsert == existingUserName) {
                throw std::invalid_argument("This email is already taken\n");
            }
        }
    }
};

int authorizationService::findUser(std::string email) {
    int usercounter=0;
    User userToFind;
    std::string userEmailToFind;
    for(int i = 0;i<userList.size();i++){
        userToFind = userList[i];
        userEmailToFind = userToFind.getEmail();
        if(userEmailToFind==email){
            return usercounter;
        }
        usercounter++;
    }
};


















authorizationService::authorizationService(){}


