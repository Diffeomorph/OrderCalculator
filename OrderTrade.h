#pragma once

#include "Order.h"

class OrderTrade : public Order {
public:
    OrderTrade(const string& line);

    bool MinusShares(int shares);
    const string& GetStockSymbol() { return stock_symbol; }
    const int GetNumberOfShares() { return number_of_shares; }
private:
    const char side_indicator;
    int number_of_shares;
    const string stock_symbol;
    const string price;
    const string execution_id;
};