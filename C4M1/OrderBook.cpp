#include "OrderBook.h"
#include <map>

using namespace std;

/* Construct, reading a csv file */
OrderBook::OrderBook(std::string filename) {
    orders = CSVReader::readCSV(filename);
}

/* Return vector of all known products in the dataset */
vector<string> OrderBook::getKnownProducts() {
    vector<string> products;
    map<string, bool> prodMap;

    for (OrderBookEntry& order : orders) {
        prodMap[order.product] = true;
    }

    // Now flatten the map to a vector of strings
    for (auto const& product : prodMap) {
        products.push_back(product.first);
    }

    return products;
}

/* Return vector of Orders according to the sent filters */
vector<OrderBookEntry> OrderBook::getOrders(
    OrderBookType type,
    string product,
    string timestamp
) {
    vector<OrderBookEntry> orders_sub;
    return orders_sub;
}

