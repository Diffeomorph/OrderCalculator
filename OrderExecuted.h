#pragma once

#include "Order.h"

/*
* Class for the Order Executed message type in Pitch. executed_shares corresponds
* to the amount of shares which have been executed.
*/


class OrderExecuted : public Order {
public:
    OrderExecuted(const string& line);

    const int GetExecutedShares() { return executed_shares; }
private:
    const int executed_shares;
    const string execution_id;

};

