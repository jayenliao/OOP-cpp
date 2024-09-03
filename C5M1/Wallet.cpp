#include "Wallet.h"
using namespace std;

Wallet::Wallet() {

}

void Wallet::insertCurrency(string type, double amount) {
    double balance;

    if (amount < 0) {
        throw exception{};
    }
    if (currencies.count(type) == 0) {
        balance = 0;
    } else {
        balance = currencies[type];
    }
    balance += amount;
    currencies[type] = balance;
}

bool Wallet::containsCurrency(string type, double amount) {
    return false;
}

string Wallet::toString() {
    return "oink";
}
