#include <iostream>
#include <string>
#include <vector>

using namespace std; // then we don't need to keep writing std::

enum class OrderBookType{bid, ask};

class OrderBookEntry {
    public:
        // Here, we don't follow the variable order of course videos.
        // Instead, we use the variable (column) order of file 20200317.csv
        OrderBookEntry(
            string timestamp,
            string product,
            OrderBookType orderType,
            double price,
            double amount
        )
        : timestamp(timestamp), product(product), orderType(orderType), price(price), amount(amount)
        {

        }
        string timestamp;
        string product;
        OrderBookType orderType;
        double price;
        double amount;
};

// Utility functions
string orderBookTypeToString(OrderBookType type);
double computeAveragePrice(const vector<OrderBookEntry>& orders);
double computeLowPrice(const vector<OrderBookEntry>& orders);
double computeHighPrice(const vector<OrderBookEntry>& orders);
double computePriceSpread(const vector<OrderBookEntry>& orders);

int main() {

    // Creating a vector of OrderBookEntry objects
    vector<OrderBookEntry> orders = {
        OrderBookEntry("2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::ask, 5377.46076613,0.0064523),
        OrderBookEntry("2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::ask, 5378.24518971,0.88506963),
        OrderBookEntry("2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::ask, 5381.87187775,0.0008),
        OrderBookEntry("2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::ask, 5384.99999998,0.73293336),
        OrderBookEntry("2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::ask, 5385.,0.0194056),
        OrderBookEntry("2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::ask, 5400.,0.0384),
        OrderBookEntry("2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::bid, 5290.,0.00903071),
        OrderBookEntry("2020/03/17 17:01:30.099017", "BTC/USDT", OrderBookType::bid, 5340.8502489, 0.00735261),
        OrderBookEntry("2020/03/17 17:01:30.099017", "BTC/USDT", OrderBookType::bid, 5338.00000001, 0.4284),
        OrderBookEntry("2020/03/17 17:01:30.099017", "BTC/USDT", OrderBookType::bid, 5338., 0.00187337)
    };

    // Iterating over the vector and printing each entry
    cout << endl;
    cout << "---- List of all order entries ----" << endl;
    for (const OrderBookEntry order : orders) {
        cout << order.timestamp
                << " | Product: " << order.product
                << ", Order Type: " << orderBookTypeToString(order.orderType)
                << ", Price: " << order.price
                << ", Amount: " << order.amount << endl;
    }
    cout << endl;

    // Computing and displaying basic statistics
    cout << "------- Statistics of PRICE ------" << endl;
    cout << "Average Price: " << computeAveragePrice(orders) << endl;
    cout << "Lowest Price: " << computeLowPrice(orders) << endl;
    cout << "Highest Price: " << computeHighPrice(orders) << endl;
    cout << "Price Spread: " << computePriceSpread(orders)
            << " = Highest - Lowest Price = "
            << computeHighPrice(orders) << " - " << computeLowPrice(orders) << endl;
    cout << endl;

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
