#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "MerkelMain.h"

using namespace std; // then we don't need to keep writing std::

// Utility functions
// string orderBookTypeToString(OrderBookType type);
// double computeAveragePrice(const vector<OrderBookEntry>& orders);
// double computeLowPrice(const vector<OrderBookEntry>& orders);
// double computeHighPrice(const vector<OrderBookEntry>& orders);
// double computePriceSpread(const vector<OrderBookEntry>& orders);

int main() {

    MerkelMain app{};
    app.init(); // initialize the app

    // // Iterating over the vector and printing each entry
    // cout << endl;
    // cout << "---- List of all order entries ----" << endl;
    // for (const OrderBookEntry order : orders) {
    //     cout << order.timestamp
    //             << " | Product: " << order.product
    //             << ", Order Type: " << orderBookTypeToString(order.orderType)
    //             << ", Price: " << order.price
    //             << ", Amount: " << order.amount << endl;
    // }
    // cout << endl;

    // // Computing and displaying basic statistics
    // cout << "------- Statistics of PRICE ------" << endl;
    // cout << "Average Price: " << computeAveragePrice(orders) << endl;
    // cout << "Lowest Price: " << computeLowPrice(orders) << endl;
    // cout << "Highest Price: " << computeHighPrice(orders) << endl;
    // cout << "Price Spread: " << computePriceSpread(orders)
    //         << " = Highest - Lowest Price = "
    //         << computeHighPrice(orders) << " - " << computeLowPrice(orders) << endl;
    // cout << endl;

    return 0;
}

string orderBookTypeToString(OrderBookType type) {
    if (type == OrderBookType::bid) {
        return "Bid";
    } else if (type == OrderBookType::ask) {
        return "Ask";
    } else {
        return "Unknown";
    }
}

double computeAveragePrice(const vector<OrderBookEntry>& orders) {
    double sum = 0;
    for (OrderBookEntry order : orders) {
        sum += order.price;
    }
    return orders.empty() ? 0 : sum / orders.size();
}

double computeLowPrice(const vector<OrderBookEntry>& orders) {
    double low = orders[0].price;
    for (OrderBookEntry order : orders) {
        if (order.price < low) {
            low = order.price;
        }
    }
    return low;
}

double computeHighPrice(const vector<OrderBookEntry>& orders) {
    double high = orders[0].price;
    for (OrderBookEntry order : orders) {
        if (order.price > high) {
            high = order.price;
        }
    }
    return high;
}

double computePriceSpread(const vector<OrderBookEntry>& orders) {
    double high = computeHighPrice(orders);
    double low = computeLowPrice(orders);
    return high - low;
}
