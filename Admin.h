//
// Created by 28495 on 2022/9/10.
//
#include<iostream>
#include "Commodity.h"
#include "User.h"
#include "Order.h"
using namespace std;

#ifndef AP_PROJECT_1_ADMIN_H
#define AP_PROJECT_1_ADMIN_H


class Admin {
private:
    string admin_name = "admin";
    string admin_password = "123456";
public:
    void admin_login();
    void admin_menu();
    void show_all_commodities(commodity_node* cd_list);
    void search_commodity(commodity_node* cd_list);
    static void off_shelf_commodity(commodity_node* cd_list);
    static void show_all_orders(order_node* order_list);
    static void show_all_users(user_node* user_list);
    void block_user(user_node* user_list);
};


#endif //AP_PROJECT_1_ADMIN_H
