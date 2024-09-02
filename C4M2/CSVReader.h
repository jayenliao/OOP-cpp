#pragma once

#include <vector>
#include <string>
#include "OrderBookEntry.h"

using namespace std;

class CSVReader {
    public:
        CSVReader();
        static vector<OrderBookEntry> readCSV(string csvFilename);
        static vector<string> tokenize(string csvLine, char separator);
    private:
        static OrderBookEntry strToOBE(vector<string> strings);
};
