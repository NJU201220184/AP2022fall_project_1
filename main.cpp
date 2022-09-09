#include <iostream>
#include "User.h"

User user_list[20];

int main() {
    string command;
    cin>>command;
    while(command != "4"){
        if(command == "1") cout<<"Admin"<<endl; //Administrator
        else if(command == "2") cout<<"User Signup"<<endl; //用户注册
        else if(command == "3") cout<<"User Login"<<endl; //用户登录
        else cout<<"Unknown command, please try again..."<<endl; //未识别命令
        cin>>command;
    }
    cout<<"System killed"<<endl;
    return 0;
}
