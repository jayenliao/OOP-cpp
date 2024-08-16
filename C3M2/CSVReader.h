#pragma once

#include <vector>
#include <string>
#include "OrderBookEntry.h"

using namespace std;

class CSVReader {
    public:
        CSVReader();
        static vector<OrderBookEntry> readCSV(string csvFilename);
    private:
        static vector<string> tokenize(string csvLine, char separator);
        OrderBookEntry strToOBE(vector<string> strings);
};
