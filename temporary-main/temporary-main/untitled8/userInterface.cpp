//
// Created by Konik on 04.06.2023.
//

#include "main.h"

int graphicalInterface::userDecision(std::string insertedAction){
    if(insertedAction=="Sign up"){
        return 0;
    }else if(insertedAction=="Log in"){
        return 1;
    }else if(insertedAction=="Change password") {
        return 2;
    }else if(insertedAction=="Exit"){
        return 4;
    }else
        return 404;
};

void graphicalInterface::correctSpelling(std::string &insertedAction){
    insertedAction[0] = std::toupper(insertedAction[0]);
    for(int i = 1;i<insertedAction.length();i++){
        insertedAction[i] = std::tolower(insertedAction[i]);
    }
    while (!insertedAction.empty() && insertedAction.back() == ' ') {
        insertedAction.pop_back();
    }
};

void graphicalInterface::displayFunctions() {
    std::cout<<"[Sign up]\t[Log in]\t[Change password]\t[Exit]\n";
};

int graphicalInterface::insertedAction(){
    std::string insertedAction;
    displayFunctions();
    std::cout<<"Insert action"<<std::endl;
    std::cin.sync();
    getline(std::cin, insertedAction);
    correctSpelling(insertedAction);
    return userDecision(insertedAction);
};

void graphicalInterface::userAction() {
    userGreetings();
    switch (insertedAction()) {
        case 0:
            controller.userRegistery();
            std::cout<<"You have successfully register a user\n";
            break;
        case 1:
            loginservice.loginSystem(user);
            std::cout<<"You have successfully log in to application\n";
            break;
        case 2:
            loginservice.passwordSystem();
            std::cout<<"You have successfully change user password\n";
            break;
        case 3:
            loginservice.exit();
        case 404:
            std::cout<<"Incorrectly writen action try again\n";
            userAction();
        default:
            throw std::invalid_argument("Do not applied action");
    }
    userAction();
};

void graphicalInterface::userGreetings(){
    std::cout<<"What would you like to do now?\n";
};

void graphicalInterface::wholeSystem(){
    std::cout<<"Hello"<<std::endl;
    userAction();
};
