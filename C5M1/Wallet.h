#include <string>
#include <map>
#include "OrderBookEntry.h"

using namespace std;

class Wallet {
    public:
        Wallet();

        /** intert currency to the wallet */
        void insertCurrency(string type, double amount);

        /** remove currency from the wallet */
        bool removeCurrency(string type, double amount);

        /** check if the wallet contains such much currency or more */
        bool containsCurrency(string type, double amount);

        bool canFullfillOrder(const OrderBookEntry order);

        /** generate a string representation of the wallet */
        string toString();

    private:
        map<string, double> currencies;

};
