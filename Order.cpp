#include "Order.h"

Order::Order(const string& line) :
    time_stamp(line.substr(1, 8)),
    message_type(line.at(9)),
    order_id(line.substr(10, 12))
{}