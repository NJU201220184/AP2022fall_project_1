//
// Created by 28495 on 2022/9/17.
//

#ifndef AP_PROJECT_1_ORDER_H
#define AP_PROJECT_1_ORDER_H

#include <iostream>
using namespace std;

class Order {
    string orderID,commodityID,date,sellerID,buyerID;
    float unitPrice;
    int number;
public:
    Order(char* _orderID, char* _commodityID, char* _unitPrice,
          char* _number,char* _date, char* _sellerID, char* _buyerID);
    Order();
    void print_info();
    string _orderID();
    string _commodityID();
    string _date();
    string _sellerID();
    string _buyerID();
    float _unitPrice();
    int _number();
};

#endif //AP_PROJECT_1_ORDER_H
