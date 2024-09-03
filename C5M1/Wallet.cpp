#include "Wallet.h"
using namespace std;

Wallet::Wallet() {

}

void Wallet::insertCurrency(string type, double amount) {
    if (amount < 0) {
        throw exception{};
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

bool Wallet::containsCurrency(string type, double amount) {
    if (currencies.count(type) == 0) {
        return false;
    } else {
        return currencies[type];
    }
}

string Wallet::toString() {
    return "oink";
}
