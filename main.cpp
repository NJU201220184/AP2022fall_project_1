#include "menu.h"
#include "User.h"
#include <fstream>
#include <sstream>
#include <cstring>

struct user_node{
    User user;
    user_node* next;
};

int main() {
    //main_menu();
    ifstream in;
    string file_name = "D:\\AP_project_1\\user.txt";
    in.open(file_name.data());

    auto* user_list_head = new user_node;
    user_list_head = nullptr;
    auto* user_list_tail = user_list_head;
    int line_count = 0;

    string line;
    while(getline(in, line))
    {
        line_count++;
        if(line_count > 1){
            char config[7][25];

            istringstream str(line);
            string out;

            int index = 0;
            while(getline(str, out, ',')){
                char feature[25];
                strcpy(feature, out.c_str());
                strcpy(config[index] , feature);
                index++;
            }

            auto* user_list_temp = new user_node;
            user_list_temp->user.sign_in(config[0], config[1], config[2], config[3], config[4], config[5], config[6]);
            if(user_list_head == nullptr) user_list_head = user_list_tail = user_list_temp;
            else{
                user_list_tail->next = user_list_temp;
                user_list_tail = user_list_tail->next;
            }
        }
    }
    user_list_head->user.print_info();
    return 0;
}




