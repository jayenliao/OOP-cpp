#include "OrderBookEntry.h"

OrderBookEntry::OrderBookEntry(
            string timestamp,
            string product,
            OrderBookType orderType,
            double price,
            double amount
        )
    : timestamp(timestamp), product(product), orderType(orderType), price(price), amount(amount)
{

}
