#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include "MerkelMain.h"

using namespace std;

int main() {
    Wallet wallet;

    // // Test Wallet::insertCurrency()

    // // Test 1
    // cout << "- if currency 'type' is not in the wallet yet, set the amount to amount." << endl;
    // cout << "Currently, the wallet is empty:" << endl;
    // cout << wallet.toString() << endl;
    // cout << "Insert BTC with amount 5, the output should be 'BTC : 5.000000'" << endl;
    // wallet.insertCurrency("BTC", 5);
    // cout << wallet.toString() << endl;

    // // Test 2
    // cout << "- if currency 'type' is already in the wallet and has > 0,";
    // cout << " add amount to the current amount." << endl;
    // cout << "Insert BTC with amount 12, the output should be 'BTC : 17.000000'" << endl;
    // wallet.insertCurrency("BTC", 12);
    // cout << wallet.toString() << endl;

    // // Test 3
    // cout << "- throw an exception if 'amount' is less than 0" << endl;
    // wallet.insertCurrency("BTC", -12);
    // cout << wallet.toString() << endl;

    // Test Wallet::removeCurrency()

    // Give the wallet some initial funds
    // wallet.insertCurrency("ETH", 100);
    // cout << "Currently, the wallet has: " << wallet.toString() << endl;

    // // Test 1
    // cout << "- if the wallet does not contain this much currency, ";
    // cout << "do not change the wallet and return true" << endl;
    // cout << "(I found the instruction here might be wrong, ";
    // cout << "we should return false here.)" << endl;
    // bool currencyRemoved = wallet.removeCurrency("USDT", 12);
    // if (!currencyRemoved) {cout << "We didn't remove the currency." << endl;}
    // cout << wallet.toString() << endl; // this should be 'ETH : 100.000000'

    // // Test 2
    // cout << "If the wallet does contain at least this much currency of this type, ";
    // cout << "remove the currency from the wallet and return true" << endl;
    // currencyRemoved = wallet.removeCurrency("ETH", 75);
    // if (!currencyRemoved) {cout << "We didn't remove the currency." << endl;}
    // cout << wallet.toString() << endl; // this should be 'ETH : 25.000000'

    // // Test 3
    // cout << "- throw an exception if amount < 0" << endl;
    // wallet.removeCurrency("BTC", -75);

    // Test Wallet::containsCurrency()

    // Give the wallet some initial funds
    // wallet.insertCurrency("ETH", 100);
    // cout << "Currently, the wallet has: " << wallet.toString() << endl;
    // string message_true = "True, the wallet contains the sent amount of currency or more";
    // string message_false = "False, the wallet does not contain the sent amount of currency or more";

    // // Test 1
    // cout << "- if the wallet contains the sent amount of currency or more, return true" << endl;
    // bool currencyContained = wallet.containsCurrency("ETH", 50);
    // cout << "Contains 'ETH, 50'?" << endl;
    // if (currencyContained) {cout << message_true << endl;}
    // else {cout << message_false << endl;}

    // cout << endl;

    // // Test 2
    // cout << "- if the wallet does not contains the sent amount of currency or more, return false" << endl;
    // currencyContained = wallet.containsCurrency("ETH", 50000);
    // cout << "Contains 'ETH, 50000'?" << endl;
    // if (currencyContained) {cout << message_true << endl;}
    // else {cout << message_false << endl;}

    // wallet.removeCurrency("BTC", 10);
    // cout << wallet.toString() << endl;

    // OrderBookEntry obe{"timestamp", "USDT/BTC", OrderBookType::ask, 10, 25};
    // if (wallet.canFullfillOrder(obe)) {
    //     cout << "Fullfilled the order!";
    // }

    MerkelMain app{};
    app.init();
}
