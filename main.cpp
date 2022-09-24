#include "menu.h"
#include "File.h"

const string user_file_name = "D:\\AP_project_1\\user.txt";
const string commodity_file_name = "D:\\AP_project_1\\commodity.txt";
const string order_file_name = "D:\\AP_project_1\\order.txt";

user_node* user_list = read_user_data(user_file_name);
commodity_node* cd_list = read_commodity_data(commodity_file_name);
order_node* order_list = read_order_data(order_file_name);

int main() {
    main_menu();
    return 0;
}




