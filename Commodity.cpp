//
// Created by 28495 on 2022/9/11.
//

#include "File.h"
#include <iomanip>
#include <time.h>

extern string user_file_name;
extern string commodity_file_name;
extern string order_file_name;

extern user_node* user_list;
extern commodity_node* cd_list;
extern order_node* order_list;

extern int user_count;
extern int cd_count;
extern int order_count;


Commodity::Commodity() {
}

Commodity::Commodity(char* _commodityID, char* _commodityName, char* _price, char* _number, char* _description, char* _sellerID, char* _addedDate, char* _state){
    commodityID = _commodityID;
    commodityName = _commodityName;
    price = atof(_price);
    number = atoi(_number);
    description = _description;
    sellerID = _sellerID;
    addedDate = _addedDate;
    state = _state;
    create_time = clock();
}

void Commodity::print_info() {
    cout<<setiosflags(ios::left)<<setw(8)<<commodityID
    <<setiosflags(ios::left)<<setw(15)<<commodityName
    <<setiosflags(ios::left)<<setw(8)<<price
    <<setiosflags(ios::left)<<setw(8)<<number
    <<setiosflags(ios::left)<<setw(16)<<description
    <<setiosflags(ios::left)<<setw(12)<<sellerID
    <<setiosflags(ios::left)<<setw(16)<<addedDate
    <<setiosflags(ios::left)<<setw(15)<<state<<endl;
}

string Commodity::name() {
    return std::string(commodityName);
}

void Commodity::change_state() {
    state = "out_of_Auction";
}

void Commodity::change_price(float _price){
    price = _price;
}

void Commodity::change_description(string _description){
    description = _description;
}

string Commodity::_sellerID() {
    return std::string(sellerID);
}

string Commodity::_commodityID() {
    return std::string(commodityID);
}

float Commodity::_price() {
    return price;
}

int Commodity::_number() {
    return number;
}

string Commodity::_description() {
    return std::string(description);
}

string Commodity::_addedDate() {
    return std::string(addedDate);
}

string Commodity::_state() {
    return std::string(state);
}

void Commodity::add_bid(string buyerID, float bid, int number) {
    bid_node* temp = new bid_node;
    temp->buyerID = buyerID;
    temp->bid = bid;
    temp->number = number;
    temp->next = nullptr;
    if(bid_list == nullptr) bid_list = temp;
    else{
        while(bid_list->next != nullptr){
            bid_list = bid_list->next;
        }
        bid_list->next = temp;
    }
}

void Commodity::show_bid(){
    auto iter = bid_list;
    cout<<"Commodity name:"<<commodityName<<endl;
    while(iter != nullptr){
        cout<<"buyerID:"<<iter->buyerID<<" number:"<<iter->number<<" bid:"<<iter->bid<<endl;
        iter = iter->next;
    }
    cout<<"This is the end of bid list"<<endl;
}

int Commodity::_create_time(){
    return (int)create_time;
}

