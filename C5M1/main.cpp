#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include "MerkelMain.h"

using namespace std;

int main() {
    MerkelMain app{};
    app.init();

    Wallet wallet;
    wallet.insertCurrency("BTC", 10);
    wallet.insertCurrency("USDT", 10000);
    // cout << "Wallet has BTC " << wallet.containsCurrency("BTC", 10) << endl;
    // cout << "Wallet contains USDT " << wallet.containsCurrency("USDT", 10000) << endl;
    cout << wallet.toString() << endl;

}
