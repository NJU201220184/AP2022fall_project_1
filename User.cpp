//
// Created by 28495 on 2022/9/9.
//

#include "User.h"
#include "seller.h"
#include <iomanip>

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
    cout<<setiosflags(ios::left)<<setw(8)<<userID
        <<setiosflags(ios::left)<<setw(12)<<username
        <<setiosflags(ios::left)<<setw(16)<<address
        <<setiosflags(ios::left)<<setw(12)<<setiosflags(ios::fixed)<<setprecision(1)<<balance
        <<setiosflags(ios::left)<<setw(8)<<userState<<endl;
}

void User::seller_function() {

}

void User::buyer_function() {

}

string User::_username() {
    return username;
}

string User::_password() {
    return password;
}

string User::_userID() {
    return userID;
}

string User::_phoneNumber() {
    return phoneNumber;
}

string User::_address() {
    return address;
}

float User::_balance() {
    return balance;
}

string User::_userState() {
    return userState;
}

void User::change_state() {
    userState = "blocked";
}

void User::buyer_show_all_commodities(commodity_node *cd_list) {
    cout<<endl;
    commodity_node* iter = cd_list;
    cout<<setiosflags(ios::left)<<setw(12)<<"commodityID"
        <<setiosflags(ios::left)<<setw(15)<<"commodityName"
        <<setiosflags(ios::left)<<setw(8)<<"price"
        <<setiosflags(ios::left)<<setw(8)<<"number"
        <<setiosflags(ios::left)<<setw(16)<<"description"
        <<setiosflags(ios::left)<<setw(12)<<"sellerID"
        <<setiosflags(ios::left)<<setw(16)<<"addedDate"
        <<setiosflags(ios::left)<<setw(15)<<"state"<<endl;
    while(iter != nullptr){
        if(iter->cd._state() == "onAuction")
            iter->cd.print_info();
        iter = iter->next;
    }
    cout<<endl;
}

void User::seller_show_all_commodities(commodity_node *cd_list) {
    cout<<endl;
    commodity_node* iter = cd_list;
    cout<<setiosflags(ios::left)<<setw(12)<<"commodityID"
        <<setiosflags(ios::left)<<setw(15)<<"commodityName"
        <<setiosflags(ios::left)<<setw(8)<<"price"
        <<setiosflags(ios::left)<<setw(8)<<"number"
        <<setiosflags(ios::left)<<setw(16)<<"description"
        <<setiosflags(ios::left)<<setw(12)<<"sellerID"
        <<setiosflags(ios::left)<<setw(16)<<"addedDate"
        <<setiosflags(ios::left)<<setw(15)<<"state"<<endl;
    while(iter != nullptr){
        //显示自己发布的商品
        if(iter->cd._sellerID() == userID)
            iter->cd.print_info();
        iter = iter->next;
    }
    cout<<endl;
}

void User::buyer_show_orders(order_node *order_list) {
    cout<<endl;
    order_node* iter = order_list;
    cout<<setiosflags(ios::left)<<setw(8)<<"orderID"
        <<setiosflags(ios::left)<<setw(12)<<"commodityID"
        <<setiosflags(ios::left)<<setw(12)<<"unitPrice"
        <<setiosflags(ios::left)<<setw(8)<<"number"
        <<setiosflags(ios::left)<<setw(12)<<"date"
        <<setiosflags(ios::left)<<setw(8)<<"sellerID"
        <<setiosflags(ios::left)<<setw(8)<<"buyerID"<<endl;
    while(iter != nullptr){
        if(iter->order._buyerID() == userID)
            iter->order.print_info();
        iter = iter->next;
    }
    cout<<endl;
}

void User::seller_show_orders(order_node *order_list) {
    cout<<endl;
    order_node* iter = order_list;
    cout<<setiosflags(ios::left)<<setw(8)<<"orderID"
        <<setiosflags(ios::left)<<setw(12)<<"commodityID"
        <<setiosflags(ios::left)<<setw(12)<<"unitPrice"
        <<setiosflags(ios::left)<<setw(8)<<"number"
        <<setiosflags(ios::left)<<setw(12)<<"date"
        <<setiosflags(ios::left)<<setw(8)<<"sellerID"
        <<setiosflags(ios::left)<<setw(8)<<"buyerID"<<endl;
    while(iter != nullptr){
        if(iter->order._sellerID() == userID)
            iter->order.print_info();
        iter = iter->next;
    }
    cout<<endl;
}

void User::search_commodity(commodity_node *cd_list) {
    cout<<endl;
    commodity_node* iter = cd_list;
    cout<<"Please input the name of the commodity: ";
    string name;
    cin>>name;
    bool is_found = false;
    int count = 0;
    while(iter != nullptr){
        if(iter->cd.name() == name) {
            count++;
            if(count == 1)
            {
                cout<<setiosflags(ios::left)<<setw(12)<<"commodityID"
                    <<setiosflags(ios::left)<<setw(15)<<"commodityName"
                    <<setiosflags(ios::left)<<setw(8)<<"price"
                    <<setiosflags(ios::left)<<setw(8)<<"number"
                    <<setiosflags(ios::left)<<setw(16)<<"description"
                    <<setiosflags(ios::left)<<setw(12)<<"sellerID"
                    <<setiosflags(ios::left)<<setw(16)<<"addedDate"
                    <<setiosflags(ios::left)<<setw(15)<<"state"<<endl;
            }
            if(iter->cd._state() == "onAuction")
            {
                iter->cd.print_info();
            }
            is_found = true;
        }
        iter = iter->next;
    }
    if(!is_found) cout<<"not found..."<<endl;
    cout<<endl;
}

void User::seller_add_commodity(commodity_node *cd_list) {

}

void User::buyer_auction() {

}




