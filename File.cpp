//
// Created by 28495 on 2022/9/26.
//

#include "File.h"

//Read Files
user_node* read_user_data(string file_name) {
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
    user_list_head->user.print_info();
    return user_list_head;
}

commodity_node* read_commodity_data(const string& file_name){
    ifstream in;
    in.open(file_name.data());

    int line_count = 0;
    string line;
    auto* cd_list_head = new commodity_node;
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
    while(iter != nullptr){
        iter->cd.print_info();
        iter = iter->next;
    }
    return cd_list_head;
}

order_node* read_order_data(const string& order_file_name){
    ifstream in;
    in.open(order_file_name.data());

    int line_count = 0;
    string line;
    auto* order_list_head = new order_node;
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
    auto* iter = order_list_head;
    while(iter != nullptr){
        iter->order.print_info();
        iter = iter->next;
    }
    return order_list_head;
}

//Write Files
void write_user_data(user_node* user_list, string file_name){
    ofstream destFile(file_name, ios::out);
    //写入文件
    destFile<<"username,"<<"password,"<<"userID,"
            <<"phoneNumber,"<<"address,"<<"balance,"<<"userState"<<'\n';
    auto iter = user_list;
    while(iter){
        destFile<<iter->user._username()<<','<<iter->user._password()<<','
                <<iter->user._userID()<<','<<iter->user._phoneNumber()<<','
                <<iter->user._address()<<','<<iter->user._balance()<<','
                <<iter->user._userState()<<'\n';
        iter = iter->next;
    }
    destFile.close();
}

void write_cd_data(commodity_node* cd_list, string file_name){
    ofstream destFile(file_name, ios::out);
    //写入文件
    destFile<<"commodityID,commodityName,price,number,description,sellerID,addedDate,state"<<'\n';
    auto iter = cd_list;
    while(iter){
        destFile<<iter->cd._commodityID()<<','<<iter->cd.name()<<','
                <<iter->cd._price()<<','<<iter->cd._number()<<','
                <<iter->cd._description()<<','<<iter->cd._sellerID()<<','
                <<iter->cd._addedDate()<<','<<iter->cd._state()<<'\n';
        iter = iter->next;
    }
    destFile.close();
}

void write_order_data(order_node* order_list, string file_name){
    ofstream destFile(file_name, ios::out);
    //写入文件
    destFile<<"orderID,commodityID,unitPrice,number,date,sellerID,buyerID"<<'\n';
    auto iter = order_list;
    while(iter){
        destFile<<iter->order._orderID()<<','<<iter->order._commodityID()<<','
                <<iter->order._unitPrice()<<','<<iter->order._number()<<','
                <<iter->order._date()<<','<<iter->order._sellerID()<<','
                <<iter->order._buyerID()<<'\n';
        iter = iter->next;
    }
    destFile.close();
}