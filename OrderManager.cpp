
#include "OrderManager.h"
#include "OrderShort.h"
#include "OrderCancel.h"
#include "OrderExecuted.h"
#include "OrderTrade.h"

#include <iostream>
#include <fstream>
#include <algorithm>

// function for comparing the second element of two pairs
bool Comparator(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}

OrderManager::OrderManager() {
    ifstream file("out.txt");
    string str;
    while (getline(file, str))
    {
        char type = str.at(9);
        if (type == 'A') {
            AddOrderShort(str);
        }
        else if (type == 'E') {
            AddOrderExecuted(str);
        }
        else if (type == 'X') {
            AddOrderCancel(str);
        }
        else if (type == 'P') {
            AddTradeShort(str);
        }
        else {
            continue;
        }
    }
    file.close();

    vector<pair<string, int>> elems(executed_orders.begin(), executed_orders.end());
    sort(elems.begin(), elems.end(), Comparator);

    int top = 10;
    int n = elems.size();
    ofstream output("ans.txt");
    for (int i = 0; i < min(n, top); i++) {
        output << elems[i].first << " : " << elems[i].second << endl;
    }
    output.close();

}

void OrderManager::AddOrderShort(const string& line)
{
    auto order_short = std::unique_ptr<OrderShort>(new OrderShort(line));
    open_orders[order_short->GetOrderID()] = std::move(order_short);
}

void OrderManager::AddOrderCancel(const string& line)
{
    OrderCancel order_cancel(line);
    if (open_orders[order_cancel.GetOrderID()]->MinusShares(order_cancel.GetCanceledShares())) {
        if (open_orders[order_cancel.GetOrderID()]->NumberOfShares() == 0) {
            open_orders.erase(order_cancel.GetOrderID());
        }
    }
}

void OrderManager::AddOrderExecuted(const string& line)
{
    OrderExecuted order_executed(line);

    executed_orders[open_orders[order_executed.GetOrderID()]->GetStockSymbol()] += order_executed.GetExecutedShares();

    if (open_orders[order_executed.GetOrderID()]->MinusShares(order_executed.GetExecutedShares())) {
        if (open_orders[order_executed.GetOrderID()]->NumberOfShares() == 0) {
            open_orders.erase(order_executed.GetOrderID());
        }
    }
}

void OrderManager::AddTradeShort(const string& line)
{
    OrderTrade order_trade(line);
    executed_orders[order_trade.GetStockSymbol()] += order_trade.GetNumberOfShares();
}


