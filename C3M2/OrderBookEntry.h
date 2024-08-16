#pragma once
#include <string>

using namespace std;

enum class OrderBookType{bid, ask, unknown};

class OrderBookEntry
{
    public:
        OrderBookEntry(
            string _timestamp,
            string _product,
            OrderBookType _orderType,
            double _price,
            double _amount
        );
        static OrderBookType strToOBT(string s);

        double price;
        double amount;
        string timestamp;
        string product;
        OrderBookType orderType;
};
