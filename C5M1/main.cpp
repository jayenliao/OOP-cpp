#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include "MerkelMain.h"

using namespace std;

int main() {
    // MerkelMain app{};
    // app.init();

    Wallet wallet;

    // Test 1
    cout << "- if currency 'type' is not in the wallet yet, set the amount to amount." << endl;
    wallet.insertCurrency("BTC", 5);
    cout << wallet.toString() << endl;

    // Test 2
    cout << "- if currency 'type' is not in the wallet yet, set the amount to amount." << endl;
    wallet.insertCurrency("BTC", 12);
    cout << wallet.toString() << endl;

    // Test 3
    cout << "- throw an exception if 'amount' is less than 0" << endl;
    wallet.insertCurrency("BTC", -12);
    cout << wallet.toString() << endl;

    // wallet.removeCurrency("BTC", 10);
    // cout << wallet.toString() << endl;

    // OrderBookEntry obe{"timestamp", "USDT/BTC", OrderBookType::ask, 10, 25};
    // if (wallet.canFullfillOrder(obe)) {
    //     cout << "Fullfilled the order!";
    // }
}
