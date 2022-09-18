//
// Created by 28495 on 2022/9/10.

#include "User.h"
#include "Admin.h"
#include "Commodity.h"
#include "Order.h"
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;

Admin admin;

user_node* read_user_data(const string file_name){
    ifstream in;
    in.open(file_name.data());

    int line_count = 0;
    string line;
    auto* user_list_head = new user_node;
    user_list_head = nullptr;
    auto* user_list_tail = user_list_head;

    while(getline(in, line))
    {
        line_count++;
        if(line_count > 1){
            char config[7][25];

            istringstream str(line);
            string out;

            int index = 0;
            while(getline(str, out, ',')){
                char feature[25];
                strcpy(feature, out.c_str());
                strcpy(config[index] , feature);
                index++;
            }

            auto* user_list_temp = new user_node;
            user_list_temp->user = User(config[0], config[1], config[2], config[3], config[4], config[5], config[6]);
            if(user_list_head == nullptr) user_list_head = user_list_tail = user_list_temp;
            else{
                user_list_tail->next = user_list_temp;
                user_list_tail = user_list_tail->next;
            }
        }
    }
    //user_list_head->user.print_info();
    return user_list_head;
}

commodity_node* read_commodity_data(const string file_name){
    ifstream in;
    in.open(file_name.data());

    int line_count = 0;
    string line;
    commodity_node* cd_list_head = new commodity_node;
    cd_list_head = nullptr;
    commodity_node* cd_list_tail = cd_list_head;

    while(getline(in, line))
    {
        line_count++;
        if(line_count > 1){
            char config[8][25];

            istringstream str(line);
            string out;

            int index = 0;
            while(getline(str, out, ',')){
                char feature[25];
                strcpy(feature, out.c_str());
                strcpy(config[index] , feature);
                index++;
            }

            auto* cd_list_temp = new commodity_node;
            cd_list_temp->cd = Commodity(config[0], config[1], config[2], config[3], config[4], config[5], config[6], config[7]);
            if(cd_list_head == nullptr) cd_list_head = cd_list_tail = cd_list_temp;
            else{
                cd_list_tail->next = cd_list_temp;
                cd_list_tail = cd_list_tail->next;
            }
        }
    }
    commodity_node* iter = cd_list_head;
    /*while(iter != nullptr){
        iter->cd.print_info();
        iter = iter->next;
    }*/
    return cd_list_head;
}

order_node* read_order_data(const string file_name){
    ifstream in;
    in.open(file_name.data());

    int line_count = 0;
    string line;
    order_node* order_list_head = new order_node;
    order_list_head = nullptr;
    order_node* order_list_tail = order_list_head;

    while(getline(in, line))
    {
        line_count++;
        if(line_count > 1){
            char config[7][25];

            istringstream str(line);
            string out;

            int index = 0;
            while(getline(str, out, ',')){
                char feature[25];
                strcpy(feature, out.c_str());
                strcpy(config[index] , feature);
                index++;
            }

            auto* order_list_temp = new order_node;
            order_list_temp->order = Order(config[0], config[1], config[2], config[3], config[4], config[5], config[6]);
            if(order_list_head == nullptr) order_list_head = order_list_tail = order_list_temp;
            else{
                order_list_tail->next = order_list_temp;
                order_list_tail = order_list_tail->next;
            }
        }
    }
    //order_list_head->order.print_info();
    return order_list_head;
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
        else if(command == "3") cout<<"User Login"<<endl<<endl; //用户登录
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



