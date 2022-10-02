//
// Created by 28495 on 2022/9/17.
//

#include "Order.h"
#include <iomanip>

Order::Order(char* _orderID, char* _commodityID, char* _unitPrice, char* _number, char* _date, char* _sellerID,char* _buyerID)
{
    orderID = _orderID;
    commodityID = _commodityID;
    unitPrice = atof(_unitPrice);
    number = atoi(_number);
    date = _date;
    sellerID = _sellerID;
    buyerID = _buyerID;
}

Order::Order() {

}

void Order::print_info() {
    cout<<setiosflags(ios::left)<<setw(8)<<orderID
        <<setiosflags(ios::left)<<setw(12)<<commodityID
        <<setiosflags(ios::left)<<setw(12)<<unitPrice
        <<setiosflags(ios::left)<<setw(8)<<number
        <<setiosflags(ios::left)<<setw(12)<<date
        <<setiosflags(ios::left)<<setw(10)<<sellerID
        <<setiosflags(ios::left)<<setw(8)<<buyerID<<endl;
}

string Order::_orderID(){
    return orderID;
}

string Order::_commodityID(){
    return commodityID;
}

string Order::_date(){
    return date;
}

string Order::_sellerID(){
    return sellerID;
}

string Order::_buyerID(){
    return buyerID;
}

float Order::_unitPrice(){
    return unitPrice;
}

int Order::_number(){
    return number;
}
