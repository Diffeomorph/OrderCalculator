#pragma once

#include "Order.h"

class OrderShort : public Order {
public:
    OrderShort(const string& line);

    bool MinusShares(int shares);
    const int NumberOfShares() { return number_of_shares; }
    const string& GetStockSymbol() { return stock_symbol; }
private:
    const char side_indicator;
    int number_of_shares;
    const string stock_symbol;
    const string price;
    const char display;
};
