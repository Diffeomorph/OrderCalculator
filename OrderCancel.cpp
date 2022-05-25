#include "OrderCancel.h"

OrderCancel::OrderCancel(const string& line) :
    Order(line),
    canceled_shares(stoi(line.substr(22, 6)))
{}