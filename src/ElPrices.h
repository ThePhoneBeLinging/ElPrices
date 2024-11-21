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
    static void launch();
    static void wattHourUsed();
private:
    static inline std::shared_ptr<Text> currentPrice_;
    static inline std::unique_ptr<PriceController> priceController_;
    static inline std::shared_ptr<UsageController> usageController_;
    static inline std::shared_ptr<EngineBase> engineBase_;
    static inline std::unique_ptr<MockUsageGetter> mockUsageGetter_;
};

#endif //ELPRICES_H
