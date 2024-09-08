# Course 4: Working with Objects in C++

To compile the files, please run the following command:

```bash
g++ CSVReader.cpp MerkelMain.cpp OrderBook.cpp OrderBookEntry.cpp main.cpp --std=c++11
```

## Assignment: Implement a market analysis function

### Instructions

The learning goals are to be able to do the following:

- Write functions that calculate statistics
- Use test data to verify your algorithm

#### Grading Criteria Overview

The assignment will be graded with a fairly light touch – essentially the grader checks that the work has all the required parts.

### Step-By-Step Assignment Instructions

You should start with a functioning Merklrerex build which can load in a data file and display the low and high statistics. This means you need to complete the lab worksheets which precede this peer assignment before you attempt this assignment.

Steps to take:

1. Check out this example screenshot from binance.com:

    ![](binance.png)

    Can you identify some metrics on there that are more interesting than high and low?

    Your job is to try and implement one of those metrics and to add it to the menu as an option.

2. Start by making sure you can load in a data file and print low and high statistics from a vector of orders

3. Add a function to the OrderBook class header named appropriately. It should have a similar signature to the getHighPrice function:

    ```cpp
    static double getHighPrice(std::vector<OrderBookEntry>& orders);
    ```

4. Write an implementation of your function.

5. Set up some test data and check that it is working as you'd expect. For example, you could manually create a vector of OrderBookEntries with specific values for amount and price and send that into the function to check it does what you expect.

To complete the assignment, you need to provide the following:

- A brief, high-level description of your statistic and how you found out about it.

- The code for your function

- A brief description of how you went about testing your function

### My Submission

#### Prompt 1: Write a brief, high-level description of your statistic and say how you found out about it.

- **getPriceMean** calculates the average price of orders over a specified period. It provides a simple yet powerful insight into the general price level within the dataset. I found out about this metric as it is commonly used in various forms of technical analysis to smooth out short-term fluctuations and highlight longer-term trends.

- **getPriceStd** computes the standard deviation of prices, which measures the amount of variation or dispersion in the dataset. A low standard deviation indicates that prices are close to the average, whereas a high standard deviation indicates a wide range of prices. This statistic is crucial for understanding market volatility. I learned about the importance of standard deviation in financial markets as it is a key component in risk assessment and trading strategies.

- **get1HPrices** is designed to retrieve all prices from the last hour within a dataset. By filtering the dataset to only include orders within the last 60 minutes (i.e., 3600 seconds), the function helps to focus on short-term price movements and can be used to compute price range. I identified this as a useful statistic for traders who want to understand recent market trends and make decisions based on the most current data available.

#### Prompt 2

```
Copy and paste the implementation of your function here. It will be assessed on the following points:

* Does it look functiona?

* Is it laid out neatly?

* Is there a well written comment above the function explaining what it does, what goes in (parameters) and what comes out (return)
```

- Please visit the [GitHub file](https://github.com/jayenliao/OOP-cpp/blob/main/C4M1/OrderBook.cpp) for better reference:

```cpp
// Function: getPriceAverage
// Purpose: Calculate the average price of orders over a specified period.
// Parameters:
// - const std::vector<double>& prices: A vector of prices to calculate the average from.
// Returns: The average price as a double.

double OrderBook::getPriceMean(vector<OrderBookEntry>& orders) {
        double sum = 0;
        for (const OrderBookEntry& order : orders) {
                 sum += order.price;
        }
        return orders.empty() ? 0 : sum / orders.size();}


// Function: getPriceStd
// Purpose: Calculate the standard deviation of prices over a specified period.
// Parameters:
// - const std::vector<double>& prices: A vector of prices to calculate the standard deviation from.
// Returns: The standard deviation of prices as a double.

double OrderBook::getPriceStd(vector<OrderBookEntry>& orders) {
        double sum_sq = 0;
        double priceMean = getPriceMean(orders);
        for (const OrderBookEntry& order : orders) {
               sum_sq += pow((order.price - priceMean), 2);
        }
        return sqrt(sum_sq);}


// Function: get1HPrices
// Purpose: Retrieve all prices from the last hour in the dataset.
// Parameters:
// - const std::vector<OrderBookEntry>& orders: A vector of order entries to be analyzed.
// - const std::string& currentTime: The current timestamp to calculate the 1-hour window.
// Returns: A vector of prices from the last hour.

std::vector<double> OrderBook::get1HPrices(const std::vector<OrderBookEntry>& orders, const std::string& currentTime) {
    std::vector<double> prices;
    std::tm tm = {};
    std::istringstream ss(currentTime);
    ss >> std::get_time(&tm, "%Y/%m/%d %H:%M:%S");
    time_t currentTimestamp = mktime(&tm);
    for (const auto& order : orders) {
        std::tm orderTm = {};
        std::istringstream orderSS(order.timestamp);
        orderSS >> std::get_time(&orderTm, "%Y/%m/%d %H:%M:%S");
        time_t orderTimestamp = mktime(&orderTm);
        if (difftime(currentTimestamp, orderTimestamp) <= 3600) { // 3600 seconds = 1 hour
            prices.push_back(order.price);
        }
    }
    return prices;
}
```

### Prompt 3: How did you test your function? Briefly describe any testing you did.

In addition to the original dataset (i.e., `20200307.csv`), I created small, controlled datasets with known values to test each function individually. For example, I tested getPriceAverage with a vector of prices where the expected average was easily calculable. Similarly, I tested getPriceStd with a dataset where I manually calculated the standard deviation to verify the function's output.
