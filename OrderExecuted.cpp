#include "OrderExecuted.h"

OrderExecuted::OrderExecuted(const string& line) :
    Order(line),
    executed_shares(stoi(line.substr(22, 6))),
    execution_id(line.substr(28, 12))
{}
