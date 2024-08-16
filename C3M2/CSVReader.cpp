#include <vector>
#include <string>
#include <iostream>
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
OrderBookEntry CSVReader::strToOBE(vector<string> tokens) {
    if (tokens.size() != 5) {
        cout << "\nError: a bad line!\n" << endl;
        throw exception{};
    }
    double price, amount;
    try {
        price = stod(tokens[3]);
        amount = stod(tokens[4]);
    } catch (exception& e) {
        cout << "Bad float(s)! " << tokens[3] << " | " << tokens[4] << endl;
        throw;
    }
    OrderBookEntry obe{
        tokens[0],
        tokens[1],
        OrderBookEntry::strToOBT(tokens[2]),
        price,
        amount
    };
    return obe;
}
