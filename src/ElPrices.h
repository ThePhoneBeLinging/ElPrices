//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#ifndef ELPRICES_H
#define ELPRICES_H

#include <memory>
#include "EngineBase/EngineBase.h"
#include "Data/Pricing/PriceController.h"
#include "Data/Usage/MockUsageGetter.h"
#include "Data/Usage/UsageController.h"


class ElPrices
{
public:
    ElPrices();
private:
    std::shared_ptr<Text> currentPrice_;
    std::unique_ptr<PriceController> priceController_;
    std::shared_ptr<UsageController> usageController_;
    std::shared_ptr<EngineBase> engineBase_;
    std::unique_ptr<MockUsageGetter> mockUsageGetter_;
};

#endif //ELPRICES_H
