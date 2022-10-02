//
// Created by 28495 on 2022/9/9.
//

#include "File.h"
#include <iomanip>
#include <time.h>

extern string user_file_name;
extern string commodity_file_name;
extern string order_file_name;

extern user_node* user_list;
extern commodity_node* cd_list;
extern order_node* order_list;

extern int user_count;
extern int cd_count;
extern int order_count;

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
    cout<<endl;
    cout<<"This is your personal center, please input the operation you want:"<<endl;
    cout<<"============================================================================================="<<endl;
    cout<<"1.Change password 2.Change phoneNumber 3.Change address 4.Recharge 5.Return to user main menu"<<endl;
    cout<<"============================================================================================="<<endl;
    cout<<endl;
    cout<<"Please input a command:";
    string command;
    cin>>command;
    while(command != "5"){
        if(command == "1") {
            string new_password;
            cout<<"Please input new pass_word:";
            cin>>new_password;
            cout<<"Please input new pass_word again:";
            string verification;
            cin>>verification;
            while(verification != new_password){
                cout<<"two passwords are not the same, please try again";
                cin>>verification;
            }
            password = verification;
            cout<<"Password changed successfully!"<<endl;
            write_user_data(user_list, user_file_name);
        }
        else if(command == "2") {
            cout<<"Please imput your new phoneNumber:";
            string new_phoneNumber;
            cin>>new_phoneNumber;
            phoneNumber = new_phoneNumber;
            cout<<"phoneNumber changed successfully!"<<endl;
            write_user_data(user_list, user_file_name);
        }
        else if(command == "3") {
            cout<<"Please imput your new address:";
            string new_address;
            cin.ignore();
            getline(cin, new_address); //输入�??�??能含有空�??
            address = new_address;
            cout<<"Address changed successfully!"<<endl;
            write_user_data(user_list, user_file_name);
        }
        else if(command == "4") {
            cout<<"Please input the money you wanna recharge:";
            float money;
            cin>>money;
            balance += money;
            cout<<"Current balance:"<<balance<<endl;
            write_user_data(user_list, user_file_name);
        }
        else cout<<"Unknown command, please try again..."<<endl<<endl;
        cout<<"Please input the operation you want:"<<endl;
        cout<<"============================================================================================="<<endl;
        cout<<"1.Change password 2.Change phoneNumber 3.Change address 4.Recharge 5.Return to user main menu"<<endl;
        cout<<"============================================================================================="<<endl;
        cout<<endl;
        cout<<"Please input a command:";
        cin>>command;
    }
    cout<<endl;
    cout<<"Return to User Main Menu..."<<endl<<endl;
}

