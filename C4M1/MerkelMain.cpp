#include <iostream>
#include <vector>
#include "MerkelMain.h"
#include "OrderBookEntry.h"
#include "CSVReader.h"

using namespace std;

MerkelMain::MerkelMain() {

}

void MerkelMain::init() {
    // loadOrderBook();
    int input;
    currentTime = orderBook.getEarlistTime();
    while (true) {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

// void MerkelMain::loadOrderBook() {
//     orders = CSVReader::readCSV("/Users/jayliao/Documents/2_areas/001_programming/cpp/coursera_OOP_specialization/C3M1/Merkelerex/src/20200317.csv");
// }

void MerkelMain::printMenu() {
    cout << "----- MerkleRex Menu -----" << endl;
    cout << "1. Print help" << endl;
    cout << "2. Print exchange stats" << endl;
    cout << "3. Make an ask" << endl;
    cout << "4. Make a bid" << endl;
    cout << "5. Print wallet" << endl;
    cout << "6. Continue" << endl;
    cout << "===========================" << endl;
    cout << "Current time: " << currentTime << endl;
}

void MerkelMain::printHelp() {
    cout << "Help: Your aim is to make money, analyze the market, and make bids and offers.\n" << endl;
}

void MerkelMain::printMarketStats() {
    for (string const& p : orderBook.getKnownProducts()) {
        cout << "Product: " << p << endl;
        vector<OrderBookEntry> entries = orderBook.getOrders(
            OrderBookType::ask, p, currentTime
        );
        cout << "Asks seen: " << entries.size() << endl;
        cout << "Maximum ask: " << OrderBook::getHighPrice(entries) << endl;
        cout << "Minimum ask: " << OrderBook::getLowPrice(entries) << endl;

        vector<double> prices1H = OrderBook::get1HPrices(entries, currentTime);
        double change = prices1H[1] - prices1H[0];
        double change_percent = change / prices1H[0] * 100;
        cout << "Ask price change in the last 1H: " << prices1H[1] << " - " <<  prices1H[0] << " = " << change << " (" << change_percent << "%)" << endl;

        cout << "Average ask price: " << OrderBook::getPriceMean(entries) << endl;
        cout << "Std of ask price: " << OrderBook::getPriceStd(entries) << endl;
        cout << endl;

    }
    // cout << "OrderBook contains: " << orders.size() << " entries.\n" << endl;
    // unsigned int bids = 0;
    // unsigned int asks = 0;
    // for (OrderBookEntry& entry : orders) {
    //     if (entry.orderType == OrderBookType::bid) {++bids;}
    //     if (entry.orderType == OrderBookType::ask) {++asks;}
    // }
    // cout << "Number of bids = " << bids << endl;
    // cout << "Number of asks = " << asks << endl;
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
    currentTime = orderBook.getNextTime(currentTime);
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
