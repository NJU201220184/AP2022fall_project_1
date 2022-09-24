//
// Created by 28495 on 2022/9/9.
//

#include "User.h"
#include "seller.h"

User::User() {

}

User::User(char* str0, char* str1, char* str2, char* str3,
           char* str4, char* str5, char* str6)
{
    userID = str0;
    username = str1;
    password = str2;
    phoneNumber = str3;
    address = str4;
    balance = atof(str5);
    userState = str6;
}

void User::change_info() {
    cout<<"Please input the operation you want :"<<endl;
    cout<<"============================================================================================="<<endl;
    cout<<"1.Change password 2.Change phoneNumber 3.Change address 4.Recharge 5.Return to user main menu"<<endl;
    cout<<"============================================================================================="<<endl;
    cout<<endl;
    cout<<"Please input a command:";
    string command;
    cin>>command;
    while(command != "5"){
        if(command == "1") {}
        else if(command == "2") {}
        else if(command == "3") {}
        else if(command == "4") {}
        else cout<<"Unknown command, please try again..."<<endl<<endl;
        cout<<"Please input the operation you want :"<<endl;
        cout<<"============================================================================================="<<endl;
        cout<<"1.Change password 2.Change phoneNumber 3.Change address 4.Recharge 5.Return to user main menu"<<endl;
        cout<<"============================================================================================="<<endl;
        cout<<endl;
        cout<<"Please input a command:";
        cin>>command;
    }
    cout<<"Return to User Main Menu"<<endl<<endl;
}

void User::select_function() {
    cout<<"======================================================="<<endl;
    cout<<"1.Buyer Login 2.Seller Login 3.Personal Center 4.Log out"<<endl;
    cout<<"======================================================="<<endl;
    cout<<endl;
    cout<<"Please input a command:";
    string command;
    cin>>command;
    while(command != "4"){
        if(command == "1") select_function();
        else if(command == "2") buyer_function();
        else if(command == "3") change_info();
        else cout<<"Unknown command, please try again..."<<endl<<endl;
        cout<<"======================================================="<<endl;
        cout<<"1.Buyer Login 2.Seller Login 3.Personal Center 4.Log out"<<endl;
        cout<<"======================================================="<<endl;
        cout<<endl;
        cout<<"Please input a command:";
        cin>>command;
    }
    cout<<"Log out"<<endl<<endl;
}

void User::print_info() {
    cout<<userID<<'\t'<<username<<'\t'<<phoneNumber<<'\t'<<address<<'\t'<<balance<<'\t'<<userState<<'\n';
}

void User::seller_function() {

}

void User::buyer_function() {

}


