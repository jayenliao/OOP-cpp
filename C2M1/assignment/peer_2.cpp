#include <iostream>
#include <string>
#include <math.h>


enum class OrderBookType { ask, bid};

class OrderBookEntry // this is the name of the class
{
    public: // parts of the class that can be seen from outside
    //Constructor
    OrderBookEntry(std::string _dateTimestamp, std::string _product, OrderBookType _orderType, double _price, double _amount);

    std::string dateTimestamp;
    std::string product;
    OrderBookType orderType;
    double price; 
    double amount;
}; 

OrderBookEntry::OrderBookEntry(std::string _dateTimestamp, std::string _product, OrderBookType _orderType, double _price, double _amount)
            : dateTimestamp(_dateTimestamp),
              product(_product),
              orderType(_orderType),
              price(_price),
              amount(_amount)
              {}


double computeAveragePrice(std::vector<OrderBookEntry>& entries) {
    double totPrice = 0;
    double nbrEntries = entries.size();
    if (nbrEntries == 0) {
        return 0;
    } else {
        for(OrderBookEntry& e : entries) {
            totPrice += e.price;
        }
        return totPrice/nbrEntries;
    }
}

double computeLowPrice(std::vector<OrderBookEntry>& entries) {
    if (entries.size() == 0) {
        return 0;
    } else {
        double lowestPrice = entries[0].price;
        for(OrderBookEntry& e : entries) {
            lowestPrice = std::min(lowestPrice, e.price);
        }
        return lowestPrice;
    }
}

double computeHighPrice(std::vector<OrderBookEntry>& entries) {
    if (entries.size() == 0) {
        return 0;
    } else {
        double highestPrice = entries[0].price;
        for(OrderBookEntry& e : entries) {
            highestPrice = std::max(highestPrice, e.price);
        }
        return highestPrice;
    }
}

double computePriceSpread(std::vector<OrderBookEntry>& entries) {
    return computeHighPrice(entries) - computeLowPrice(entries);
}

void printMenu()
{
    // 1 print help
    std::cout << "1: Print help " << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats" << std::endl;
    // 3 make an offer
    std::cout << "3: Make an offer " << std::endl;
    // 4 make a bid 
    std::cout << "4: Make a bid " << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet " << std::endl;
    // 6 continue   
    std::cout << "6: Continue " << std::endl;

    std::cout << "============== " << std::endl;
}

void printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << std::endl;
}

void  printMarketStats()
{
    std::cout << "Market looks good. " << std::endl;
}

void enterOffer()
{
    std::cout << "Mark and offer - enter the amount " << std::endl;
}

void enterBid()
{
    std::cout << "Make a bid - enter the amount" << std::endl;
}

void printWallet()
{
    std::cout << "Your wallet is empty. " << std::endl;
}
        
void gotoNextTimeframe()
{
    std::cout << "Going to next time frame. " << std::endl;
}
 
int getUserOption()
{
    int userOption;

    std::cout << "Type in 1-6" << std::endl;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void processUserOption(int userOption)
{
    if (userOption == 0) // bad input
    {
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
    }
    if (userOption == 1) // bad input
    {
        printHelp();
    }
    if (userOption == 2) // bad input
    {
        printMarketStats();
    }
    if (userOption == 3) // bad input
    {
        enterOffer();
    }
    if (userOption == 4) // bad input
    {
        enterBid();
    }
    if (userOption == 5) // bad input
    {
        printWallet();
    }
    if (userOption == 6) // bad input
    {
        gotoNextTimeframe();
    }       
}

int main()
{    
    /*
    while (true)
    {
        printMenu();
        int userOption = getUserOption();
        processUserOption(userOption);
    }
*/

    std::vector<OrderBookEntry> entries;
    // create an object of type OrderBookEntry
    // with a variable name of obe1
    OrderBookEntry obe1 = OrderBookEntry("2020/03/17 17:01:24.884492","ETR/BTC",OrderBookType::ask,0.125,100);
    OrderBookEntry obe2 = OrderBookEntry("2020/03/19 06:05:11.335487","ETR/BTC",OrderBookType::bid,0.5,50);

    entries.push_back(obe1);
    entries.push_back(obe2);

    for (OrderBookEntry& e : entries)
    {
        std::cout << e.price << std::endl;
    }

    std::cout << "Average Price: " << computeAveragePrice(entries) << std::endl;
    std::cout << "Lowest Price: " << computeLowPrice(entries) << std::endl;
    std::cout << "Highest Price: " << computeHighPrice(entries) << std::endl;
    std::cout << "Price Spread: " << computePriceSpread(entries) << std::endl;
    return 0;
}

