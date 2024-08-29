#pragma once
#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"

using namespace std;

class MerkelMain {
    public:
        MerkelMain();
        /** Call this to start the sim */
        void init();

    private:
        // void loadOrderBook();
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterOffer();
        void enterBid();
        void printWallet();
        void gotoNextTimeFrame();
        void warnInvalid();
        int getUserOption();
        void processUserOption(int userOption);

        OrderBook orderBook{"20200317.csv"};
};
