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
    Commodity();
    Commodity(char* _commodityID, char* _commodityName, char* _price, char* _number,
              char* _description, char* _sellerID, char* _addedDate, char* _state);
    void print_info();
    string name();
    string _state();
    string _sellerID();
    void change_state();
    string
};

struct commodity_node{
    Commodity cd;
    commodity_node* next;
};


#endif //AP_PROJECT_1_COMMODITY_H
