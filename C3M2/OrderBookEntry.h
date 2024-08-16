#pragma once

#include <string>

enum class OrderBookType{bid, ask};

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
        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;
};
