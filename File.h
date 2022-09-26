//
// Created by 28495 on 2022/9/24.
//

#ifndef AP_PROJECT_1_FILE_H
#define AP_PROJECT_1_FILE_H

#include "Node_list.h"

#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;

user_node* read_user_data(string file_name);
commodity_node* read_commodity_data(const string& file_name);
order_node* read_order_data(const string& order_file_name);

void write_user_data(user_node* user_list, string file_name);
void write_cd_data(commodity_node* cd_list, string file_name);
void write_order_data(order_node* order_list, string file_name);



#endif //AP_PROJECT_1_FILE_H



