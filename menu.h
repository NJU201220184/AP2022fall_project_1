//
// Created by 28495 on 2022/9/10.
//

#ifndef AP_PROJECT_1_MENU_H
#define AP_PROJECT_1_MENU_H

#endif //AP_PROJECT_1_MENU_H

#include "User.h"
#include "Admin.h"
using namespace std;

Admin admin;

void main_menu(){
    cout<<"======================================================="<<endl;
    cout<<"1.Administrator Login 2.User Signup 3.User Login 4.Quit"<<endl;
    cout<<"======================================================="<<endl;
    cout<<endl;
    cout<<"Please input a command:";
    string command;
    cin>>command;
    while(command != "4"){
        if(command == "1") {
            admin.admin_login();
        }
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
    cout<<"System killed"<<endl;
}

