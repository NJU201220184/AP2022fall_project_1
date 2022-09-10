//
// Created by 28495 on 2022/9/10.
//

#include "Admin.h"

void Admin::show_all_commodities() {

}

void Admin::admin_menu() {
    cout<<"========================================================================================================================"<<endl;
    cout<<"1.show_all_commodities 2.search_commodity 3.off_shelf_commodity 4.show_all_orders 5.show_all_users 6.block_user 7.logout"<<endl;
    cout<<"========================================================================================================================"<<endl;
    cout<<endl;
    cout<<"Please input a command:";
    string command;
    cin>>command;
    while(command != "7"){
        if(command == "1") cout<<"show_all_commodities"<<endl<<endl;
        else if(command == "2") cout<<"search_commodity"<<endl<<endl;
        else if(command == "3") cout<<"off_shelf_commodity"<<endl<<endl;
        else if(command == "4") cout<<"show_all_orders"<<endl<<endl;
        else if(command == "5") cout<<"show_all_users"<<endl<<endl;
        else if(command == "6") cout<<"block_user"<<endl<<endl;
        else cout<<"Unknown command, please try again..."<<endl<<endl;
        cout<<"========================================================================================================================"<<endl;
        cout<<"1.show_all_commodities 2.search_commodity 3.off_shelf_commodity 4.show_all_orders 5.show_all_users 6.block_user 7.logout"<<endl;
        cout<<"========================================================================================================================"<<endl;
        cout<<endl;
        cout<<"Please input a command:";
        cin>>command;
    }
}

void Admin::search_commodity() {

}

void Admin::off_shelf_commodity() {

}

void Admin::show_all_orders() {

}

void Admin::show_all_users() {

}

void Admin::block_user() {

}

void Admin::admin_login() {
    string name, password;
    cout<<"Please input administrator name:";
    cin>>name;
    cout<<"Please input password:";
    cin>>password;
    if(name == admin_name && password == admin_password){
        cout<<"-----Login successfully!-----"<<endl;
        cout<<endl;
        admin_menu();
    }
    else{
        cout<<"-----Wrong password...Login unsuccessfully...Return to main menu!-----"<<endl;
    }
}

