#pragma once
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <string>
#include <vector>

using namespace std;

class OrderBook {

    public:
    /* Construct, reading a csv file */
        OrderBook(std::string filename);

    /* Return vector of all known products in the dataset */
        vector<string> getKnownProducts();

    /* Return vector of Orders according to the sent filters */
        vector<OrderBookEntry> getOrders(
            OrderBookType type,
            string product,
            string timestamp
        );
        string getEarlistTime();

        static double getHighPrice(vector<OrderBookEntry>& orders);
        static double getLowPrice(vector<OrderBookEntry>& orders);

    private:
        vector<OrderBookEntry> orders;
};

