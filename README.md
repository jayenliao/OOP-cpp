# Object Oriented Programming with C++ (OOP-cpp)

This is the repo for learning a coursera specialization "Object Oriented Programming (OOP)", which contains 5 courses. Here are their names and my certificate for completing them.

- [Courese 1 (C1) - Intro to OOP in C++](https://www.coursera.org/account/accomplishments/verify/KOUVZCM0NOC3)

- [Courese 2 (C2) - C++ Programming: Classes and Data](https://www.coursera.org/account/accomplishments/verify/D7VC80IHBXYT)

- [Courese 3 (C3) - OOP in C++: Functions](https://www.coursera.org/account/accomplishments/verify/OBLRCRITZWEH)

- [Courese 4 (C4) - Working with Objects in C++](https://www.coursera.org/account/accomplishments/verify/OBOC4RVAVH7Q)

- [Courese 5 (C5)- Use C++ to build a Crypto Trading Platform: Final System](https://www.coursera.org/account/accomplishments/verify/SXY015LTX649)

- [Certificate for completing the spefication with these 5 courses](https://coursera.org/share/c1f32e6c3596fb52cd6112859b4c91d6)

## Completed assignments

1. **[MerkleRex main menu with if statements](https://github.com/jayenliao/OOP-cpp/blob/main/C1M1/assignment_c1m1_jc-liao.mp4)** submitted on 30 July 2023.

2. **[Implement and use the OrderBookEntry class to compute some basic statistics](https://github.com/jayenliao/OOP-cpp/tree/main/C2M1/assignment)**, submitted on 10 August 2024.

3. [**csStudent: information about computer science students**](https://github.com/jayenliao/OOP-cpp/tree/main/C3M1/assignment), submitted on 15 August 2024.

4. [**Implement a market analysis function***](https://github.com/jayenliao/OOP-cpp/tree/main/C4M1#readme), submitted on 2 September, 2024.

5. [**Test the Wallet functions: `insertCurrency`, `removeCurrency`, and `containsCurrency`**](https://github.com/jayenliao/OOP-cpp/tree/main/C5/assignment#readme), submitted on 4 September.

## Usage of Project - Crypto Trading Platform

```bash
clone https://github.com/jayenliao/OOP-cpp.git
cd OOP-cpp/C5/

g++ CSVReader.cpp MerkelMain.cpp OrderBook.cpp OrderBookEntry.cpp Wallet.cpp main.cpp --std=c++11

./a.out
```

### Scripts

All files mentioned here are under the folder `C5/`.

- [`OrderBookEntry.h`](https://github.com/jayenliao/OOP-cpp/blob/main/C5/OrderBookEntry.h) and [`OrderBookEntry.cpp`](https://github.com/jayenliao/OOP-cpp/blob/main/C5/OrderBookEntry.cpp) defines and implements the `OrderBookEntry` class to represent a trade (either an ask or a bid), with properties like timestamp, product (currency A / currency B), price, and amount.

- [`CSVReader.h`](https://github.com/jayenliao/OOP-cpp/blob/main/C5/CSVReader.h) and [`CSVReader.cpp`](https://github.com/jayenliao/OOP-cpp/blob/main/C5/CSVReader.cpp) defines and implements the class `CSVReader` for reading a csv file of trading log.

- [`OrderBook.h`](https://github.com/jayenliao/OOP-cpp/blob/main/C5/OrderBook.h) and [`OrderBook.cpp`](https://github.com/jayenliao/OOP-cpp/blob/main/C5/OrderBookEntry.cpp) defines and implements the class `OrderBook`, which use an instance of `CSVReader` to read a CSV file and represent CSV lines and a set of instances of `OrderBookEntry`. `OrderBook` also has some functions, such as getting statistics from orders.

- [`Wallet.h`](https://github.com/jayenliao/OOP-cpp/blob/main/C5/Wallet.h) and [`Wallet.cpp`](https://github.com/jayenliao/OOP-cpp/blob/main/C5/Wallet.cpp) defines and implements the class `Wallet` with functions to deal with currencies in user's wallet (an instance of `Wallet`) and trades, including `insertCurrency`, `removeCurrency`, `containsCurrency`, `canFullfillOrder`, `processSale`, and the function to print out the wallet balance, `toString`.

- [`MerkelMain.h`](https://github.com/jayenliao/OOP-cpp/blob/main/C5/MerkelMain.h) and [`MerkelMain.cpp`](https://github.com/jayenliao/OOP-cpp/blob/main/C5/MerkelMain.cpp) defines and implements the class `MerkelMain`, which is the main app class. Functions that are called when an option is entered are defined and implemented by `MerkelMain`, including:

    ```cpp
    void printHelp();        // option 1
    void printMarketStats(); // option 2
    void enterAsk();         // option 3
    void enterBid();         // option 4
    void printWallet();      // option 5
    void gotoNextTimeFrame();// option 6
    ```

An instance of this class instantiates `Wallet` and call its functions.

- [`main.cpp`](https://github.com/jayenliao/OOP-cpp/blob/main/C5/main.cpp) states the main program of calling `MerkelMain` as the main app. It was also used to test `Wallet`'s operations.

### Program Workflow

1. Loading the data from the csv file `20200317.csv` using `CSVReader`.

    - A warning message is shown for each bad csv line.

    - A bad line is a line without any of properties in the correct format:

        ```cpp
        OrderBookEntry::OrderBookEntry(
            std::string _timestamp,
            std::string _product,
            OrderBookType _orderType,
            double _price,
            double _amount,
            string _username
        )
        ```

    - How many entries the `CSVReader` loads into the program is also reported.

    - Print out example:

        ```text
        Error: a bad line!

        CSVReader::readCSV has read bad data

        Error: a bad line!

        CSVReader::readCSV has read bad data
        CSVReader::readCSV has read 3540 entries
        ```

2. Print out the `MerkleRex Menu` for user to select the function.

    - Print out example:

        ```text
        ----- MerkleRex Menu -----
        1. Print help
        2. Print exchange stats
        3. Make an ask
        4. Make a bid
        5. Print wallet
        6. Continue
        ===========================
        Current time: 2020/03/17 17:01:24.884492
        Select an option from 1 to 6:
        ```

    - Invalid input (not an integer between 1 and 6) would be identified and the user would be asked to give a valid input until they do so.

3. User selects an option (option 2, 3, 4, or 5):

    - If the user selects option 2, some basics statistics of all products (i.e., currency pairs) would be shown, for example:

        ```text
        Product: BTC/USDT
        Asks seen: 50
        Maximum ask: 5460.12
        Minimum ask: 5352
        Ask price change in the last 1H: 5460.12 - 5352 = 108.123 (2.02024%)
        Average ask price: 5394.8
        Std of ask price: 184.389

        Product: ETH/BTC
        Asks seen: 50
        Maximum ask: 0.0222704
        Minimum ask: 0.0218909
        Ask price change in the last 1H: 0.0222704 - 0.0218909 = 0.00037949 (1.73355%)
        Average ask price: 0.0220735
        Std of ask price: 0.00095546
        ```

    - If the user selects option 3, a set of values (i.e., product, ask price, and ask amount) is required to be entered. Invalid values will trigger the progam to keep asking to enter until satisfied.

        - Sending an ask of "currecny A / currency B" means that someone wants to sell currency A with the given price and amount to gain currency B.

    - If the user selects option 5, a set of values (i.e., product, bid price, and bid amount) is required to be entered. Invalid values will trigger the progam to keep asking to enter until satisfied.

        - Sending a bid of "currecny A / currency B" means that someone wants to use currency B to buy currency A with the given price and amount.

    - If the user selects option 5, the user's wallet balance of all funds will be printed out, for example:

        ```text
        Select an option from 1 to 6: 5
        Your choice: 5
        Print wallet:

        BTC : 10.000000
        ETH : 100.000000
        ```

    - If the user selects option 6, the program goes to the next time frame. It the user just sent an ask or a bid (i.e., selected option 3 or 4), selecting option 6 is required to process that ask or bid.
