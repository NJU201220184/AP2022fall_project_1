//
// Created by 28495 on 2022/9/10.
//

#ifndef AP_PROJECT_1_MENU_H
#define AP_PROJECT_1_MENU_H

#include "Admin.h"
#include "File.h"
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;

Admin admin;
string user_file_name = "D:\\AP_project_1\\user.txt";
string commodity_file_name = "D:\\AP_project_1\\commodity.txt";
string order_file_name = "D:\\AP_project_1\\order.txt";

user_node* user_list = read_user_data(user_file_name);
commodity_node* cd_list = read_commodity_data(commodity_file_name);
order_node* order_list = read_order_data(order_file_name);

void User_Signup(){

}

void User_Login(){
    string username;
    cout<<endl;
    cout<<"Please input username:";
    cin>>username;
    string password;
    cout<<"Please input password:";
    cin>>password;
    auto iter = user_list;
    bool is_found = false;
    while(iter != nullptr){
        if(iter->user._username() == username && iter->user._password() == password){
            if(iter->user._userState() == "active"){
                cout<<"Valid user!"<<endl;
                is_found = true;
                iter->user.select_function();
            }
            break;
        }
        iter = iter->next;
    }
    if(!is_found) cout<<"Invalid user..."<<endl;
}

void main_menu(){
    cout<<"======================================================="<<endl;
    cout<<"1.Administrator Login 2.User Signup 3.User Login 4.Quit"<<endl;
    cout<<"======================================================="<<endl;
    cout<<endl;
    cout<<"Please input a command:";
    string command;
    cin>>command;
    while(command != "4"){
        if(command == "1") admin.admin_login();
        else if(command == "2") cout<<"User Signup"<<endl<<endl; //用户注册
        else if(command == "3") User_Login(); //用户登录
        else cout<<"Unknown command, please try again..."<<endl<<endl; //未识别命令
        cout<<"======================================================="<<endl;
        cout<<"1.Administrator Login 2.User Signup 3.User Login 4.Quit"<<endl;
        cout<<"======================================================="<<endl;
        cout<<endl;
        cout<<"Please input a command:";
        cin>>command;
    }
    cout<<"System Quit"<<endl;
}

#endif //AP_PROJECT_1_MENU_H

