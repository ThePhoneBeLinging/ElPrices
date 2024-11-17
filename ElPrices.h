//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#ifndef ELPRICES_H
#define ELPRICES_H
#include <unordered_map>

#include "Date.h"
#include "PriceController.h"


class ElPrices
{
public:
    ElPrices();
private:
    PriceController priceController_;
};

#endif //ELPRICES_H
