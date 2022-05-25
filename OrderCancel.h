#pragma once

#include "Order.h"

/*
* Class for the Order Cancel order type in Pitch. canceled_shares corresponds
* to the amount of shares to be cancelled.
*/

class OrderCancel : public Order {
public:
    OrderCancel(const string& line);

    const int GetCanceledShares() { return canceled_shares; }
private:
    const int canceled_shares;

};