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
#include <string>
#include <ctime>
using namespace std;

Admin admin;
string user_file_name = "D:\\AP_project_1\\user.txt";
string commodity_file_name = "D:\\AP_project_1\\commodity.txt";
string order_file_name = "D:\\AP_project_1\\order.txt";

user_node* user_list = read_user_data(user_file_name);
commodity_node* cd_list = read_commodity_data(commodity_file_name);
order_node* order_list = read_order_data(order_file_name);

int user_count = 0;
int cd_count = 0;
int order_count = 0;

void check_time(){
    auto iter = cd_list;
    cout<<"Start checking..."<<endl;
    while(iter != nullptr){
        iter->cd.show_bid();
        clock_t now = clock();
        //若商品开拍时间>3min
        if(int(now) - iter->cd._create_time() > 180 * 1000){
            //check bid_node
            cout<<"This commodity has auction(s)"<<endl;
            iter->cd.check_bid();
        }
        iter = iter->next;
    }
    cout<<"Check is done."<<endl;
}

void User_Signup(){
    string username;
    cout<<endl;
    cout<<"Please input username:";
    cin>>username;
    string password;
    cout<<"Please input password:";
    cin>>password;
    cout<<"Please input new pass_word again:";
    string verification;
    cin>>verification;
    while(verification != password){
        cout<<"two passwords are not the same, please try again";
        cin>>verification;
    }
    auto* temp = new user_node;
    temp->next = nullptr;
    cout<<"Please input your phoneNumber:";
    string phoneNumber;
    cin>>phoneNumber;
    cin.ignore();
    cout<<"Please input your address:";
    string address;
    getline(cin, address);
    user_count++;
    int id = 1000 + user_count;
    string Uid = to_string(id);
    Uid[0] = 'U';
    string balance = "0.0";
    string state = "active";
    temp->next = nullptr;
    temp->user = User((char*)Uid.c_str(), (char*)username.c_str(), 
    (char*)password.c_str(), (char*)phoneNumber.c_str(), (char*)address.c_str(), (char*)balance.c_str(), (char*)state.c_str());
    auto user_tail = user_list;
    if(user_tail == nullptr) user_list = user_tail = temp;
    else{
        while(user_tail->next != nullptr) user_tail = user_tail->next;
        user_tail->next = temp;
    }
    write_user_data(user_list, user_file_name);
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
                cout<<endl<<"Log in successfully!"<<endl;
                is_found = true;
                iter->user.select_function();
            }
            break;
        }
        iter = iter->next;
    }
    if(!is_found) cout<<"User doesn't exist or deleted..."<<endl;
}

void main_menu(){
    for(auto it = user_list; it != nullptr; it = it->next){
        user_count++;
    }
    for(auto it = cd_list; it != nullptr; it = it->next){
        cd_count++;
    }
    for(auto it = order_list; it != nullptr; it = it->next){
        order_count++;
    }
    cout<<"======================================================="<<endl;
    cout<<"1.Administrator Login 2.User Signup 3.User Login 4.Quit"<<endl;
    cout<<"======================================================="<<endl;
    cout<<endl;
    cout<<"Please input a command:";
    string command;
    cin>>command;
    while(command != "4"){
        if(command == "1") admin.admin_login(); //管理员登�?
        else if(command == "2") User_Signup(); //用户注册
        else if(command == "3") User_Login(); //用户登录
        else cout<<"Unknown command, please try again..."<<endl<<endl; //�?识别命令
        check_time();
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

