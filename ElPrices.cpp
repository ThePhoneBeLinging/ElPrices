//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#include "ElPrices.h"

#include <iostream>

ElPrices::ElPrices()
{
    priceController_ = PriceController();
    priceController_.updatePriceList();
    std::cout << priceController_.getDateFromString("16.11.2024")->getPriceAtPoint(11) << std::endl;
}
