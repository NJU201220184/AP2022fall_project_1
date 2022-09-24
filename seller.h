//
// Created by 28495 on 2022/9/19.
//

#ifndef AP_PROJECT_1_SELLER_H
#define AP_PROJECT_1_SELLER_H

#endif //AP_PROJECT_1_SELLER_H

#include "User.h"
#include "Commodity.h"
#include "Order.h"

void List_item(commodity_node* cd_node){
    cout<<"Please input the name of the item: ";
    string name;
    cin>>name;
    cout<<"Please input the price of the item: ";
    float price;
    cin>>price;
    cout<<"Please input the number of the item: ";
    int number;
    cin>>number;
    cout<<"Please input the description of the item: ";
    string description;
    cin>>description;
    commodity_node* temp = new commodity_node;
    int id = rand() % 100 + 1;
    temp->cd = Commodity();
    temp->next = nullptr;
    commodity_node* iter = cd_node;
    if(iter == nullptr) cd_node = temp;
    else{
        while(iter != nullptr){
            iter = iter->next;
        }
        iter = temp;
    }
    /*rewrite the file*/
}