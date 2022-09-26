//
// Created by 28495 on 2022/9/11.
//

#include <iomanip>
#include "Node_list.h"

Commodity::Commodity() {
    bid_list = nullptr;
}

Commodity::Commodity(char* _commodityID, char* _commodityName, char* _price, char* _number, char* _description, char* _sellerID, char* _addedDate, char* _state){
    commodityID = _commodityID;
    commodityName = _commodityName;
    price = atof(_price);
    number = atoi(_number);
    description = _description;
    sellerID = _sellerID;
    addedDate = _addedDate;
    state = _state;
    bid_list = nullptr;
}

void Commodity::print_info() {
    cout<<setiosflags(ios::left)<<setw(8)<<commodityID
    <<setiosflags(ios::left)<<setw(15)<<commodityName
    <<setiosflags(ios::left)<<setw(8)<<price
    <<setiosflags(ios::left)<<setw(8)<<number
    <<setiosflags(ios::left)<<setw(16)<<description
    <<setiosflags(ios::left)<<setw(12)<<sellerID
    <<setiosflags(ios::left)<<setw(16)<<addedDate
    <<setiosflags(ios::left)<<setw(15)<<state<<endl;
}

string Commodity::name() {
    return std::string(commodityName);
}

void Commodity::change_state() {
    state = "out_of_Auction";
}

string Commodity::_sellerID() {
    return std::string(sellerID);
}

string Commodity::_commodityID() {
    return std::string(commodityID);
}

float Commodity::_price() {
    return price;
}

int Commodity::_number() {
    return number;
}

string Commodity::_description() {
    return std::string(description);
}

string Commodity::_addedDate() {
    return std::string(addedDate);
}

string Commodity::_state() {
    return std::string(state);
}

void Commodity::add_bid(string buyerID, float bid) {
    bid_node* temp = new bid_node;
    temp->sellerID = sellerID;
    temp->bid = bid;
    temp->next = nullptr;
    if(bid_list == nullptr) bid_list = temp;
    else{
        while(bid_list->next != nullptr){
            bid_list = bid_list->next;
        }
        bid_list->next = temp;
    }
}




