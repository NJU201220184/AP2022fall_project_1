//
// Created by 28495 on 2022/9/10.
//

#include "Admin.h"
#include "File.h"
#include <iomanip>


void Admin::admin_menu() {
    cout<<"========================================================================================================================"<<endl;
    cout<<"1.show_all_commodities 2.search_commodity 3.off_shelf_commodity 4.show_all_orders 5.show_all_users 6.block_user 7.logout"<<endl;
    cout<<"========================================================================================================================"<<endl;
    cout<<endl;
    cout<<"Please input a command:";
    string command;
    cin>>command;
    while(command != "7"){
        if(command == "1") show_all_commodities(cd_list);
        else if(command == "2") search_commodity(cd_list);
        else if(command == "3") off_shelf_commodity(cd_list);
        else if(command == "4") show_all_orders(order_list);
        else if(command == "5") show_all_users(user_list);
        else if(command == "6") cout<<"block_user"<<endl<<endl;
        else cout<<"Unknown command, please try again..."<<endl<<endl;
        cout<<"========================================================================================================================"<<endl;
        cout<<"1.show_all_commodities 2.search_commodity 3.off_shelf_commodity 4.show_all_orders 5.show_all_users 6.block_user 7.logout"<<endl;
        cout<<"========================================================================================================================"<<endl;
        cout<<endl;
        cout<<"Please input a command:";
        cin>>command;
    }
    cout<<endl<<"Administrator log out"<<endl<<endl;
}

void Admin::show_all_commodities(commodity_node* cd_list) {
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
        iter->cd.print_info();
        iter = iter->next;
    }
    cout<<endl;
}

void Admin::search_commodity(commodity_node* cd_list) {
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
            iter->cd.print_info();
            is_found = true;
        }
        iter = iter->next;
    }
    if(!is_found) cout<<"not found..."<<endl;
    cout<<endl;
}

void Admin::off_shelf_commodity(commodity_node* cd_list) {
    cout<<endl;
    commodity_node* iter = cd_list;
    cout<<"Please input the name of the commodity: ";
    string name;
    cin>>name;
    cout<<"Please input the id of the commodity's seller: ";
    string sellerID;
    cin>>sellerID;
    bool is_found = false;
    int count = 0;
    while(iter != nullptr){
        if(iter->cd.name() == name && iter->cd._sellerID() == sellerID && iter->cd._state() == "onAuction") {
            cout<<"Found the commodity!"<<endl;
            iter->cd.print_info();
            is_found = true;
            break;
        }
        iter = iter->next;
    }
    if(!is_found) cout<<"not found this commodity or not commodity not on auction..."<<endl;
    else{
        cout<<"Are you sure that you want to ban this commodity?(Yes/No)"<<endl;
        string option;
        cin>>option;
        if(option == "Yes") {
            iter->cd.change_state();
            write_cd_data(cd_list, commodity_file_name);
            cout<<"Commodity banned successfully!"<<endl;
            read_commodity_data(commodity_file_name);
        }
        else cout<<"Commodity remains."<<endl;
    }
    cout<<endl;
}

void Admin::show_all_orders(order_node* order_list) {
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
        iter->order.print_info();
        iter = iter->next;
    }
    cout<<endl;
}

void Admin::show_all_users(user_node* user_list) {
    cout<<endl;
    user_node* iter = user_list;
    cout<<setiosflags(ios::left)<<setw(8)<<"userID"
        <<setiosflags(ios::left)<<setw(12)<<"username"
        <<setiosflags(ios::left)<<setw(16)<<"address"
        <<setiosflags(ios::left)<<setw(12)<<"balance"
        <<setiosflags(ios::left)<<setw(8)<<"userState"<<endl;
    while(iter != nullptr){
        iter->user.print_info();
        iter = iter->next;
    }
    cout<<endl;
}

void Admin::block_user(user_node* user_list) {
    cout<<endl;
    user_node* iter = user_list;
    cout<<"Please input the name of the commodity: ";
    string name;
    cin>>name;
    cout<<"Please input the id of the commodity's seller: ";
    string sellerID;
    cin>>sellerID;
    bool is_found = false;
    int count = 0;
    while(iter != nullptr){
        if(iter->user._username() == name && iter->user._userState() == "active") {
            cout<<"Found the user!"<<endl;
            iter->user.print_info();
            is_found = true;
            break;
        }
        iter = iter->next;
    }
    if(!is_found) cout<<"not found this commodity or not commodity not on auction..."<<endl;
    else{
        cout<<"Are you sure that you want to ban this commodity?(Yes/No)"<<endl;
        string option;
        cin>>option;
        if(option == "Yes") {
            iter->user.change_state();
            write_cd_data(cd_list, commodity_file_name);
            cout<<"User deleted successfully!"<<endl;
            read_user_data(user_file_name);
        }
        else cout<<"User remains."<<endl;
    }
    cout<<endl;
}

void Admin::admin_login() {
    string name, password;
    cout<<"Please input administrator name:";
    cin>>name;
    cout<<"Please input password:";
    cin>>password;
    cout<<endl;
    if(name == admin_name && password == admin_password){
        cout<<"-----Login successfully!-----"<<endl;
        cout<<endl;
        admin_menu();
    }
    else{
        cout<<"-----Wrong password...Login unsuccessfully...Return to main menu!-----"<<endl;
    }
}