void User::select_function() {
    cout<<endl;
    cout<<"======================================================="<<endl;
    cout<<"1.Buyer Login 2.Seller Login 3.Personal Center 4.Log out"<<endl;
    cout<<"======================================================="<<endl;
    cout<<endl;
    cout<<"Please input a command:";
    string command;
    cin>>command;
    while(command != "4"){
        if(command == "1") buyer_function();
        else if(command == "2") seller_function();
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
        cout<<"=========================================================================================================="<<endl;
        cout<<"1.List Commodity 2.Off-shelf Commodity 3.Change Commodity Info 4.Show Commodity 5.Check Orders 6.User Menu"<<endl;
        cout<<"=========================================================================================================="<<endl;
    cout<<endl;
    cout<<"Please input a command:";
    string command;
    cin>>command;
    while(command != "6"){
        if(command == "1") seller_add_commodity();
        else if(command == "2") off_shelf_commodity();
        else if(command == "3") change_cd_info();
        else if(command == "4") seller_show_commodities();
        else if(command == "5") seller_show_orders();
        else cout<<"Unknown command, please try again..."<<endl<<endl;
        cout<<"=========================================================================================================="<<endl;
        cout<<"1.List Commodity 2.Off-shelf Commodity 3.Change Commodity Info 4.Show Commodity 5.Check Orders 6.User Menu"<<endl;
        cout<<"=========================================================================================================="<<endl;
        cout<<endl;
        cout<<"Please input a command:";
        cin>>command;
    }
    cout<<"Back to User Main Menu"<<endl<<endl;
}

void User::buyer_function() {
    cout<<"================================================================================================="<<endl;
    cout<<"1.Show Commodity 2.Search Commodity 3.Buy Commodity(Auction) 4.Show Orders 5.User Menu"<<endl;
    cout<<"================================================================================================="<<endl;
    cout<<endl;
    cout<<"Please input a command:";
    string command;
    cin>>command;
    while(command != "5"){
        if(command == "1") buyer_show_all_commodities();
        else if(command == "2") search_commodity();
        else if(command == "3") buyer_auction();
        else if(command == "4") buyer_show_orders();
        else cout<<"Unknown command, please try again..."<<endl<<endl;
        cout<<"================================================================================================="<<endl;
        cout<<"1.Show Commodity 2.Search Commodity 3.Buy Commodity(Auction) 4.Show Orders 5.User Menu"<<endl;
        cout<<"================================================================================================="<<endl;
        cout<<endl;
        cout<<"Please input a command:";
        cin>>command;
    }
    cout<<"Back to User Main Menu"<<endl<<endl;
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

void User::buyer_show_all_commodities() {
    cout<<endl;
    commodity_node* iter = cd_list;
    cout<<setiosflags(ios::left)<<setw(8)<<"cdID"
        <<setiosflags(ios::left)<<setw(15)<<"cdName"
        <<setiosflags(ios::left)<<setw(8)<<"price"
        <<setiosflags(ios::left)<<setw(8)<<"number"
        <<setiosflags(ios::left)<<setw(16)<<"description"
        <<setiosflags(ios::left)<<setw(12)<<"sellerID"
        <<setiosflags(ios::left)<<setw(16)<<"addedDate"
        <<setiosflags(ios::left)<<setw(15)<<"state"<<endl;
    while(iter != nullptr){
        //显示仍然在架上的商品
        if(iter->cd._state() == "onAuction")
            iter->cd.print_info();
        iter = iter->next;
    }
    cout<<endl;
}

void User::seller_show_commodities() {
    cout<<endl;
    commodity_node* iter = cd_list;
    cout<<setiosflags(ios::left)<<setw(8)<<"cdID"
        <<setiosflags(ios::left)<<setw(15)<<"cdName"
        <<setiosflags(ios::left)<<setw(8)<<"price"
        <<setiosflags(ios::left)<<setw(8)<<"number"
        <<setiosflags(ios::left)<<setw(16)<<"description"
        <<setiosflags(ios::left)<<setw(12)<<"sellerID"
        <<setiosflags(ios::left)<<setw(16)<<"addedDate"
        <<setiosflags(ios::left)<<setw(15)<<"state"<<endl;
    while(iter != nullptr){
        //显示�??己发布的商品
        if(iter->cd._sellerID() == userID)
            iter->cd.print_info();
        iter = iter->next;
    }
    cout<<endl;
}

void User::buyer_show_orders() {
    cout<<endl;
    order_node* iter = order_list;
    cout<<setiosflags(ios::left)<<setw(8)<<"orderID"
        <<setiosflags(ios::left)<<setw(12)<<"commodityID"
        <<setiosflags(ios::left)<<setw(12)<<"unitPrice"
        <<setiosflags(ios::left)<<setw(8)<<"number"
        <<setiosflags(ios::left)<<setw(12)<<"date"
        <<setiosflags(ios::left)<<setw(10)<<"sellerID"
        <<setiosflags(ios::left)<<setw(8)<<"buyerID"<<endl;
    while(iter != nullptr){
        if(iter->order._buyerID() == userID)
            iter->order.print_info();
        iter = iter->next;
    }
    cout<<endl;
}

void User::seller_show_orders() {
    cout<<endl;
    order_node* iter = order_list;
    cout<<setiosflags(ios::left)<<setw(8)<<"orderID"
        <<setiosflags(ios::left)<<setw(12)<<"commodityID"
        <<setiosflags(ios::left)<<setw(12)<<"unitPrice"
        <<setiosflags(ios::left)<<setw(8)<<"number"
        <<setiosflags(ios::left)<<setw(12)<<"date"
        <<setiosflags(ios::left)<<setw(10)<<"sellerID"
        <<setiosflags(ios::left)<<setw(8)<<"buyerID"<<endl;
    while(iter != nullptr){
        if(iter->order._sellerID() == userID)
            iter->order.print_info();
        iter = iter->next;
    }
    cout<<endl;
}

void User::search_commodity() {
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
                cout<<setiosflags(ios::left)<<setw(8)<<"cdID"
                <<setiosflags(ios::left)<<setw(15)<<"cdName"
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

void User::seller_add_commodity() {
    auto* temp = new commodity_node;
    temp->next = nullptr;
    string cdname;
    cout<<endl;
    cout<<"Please input commodity's name:";
    cin>>cdname;
    string price;
    cout<<"Please input commodity's price:";
    cin>>price;
    cout<<"Please input commodity's number:";
    string num;
    cin>>num;
    cin.ignore();
    cout<<"Please input commodity's description:";
    string description;
    getline(cin, description);
    cd_count++;
    int id = 1000 + cd_count;
    string Cid = to_string(id);
    Cid[0] = 'C';
    string state = "onAuction";
    time_t t = time(NULL);
    struct tm *local, *gm;
	local = localtime(&t); //获取当前系统时间
    int year = local->tm_year + 1900;
    int month = local->tm_mon + 1;
    int day = local->tm_mday;
    string addedDate = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    temp->cd = Commodity((char*)Cid.c_str(), (char*)cdname.c_str(), 
    (char*)price.c_str(), (char*)num.c_str(), (char*)description.c_str(),
    (char*)userID.c_str(), (char*)addedDate.c_str(), (char*)state.c_str());
    temp->next = nullptr;
    auto cd_tail = cd_list;
    if(cd_list == nullptr) cd_list = cd_tail = temp;
    else{
        while(cd_tail->next) cd_tail = cd_tail->next;
        cd_tail->next = temp;
        cd_tail = cd_tail->next;
    }
    write_cd_data(cd_list, commodity_file_name);
}

void User::buyer_auction() {
    cout<<endl;
    cout<<"Please enter the name of the commodity you wish to buy:"<<endl;
    string name;
    cin>>name;
    auto it = cd_list;
    bool is_found = false;
    while(it != nullptr){
        if(it->cd.name() == name) {
            it->cd.print_info();
            is_found = true;
        }
        it = it->next;
    }
    if(!is_found){
        cout<<"No such Commodity!"<<endl;
        return;
    }
    cout<<endl;
    cout<<"Please enter id of the commodity you wish to buy:"<<endl;
    string Cid;
    cin>>Cid;
    auto iter = cd_list;
    while(iter != nullptr){
        if(iter->cd._commodityID() == Cid){
            cout<<"Please enter the amount of the commodity you wish to buy:"<<endl;
            int num;
            cin>>num;
            if(num > iter->cd._number() || balance < iter->cd._number() * iter->cd._price()){
                cout<<"Not enough amount/money to buy, please buy less or ..."<<endl;
                return;
            }
            auto temp = new bid_node;
            cout<<"Please enter your bid:";
            float bid;
            cin>>bid;
            while(balance < bid * num){
                cout<<"Not enough money to buy, please bid with a lower price..."<<endl;
                cout<<"Please enter your bid:";
                cin>>bid;
            }
            iter->cd.add_bid(userID, bid, num);
        }
        iter = iter->next;
    }
}

void User::off_shelf_commodity(){
    cout<<endl;
    commodity_node* iter = cd_list;
    cout<<"Please input the id of the commodity you'd like to off-shelf: ";
    string cID;
    cin>>cID;
    bool is_found = false;
    int count = 0;
    while(iter != nullptr){
        if(iter->cd._commodityID() == cID && iter->cd._state() == "onAuction" && iter->cd._sellerID() == userID) {
            cout<<"Found the commodity!"<<endl;
            iter->cd.print_info();
            is_found = true;
            break;
        }
        iter = iter->next;
    }
    if(!is_found) cout<<"This commodity does not exist or is not on auction..."<<endl;
    else{
        cout<<"Are you sure that you want to off-shelf this commodity?(Yes/No)"<<endl;
        string option;
        cin>>option;
        if(option == "Yes") {
            iter->cd.change_state();
            write_cd_data(cd_list, commodity_file_name);
            cout<<"Commodity banned successfully!"<<endl;
        }
        else cout<<"Commodity remains."<<endl;
    }
    cout<<endl;
}

void User::change_cd_info(){
    cout<<endl;
    commodity_node* iter = cd_list;
    cout<<"Please input the id of the commodity you'd like to change information: ";
    string cID;
    cin>>cID;
    bool is_found = false;
    int count = 0;
    while(iter != nullptr){
        if(iter->cd._commodityID() == cID && iter->cd._state() == "onAuction" && iter->cd._sellerID() == userID) {
            cout<<"Found the commodity!"<<endl;
            iter->cd.print_info();
            is_found = true;
            break;
        }
        iter = iter->next;
    }
    if(!is_found) cout<<"This commodity does not exist or is not on auction..."<<endl;
    else{
        cout<<"Please input the attribute you'd like to change: 1.price 2.description 3.cancel"<<endl;
        string option;
        cin>>option;
        if(option == "price"){
            cout<<"Please input a new price:";
            float newPrice;
            cin>>newPrice;
            iter->cd.change_price(newPrice);
        }

        else if(option == "description"){
            cout<<"Please input a new description:";
            string new_description;
            cin.ignore();
            getline(cin, new_description);
            iter->cd.change_description(new_description);
        }

        else if(option == "cancel") return;

        else cout<<"Unknown command..."<<endl;

        write_cd_data(cd_list, commodity_file_name);
    }
    cout<<endl;
}

void User::buy(float money){
    balance -= money;
}

void User::sell(float money){
    balance += money;
}