//
// Created by 28495 on 2022/9/9.
//
#include<string>
#include<iostream>
using namespace std;

#ifndef AP_PROJECT_1_USER_H
#define AP_PROJECT_1_USER_H


class User {
private:
    string username;
    string password;
    string userID;
    string phoneNumber;
    float balance; //保留一位小数
    string userState;
public:
    void select_function();
    void buyer();
    void seller();
    void info();
    void logout();
};


#endif //AP_PROJECT_1_USER_H
