//
// Created by Konik on 23.05.2023.
//
#include "main.h"



bool Services::nameValidation(User user){
    std::string nameToValidate = user.getName();
    bool isValidName = false;
    if (!(isValidName = IsValidName(nameToValidate)))
    {
        throw std::invalid_argument("Inappropriate Name, do not use any special character\n");
    }
    else
        return true;
}

bool Services::IsValidName(std::string name) {
    for (int i = 0; i < name.length(); i++) {
        if (name[i] < 65 || (name[i] >= 91 && name[i] <= 96) || name[i] >= 123)
            return false;
    }
    return true;
}

void Services::passwordValidation(User user) {
    std::string passwordToValidate= user.getPassword();
    bool hasValidLength = hasCorrectLength(passwordToValidate);
    bool isUppercase = isUpperCase(passwordToValidate);
    bool hasSpecialChar = hasSpecialCharacter(passwordToValidate);

    if (isValidPassword(hasValidLength, isUppercase, hasSpecialChar)) {
        throw std::invalid_argument("The password must be between 9 and 20 characters long and should contain at least one uppercase letter and one special character.\n");
    }
}

bool Services::isValidPassword(bool hasCorrectLength, bool isUpperCase, bool hasSpecialChar) {
    return !hasCorrectLength || !isUpperCase || !hasSpecialChar;
}

bool Services::hasCorrectLength(std::string password) {
    if (password.length() >= 9 && password.length() <= 20) {
        return true;
    }
    return false;
}

bool Services::hasSpecialCharacter(std::string password) {
    for (int i = 0; i < password.length(); i++) {
        if (((password[i] >= 33) && (password[i] <= 64)) || ((password[i] >= 91) && (password[i] <= 96)) ||
            ((password[i] >= 123) && (password[i] <= 126))) {
            return true;
        }
    }
    return false;
}

bool Services::isUpperCase(std::string password) {
    for (int i = 0; i < password.length(); i++) {
        if ((password[i] >= 65) && (password[i] <= 90)) {
            return true;
        }
    }
    return false;
}

void Services::emailValidation(User user) {
    std::string emailToValidate = user.getEmail();
    bool isEmailCorrect = Email_check(emailToValidate);
    if (!isEmailCorrect) {
        throw std::invalid_argument("Incorrect email");
    }
}

bool Services::Email_check(std::string email) {
    const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return std::regex_match(email, pattern);
}


void Services::isUserValid(User user) {
        nameValidation(user);
        passwordValidation(user);
        emailValidation(user);
}
