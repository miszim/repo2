//
// Created by Konik on 04.06.2023.
//

#include "main.h"


void graphicalInterface::userGreetings(){
  std::cout<<"Hello"<<std::endl;
  std::cout<<"What would you like to do?\n";
};

void graphicalInterface::displayFunctions() {
    std::cout<<"[Signe up]\t[Log in]\t[Password update]\n";
};
void graphicalInterface::userAction(int action) {
    switch (action){
        case 0: controller.userRegistery() ;
            break;
        case 1: loginservice.loginData();
            break;
        case 2:
            break;
        default: throw std::invalid_argument("Do not applied action");
    }



};