//
// Created by 28495 on 2022/9/11.
//

#include <iomanip>
#include "Commodity.h"

Commodity::Commodity() {

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
}

void Commodity::print_info() {
    cout<<setiosflags(ios::left)<<setw(12)<<commodityID
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

string Commodity::_state() {
    return std::string(state);
}

void Commodity::change_state() {
    state = "out_of_Auction";
}

string Commodity::_sellerID() {
    return std::string(sellerID);
}




