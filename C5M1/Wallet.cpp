#include "Wallet.h"
#include <iostream>
using namespace std;

Wallet::Wallet() {

}

void Wallet::insertCurrency(string type, double amount) {
    if (amount < 0) {
        throw exception();
    }

    double balance;
    if (currencies.count(type) == 0) {
        balance = 0;
    } else {
        balance = currencies[type];
    }
    balance += amount;
    currencies[type] = balance;
}

bool Wallet::removeCurrency(string type, double amount) {
    if (amount < 0) {
        return false;
    }

    double balance;
    if (currencies.count(type) == 0) {
        return false;
    } else {
        // do we have an enough amount of this currency?
        if (containsCurrency(type, amount)) { // yes
            cout << "Removing " << type << ": " << to_string(amount) << endl;
            currencies[type] -= amount;
            return true;
        } else {                              // not enough
            return false;
        }
    }
}

bool Wallet::containsCurrency(string type, double amount) {
    if (currencies.count(type) == 0) {
        return false;
    } else {
        return currencies[type];
    }
}

string Wallet::toString() {
    string out;
    for (pair<string, double> pair : currencies) {
        string currency = pair.first;
        double amount = pair.second;
        out += currency + " : " + to_string(amount) + "\n";
    }
    return out;
}


