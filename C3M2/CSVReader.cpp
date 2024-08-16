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
CSVReader::tokenize(string csvLine, char separator) {
    vector<string> tokens;
    return tokens;
}
CSVReader::strToOBE(vector<string> strings) {
    OrderBookEntry obe{
        double 1,
        double 1,
        std::string "_timestamp",
        std::string "_product",
        OrderBookType OrderBookType::bid
    };
    return obe;
}
