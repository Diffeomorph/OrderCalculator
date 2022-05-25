#pragma once

#include <unordered_map>
#include <memory>

#include "OrderShort.h"

/*
* Order Manager is the class which runs the program. It holds two maps,
* open_orders and executed_orders which hold orders sitting on the book and
* records which orders have been executed.
*/


class OrderManager {
public:
    OrderManager();
private:
    void AddOrderShort(const string& line);
    void AddOrderCancel(const string& line);
    void AddOrderExecuted(const string& line);
    void AddTradeShort(const string& line);

    unordered_map<string, unique_ptr<OrderShort>> open_orders; // Order ID --> Add Order
    unordered_map<string, int> executed_orders; // stock symbol ---> quantity
};
