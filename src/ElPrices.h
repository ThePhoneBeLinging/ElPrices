//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#ifndef ELPRICES_H
#define ELPRICES_H

#include <memory>

#include "../dependencies/EngineBase/src/include/EngineBase/EngineBase.h"
#include "Data/Pricing/PriceController.h"
#include "Data/Usage/UsageController.h"


class ElPrices
{
public:
    ElPrices();
private:
    std::unique_ptr<PriceController> priceController_;
    std::shared_ptr<UsageController> usageController_;
    std::shared_ptr<EngineBase> engineBase_;
};

#endif //ELPRICES_H
