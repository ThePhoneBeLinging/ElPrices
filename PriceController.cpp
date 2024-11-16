//
// Created by Elias Aggergaard Larsen on 16/11/2024.
//

#include "PriceController.h"

int PriceController::getPriceAtPoint(int timePoint)
{
    if (timePoint < 0 || 23 < timePoint)
    {
        throw std::invalid_argument("TimePoint must be between 0 and 23, but is:" + timePoint);
    }
    return priceList_[timePoint];
}
