//
// Created by 28495 on 2022/9/11.
//

#include <iostream>
#include <time.h>
#include "File.h"
using namespace std;

#ifndef AP_PROJECT_1_COMMODITY_H
#define AP_PROJECT_1_COMMODITY_H

struct bid_node{
    string buyerID;
    int number;
    float bid;
    bid_node* next;
};

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
    bid_node* bid_list = nullptr;
    clock_t create_time;
public:
    Commodity();
    Commodity(char* _commodityID, char* _commodityName, char* _price, char* _number,
              char* _description, char* _sellerID, char* _addedDate, char* _state);
    void print_info();
    string name();
    string _commodityID();
    float _price();
    int _number();
    string _description();
    string _sellerID();
    string _addedDate();
    string _state();
    int _create_time();
    void change_state();
    void change_price(float _price);
    void change_description(string _description);
    void add_bid(string buyerID, float bid, int number);
    void show_bid();
    void check_bid();
};

#endif //AP_PROJECT_1_COMMODITY_H
