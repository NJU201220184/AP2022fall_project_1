//
// Created by 28495 on 2022/9/10.
//
#include<iostream>
using namespace std;

#ifndef AP_PROJECT_1_ADMIN_H
#define AP_PROJECT_1_ADMIN_H


class Admin {
private:
    string admin_name = "admin";
    string admin_password = "123456";
public:
    void admin_login();
    static void admin_menu();
    void show_all_commodities();
    void search_commodity();
    void off_shelf_commodity();
    void show_all_orders();
    void show_all_users();
    void block_user();
};


#endif //AP_PROJECT_1_ADMIN_H
