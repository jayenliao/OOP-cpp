#include <vector>
#include <string>
#include "CSVReader.h"

using namespace std;

CSVReader::CSVReader() {

}
vector<OrderBookEntry> CSVReader::readCSV(string csvFilename) {
    vector<OrderBookEntry> entries;
    return entries;
}
vector<string> CSVReader::tokenize(string csvLine, char separator) {
    vector<string> tokens;
    return tokens;
}
OrderBookEntry CSVReader::strToOBE(vector<string> strings) {
    OrderBookEntry obe{
        "_timestamp",
        "_product",
        OrderBookType::bid,
        1,
        1
    };
    return obe;
}
