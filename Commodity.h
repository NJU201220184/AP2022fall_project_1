//
// Created by 28495 on 2022/9/11.
//
#include<iostream>
using namespace std;

#ifndef AP_PROJECT_1_COMMODITY_H
#define AP_PROJECT_1_COMMODITY_H


class Commodity {
private:
    string commodityID;
    string commodityName;
    float price;
    int number;
    string description;
    string sellerID;
    string addedDate;
    string state;
public:
    Commodity(string _commodityID, string _commodityName, float _price, int _number, string _sellerID, string _addedDate, string _state);
};


#endif //AP_PROJECT_1_COMMODITY_H
