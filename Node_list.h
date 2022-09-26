//
// Created by 28495 on 2022/9/26.
//

#ifndef AP_PROJECT_1_NODE_LIST_H
#define AP_PROJECT_1_NODE_LIST_H

#include "User.h"
#include "Commodity.h"
#include "Order.h"

struct commodity_node{
    Commodity cd;
    commodity_node* next;
};

struct user_node{
    User user;
    user_node* next;
};

struct order_node{
    Order order;
    order_node* next;
};

#endif //AP_PROJECT_1_NODE_LIST_H
