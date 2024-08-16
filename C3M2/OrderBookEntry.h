#pragma once
#include <string>

enum class OrderBookType{bid, ask, unknown};

class OrderBookEntry
{
    public:
        OrderBookEntry(
            std::string _timestamp,
            std::string _product,
            OrderBookType _orderType,
            double _price,
            double _amount
        );
        static OrderBookType strToOBT(string s);

        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;
};
