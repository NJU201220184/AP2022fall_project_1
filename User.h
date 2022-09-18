//
// Created by 28495 on 2022/9/9.
//
#include<string>
#include<iostream>
#include "Commodity.h"
#include "Order.h"
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
    commodity_node* _cd = new commodity_node; //Commodity on sale
    order_node* _order = new order_node;
public:
    User();
    User(char* str0, char* str1, char* str2, char* str3,
         char* str4, char* str5, char* str6); //Initialize
    void select_function();
    void seller_function();
    void buyer_function();
    void change_info(); //Change info & Recharge
    void print_info(); //Debug & Admin
};

struct user_node{
    User user;
    user_node* next;
};

#endif //AP_PROJECT_1_USER_H