void Commodity::check_bid(){
    //没有则返回
    if(bid_list == nullptr) return;

    //一个则不处理
    
    //多于一个则排序
    if(bid_list != nullptr && bid_list->next != nullptr){
        auto pre = bid_list;
        auto cur = bid_list->next;
        bool flag = 0;
        for(pre; pre->next->next != nullptr; pre = pre->next){
            for(cur; cur->next != nullptr; cur = cur->next){
                if(cur->bid > pre->bid){
                    swap(cur->bid, pre->bid);
                    swap(cur->buyerID, pre->buyerID);
                    swap(cur->number, pre->number);
                }
            }
        }
    }

    //分给出价最高的buyer（们），若其要的数量过多，则无法成功交易
    auto iter3 = bid_list;
    int count;

    //一个报价
    if(bid_list->next == nullptr){
        count += bid_list->number;
    }

    //多个报价
    else{
        while(iter3->bid == bid_list->bid){
            count += iter3->number;
            iter3 = iter3->next;
        }
    }
    
    //商品数量不够
    if(count > number){
        cout<<"Not enough amount..."<<endl;
        return;
    }

    //商品数量足够
    //仅有一个报价
    if(bid_list->next == nullptr){
        //生成order
        auto temp_order = new order_node;
        auto iter4 = bid_list;
        order_count++;
        int id = 1000 + order_count;
        string Oid = to_string(id);
        Oid[0] = 'T';
        time_t t = time(NULL);
        struct tm *local;
        local = localtime(&t); //获取当前系统时间
        int year = local->tm_year + 1900;
        int month = local->tm_mon + 1;
        int day = local->tm_mday;
        string addedDate = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
        string Unitprice = to_string(iter4->bid);
        string amount = to_string(iter4->number);
        temp_order->next = nullptr;
        temp_order->order = Order((char*)Oid.c_str(), (char*)commodityID.c_str(), 
        (char*)Unitprice.c_str(), (char*)amount.c_str(), (char*)addedDate.c_str(),
        (char*)sellerID.c_str(), (char*)iter4->buyerID.c_str());
        temp_order->order.print_info();

        //连接到order_list上
        auto order_iter = order_list;
        if(order_iter == nullptr){
            order_list = temp_order;
        }

        else{
            while(order_iter->next != nullptr){
                order_iter = order_iter->next;
            }
            order_iter->next = temp_order;
        }

        //buyer和seller的处理
        auto user_node = user_list;
        for(user_node; user_node != nullptr; user_node = user_node->next){
            if(user_node->user._userID() == iter4->buyerID){
                //buyer扣钱
                user_node->user.buy(iter4->bid * iter4->number);
            }
            else if(user_node->user._userID() == sellerID){
                //seller挣钱
                user_node->user.sell(iter4->bid * iter4->number);
            }
        }
        
        //Commodity的处理
        number -= count;
        if(number == 0){
            //卖光了，商品下架
            change_state();
        }
    }
    
    //相同的最高出价
    else{
        auto iter4 = bid_list;
        while(iter4->bid == bid_list->bid){
            //生成order
            auto temp_order = new order_node;
            order_count++;
            int id = 1000 + order_count;
            string Oid = to_string(id);
            Oid[0] = 'T';
            time_t t = time(NULL);
            struct tm *local;
            local = localtime(&t); //获取当前系统时间
            int year = local->tm_year + 1900;
            int month = local->tm_mon + 1;
            int day = local->tm_mday;
            string addedDate = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
            string Unitprice = to_string(iter4->bid);
            string number = to_string(iter4->number);
            temp_order->next = nullptr;
            temp_order->order = Order((char*)Oid.c_str(), (char*)commodityID.c_str(), 
            (char*)Unitprice.c_str(), (char*)number.c_str(), (char*)addedDate.c_str(),
            (char*)sellerID.c_str(), (char*)iter4->buyerID.c_str());
            temp_order->order.print_info();

            //连接到order_list上
            auto order_iter = order_list;
            if(order_iter == nullptr){
                order_list = temp_order;
            }
            else{
                while(order_iter->next != nullptr){
                    order_iter = order_iter->next;
                }
                order_iter->next = temp_order;
            }

            //buyer和seller的处理
            auto user_node = user_list;
            for(user_node; user_node != nullptr; user_node = user_node->next){
                if(user_node->user._userID() == iter4->buyerID){
                    //buyer扣钱
                    user_node->user.buy(iter4->bid * iter4->number);
                }
                else if(user_node->user._userID() == sellerID){
                    //seller挣钱
                    user_node->user.sell(iter4->bid * iter4->number);
                }
            }
            iter4 = iter4->next;
        }

        //Commodity的处理
        number -= count;
        if(number == 0){
            //卖光了，商品下架
            change_state();
        }
    }

    //一次拍卖结束后后删掉拍卖链表并重设时间
    bid_list = nullptr;
    create_time = clock();

    //写入文件
    write_user_data(user_list, user_file_name);
    write_cd_data(cd_list, commodity_file_name);
    write_order_data(order_list, order_file_name);
}




