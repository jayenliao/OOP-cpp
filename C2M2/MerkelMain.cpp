#include <iostream>
#include <vector>
#include "MerkelMain.h"
#include "OrderBookEntry.h"

using namespace std;

MerkelMain::MerkelMain() {

}

void MerkelMain::init() {
    loadOrderBook();
    int input;
    while (true) {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MerkelMain::loadOrderBook() {
    orders.push_back(OrderBookEntry("2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::ask, 5377.46076613,0.0064523));
    orders.push_back(OrderBookEntry("2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::ask, 5378.24518971,0.88506963));
    orders.push_back(OrderBookEntry("2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::ask, 5381.87187775,0.0008));
    orders.push_back(OrderBookEntry("2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::ask, 5384.99999998,0.73293336));
    orders.push_back(OrderBookEntry("2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::ask, 5385.,0.0194056));
    orders.push_back(OrderBookEntry("2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::ask, 5400.,0.0384));
    orders.push_back(OrderBookEntry("2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::bid, 5290.,0.00903071));
    orders.push_back(OrderBookEntry("2020/03/17 17:01:30.099017", "BTC/USDT", OrderBookType::bid, 5340.8502489, 0.00735261));
    orders.push_back(OrderBookEntry("2020/03/17 17:01:30.099017", "BTC/USDT", OrderBookType::bid, 5338.00000001, 0.4284));
    orders.push_back(OrderBookEntry("2020/03/17 17:01:30.099017", "BTC/USDT", OrderBookType::bid, 5338., 0.00187337));

}

void MerkelMain::printMenu() {
    cout << "----- MerkleRex Menu -----" << endl;
    cout << "1. Print help" << endl;
    cout << "2. Print exchange stats" << endl;
    cout << "3. Make an ask" << endl;
    cout << "4. Make a bid" << endl;
    cout << "5. Print wallet" << endl;
    cout << "6. Continue" << endl;
}

void MerkelMain::printHelp() {
    cout << "Help: Your aim is to make money, analyze the market, and make bids and offers.\n" << endl;
}

void MerkelMain::printMarketStats() {
    cout << "OrderBook contains: " << orders.size() << " entries.\n" << endl;

}

void MerkelMain::enterOffer() {
    cout << "Make an offer: Enter the amount to ask.\n" << endl;
}

void MerkelMain::enterBid() {
    cout << "Make a bid: Enter the amount to bid.\n" << endl;
}

void MerkelMain::printWallet() {
    cout << "Print wallet: Your wallet is empty.\n" << endl;
}

void MerkelMain::gotoNextTimeFrame() {
    cout << "Continue: Going to next time frame.\n" << endl;
}

void MerkelMain::warnInvalid() {
    cout << "Invalid choice. Please select an integer between 1 and 6.\n" << endl;
}

int MerkelMain::getUserOption() {
    int userOption;
    cout << "Select an option from 1 to 6: ";
    cin >> userOption;
    cout << "Your choice: " << userOption << endl;
    return userOption;
}

void MerkelMain::processUserOption(int userOption) {
    if (userOption == 1) {
        printHelp();
    } else if (userOption == 2) {
        printMarketStats();
    } else if (userOption == 3) {
        enterOffer();
    } else if (userOption == 4) {
        enterBid();
    } else if (userOption == 5) {
        printWallet();
    } else if (userOption == 6) {
        gotoNextTimeFrame();
    } else {
        warnInvalid();
    }
}
