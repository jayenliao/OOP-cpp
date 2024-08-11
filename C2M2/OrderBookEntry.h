#pragma once
#include <string>
using namespace std;

enum class OrderBookType{bid, ask};

class OrderBookEntry {
    public:
        OrderBookEntry(
            string timestamp,
            string product,
            OrderBookType orderType,
            double price,
            double amount
        );

        string timestamp;
        string product;
        OrderBookType orderType;
        double price;
        double amount;
};
