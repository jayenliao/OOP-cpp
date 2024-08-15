#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> tokenize(string csvLine, char separator) {

    // string vector tokens ## stores the tokens
    vector<string> tokens;

    // int start end ## used to delineate token positions
    signed int start, end;
    string token;

    start = csvLine.find_first_not_of(separator, 0);
    do {
        end = csvLine.find_first_of(separator, start);
        if (start == csvLine.length() || start == end) {break;}
        if (end >= 0) { // a token is found
            token = csvLine.substr(start, end - start);
        }
        else {
            token = csvLine.substr(start, csvLine.length() - start);
        }
        tokens.push_back(token);
        start = end + 1;
    } while (end > 0);

    return tokens;
};

int main() {

    ifstream csvFile{"Merkelerex/src/20200317.csv"};
    string line;
    vector<string> tokens;

    if (csvFile.is_open()) {
        cout << "File is opened!\n\n" << endl;
        while (getline(csvFile, line)) {
            cout << "Read line " << line << endl;
            tokens = tokenize(line, ',');
            for (string& t : tokens) {
                if (tokens.size() != 5) {
                    cout << "\nError: a bad line!\n" << endl;
                    continue;
                }
                double price = stod(tokens[3]);
                double amount = stod(tokens[4]);
                cout << "Price=" << price << " | Amount" << amount << endl;
            }
        }
        csvFile.close();
    }
    else {
        cout << "File can not be opened!" << endl;

    }

    return 0;


    // vector<string> tokens;
    // // string s;
    // // cout << "Enter a string: ";
    // // cin >> s;
    // string s = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869";
    // tokens = tokenize(s, ',');

    // for (string& t : tokens) {
    //     cout << t << endl;
    // }

    // return 0;
};
