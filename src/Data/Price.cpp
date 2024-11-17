//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#include "Price.h"

Price::Price(int priceWithotFees, int fees) : priceWithoutFees_(priceWithotFees), fees_(fees)
{
}

int Price::getPriceWithoutFees() const
{
    return priceWithoutFees_;
}

int Price::getFees() const
{
    return fees_;
}

int Price::getPriceWithFees() const
{
    return priceWithoutFees_ + fees_;
}
