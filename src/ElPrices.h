//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#ifndef ELPRICES_H
#define ELPRICES_H

#include "Data/Pricing/PriceController.h"
#include "Data/Usage/UsageController.h"


class ElPrices
{
public:
    ElPrices();
private:
    std::unique_ptr<PriceController> priceController_;
    std::shared_ptr<UsageController> usageController_;
};

#endif //ELPRICES_H
