#pragma once

#include <string>

using namespace std;

/*
* Basic class from which all order/message types inherit from
*/

class Order {
public:
    Order(const string& line);
    const string& GetOrderID() { return order_id; }
private:
    const string time_stamp;
    const char message_type;
    const string order_id;
}; 


