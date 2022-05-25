
#include "OrderShort.h"

OrderShort::OrderShort(const string& line) :
    Order(line),
    side_indicator(line.at(22)),
    number_of_shares(stoi(line.substr(23, 6))),
    stock_symbol(line.substr(29, 6)),
    price(line.substr(35, 10)),
    display(line.at(45))
{}

bool OrderShort::MinusShares(int canceled_shares)
{
    if (canceled_shares > number_of_shares) {
        return 0;
    }
    else {
        number_of_shares -= canceled_shares;
        return 1;
    }
}
