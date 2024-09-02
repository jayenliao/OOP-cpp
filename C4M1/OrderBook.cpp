#include "OrderBook.h"
#include <map>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <cmath>

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
    for (OrderBookEntry& entry : orders) {
        if (
            entry.orderType == type &&
            entry.product == product &&
            entry.timestamp == timestamp
        ) {
            orders_sub.push_back(entry);
        }
    }

    return orders_sub;
}


double OrderBook::getHighPrice(vector<OrderBookEntry>& orders) {
    double max = orders[0].price;
    for (OrderBookEntry& entry : orders) {
        if (entry.price > max) {max = entry.price;}

    }
    return max;
}

double OrderBook::getLowPrice(vector<OrderBookEntry>& orders) {
    double min = orders[0].price;
    for (OrderBookEntry& entry : orders) {
        if (entry.price < min) {min = entry.price;}

    }
    return min;
}

vector<double> OrderBook::get1HPrices(vector<OrderBookEntry>& orders, string& currentTime) {
    // Parse the currentTime into a time_t object
    tm tm = {};
    istringstream ss(currentTime.substr(0, 19));
    ss >> get_time(&tm, "%Y/%m/%d %H:%M:%S");
    time_t currentTimestamp = mktime(&tm);

    double firstPrice = 0.0;
    double lastPrice = 0.0;
    bool foundFirst = false;

    // Iterate over the orders to find the prices within the 1H window
    for (const auto& order : orders)
    {
        // Parse the order timestamp into a time_t object
        std::tm orderTime = {};
        std::istringstream orderSS(order.timestamp.substr(0, 19));
        orderSS >> std::get_time(&orderTime, "%Y/%m/%d %H:%M:%S");
        time_t orderTimestamp = mktime(&orderTime);

        // Check if the order is within the 1-hour window
        if (difftime(orderTimestamp, currentTimestamp) <= 60) {
            if (!foundFirst) {
                firstPrice = order.price;
                foundFirst = true;
            }
            lastPrice = order.price;
        }

        if (!foundFirst) {
            throw runtime_error("No orders found within the 24-hour window");
        }
    }

    vector<double> prices1H;
    prices1H.push_back(firstPrice);
    prices1H.push_back(lastPrice);

    return prices1H;
}

double OrderBook::getPriceMean(vector<OrderBookEntry>& orders) {
    double sum = 0;
    for (const OrderBookEntry& order : orders) {
        sum += order.price;
    }
    return orders.empty() ? 0 : sum / orders.size();
}

double OrderBook::getPriceStd(vector<OrderBookEntry>& orders) {
    double sum_sq = 0;
    double priceMean = getPriceMean(orders)
    for (const OrderBookEntry& order : orders) {
        sum_sq += pow((order.price - priceMean), 2);
    }
    return sqrt(sum_sq);
}

string OrderBook::getEarlistTime() {
   return orders[0].timestamp;
}

string OrderBook::getNextTime(string timestamp) {
   string next_timestamp = "";
   for (OrderBookEntry& entry : orders) {
        if (entry.timestamp > timestamp) {
            next_timestamp = entry.timestamp;
            break;
        }
   }
   if (next_timestamp == "") {
        next_timestamp = orders[0].timestamp;
   }
   return next_timestamp;
}
