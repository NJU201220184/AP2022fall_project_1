//
// Created by 28495 on 2022/9/10.
//

#ifndef AP_PROJECT_1_ADMIN_H
#define AP_PROJECT_1_ADMIN_H

#include <string>
#include <iostream>
using namespace std;

class Admin {
private:
    string admin_name = "admin";
    string admin_password = "123456";
public:
    void admin_login();
    void admin_menu();
    void show_all_commodities();
    void search_commodity();
    static void off_shelf_commodity();
    static void show_all_orders();
    static void show_all_users();
    void block_user();
};


#endif //AP_PROJECT_1_ADMIN_H
