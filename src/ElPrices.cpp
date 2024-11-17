//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#include "ElPrices.h"

#include <iostream>


ElPrices::ElPrices()
{
    priceController_ = std::make_unique<PriceController>();
    usageController_ = std::make_shared<UsageController>();
    std::cout << priceController_->getDateFromString("18.11.2024")->getPriceAtPoint(22)->getPriceWithFees() << std::endl;
}
