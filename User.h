//
// Created by 28495 on 2022/9/9.
//

#ifndef AP_PROJECT_1_USER_H
#define AP_PROJECT_1_USER_H

#include <iostream>
#include <string>
using namespace std;


class User {
private:
    string username;
    string password;
    string userID;
    string phoneNumber;
    string address;
    float balance; //保留一位小�?
    string userState;

public:
    User();
    User(char* str0, char* str1, char* str2, char* str3,
         char* str4, char* str5, char* str6); //Initialize
    void select_function();
    void seller_function();
    void buyer_function();
    void change_info(); //Change info & Recharge
    void print_info(); //Debug & Admin
    void change_state();
    void buyer_show_all_commodities(); //buyer
    void seller_show_commodities(); //seller
    void buyer_show_orders(); //buyer
    void seller_show_orders(); //seller
    void search_commodity(); //buyer
    void seller_add_commodity(); //seller
    void off_shelf_commodity(); //seller
    void change_cd_info();
    void buyer_auction();
    void buy(float money);
    void sell(float money);
    string _username();
    string _password();
    string _userID();
    string _phoneNumber();
    string _address();
    float _balance();
    string _userState();
};

#endif //AP_PROJECT_1_USER_H
