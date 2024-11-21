//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#include "Price.h"

#include <nlohmann/json.hpp>

Price::Price(int priceWithotFees, int fees) : priceWithoutFees_(priceWithotFees), fees_(fees)
{
}

nlohmann::json Price::toJSON()
{
    nlohmann::json object;
    object["PriceWithoutFees"] = priceWithoutFees_;
    object["Fees"] = fees_;
    return object;
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
