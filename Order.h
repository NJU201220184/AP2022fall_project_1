//
// Created by 28495 on 2022/9/17.
//
#include <iostream>
using namespace std;
#ifndef AP_PROJECT_1_ORDER_H
#define AP_PROJECT_1_ORDER_H


class Order {
    string orderID,commodityID,unitPrice,number,date,sellerID,buyerID;
public:
    Order(string _orderID, string _commodityID, float _unitPrice,
          int _number,string _date, string _sellerID, string _buyerID);
};


#endif //AP_PROJECT_1_ORDER_H
