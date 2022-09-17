//
// Created by 28495 on 2022/9/9.
//
#include<string>
#include<iostream>
#include "Commodity.h"
using namespace std;

#ifndef AP_PROJECT_1_USER_H
#define AP_PROJECT_1_USER_H


class User {
private:
    string username;
    string password;
    string userID;
    string phoneNumber;
    string address;
    float balance; //保留一位小数
    string userState;
    Commodity commodity_list[25]; //Commodity on sale

public:
    User(char* str0, char* str1, char* str2, char* str3,
         char* str4, char* str5, char* str6); //Initialize
    void select_function(); 
    void buyer(); //The function of buyer
    void seller(); //The function of seller
    void change_info(); //Change info & Recharge
};


#endif //AP_PROJECT_1_USER_H
