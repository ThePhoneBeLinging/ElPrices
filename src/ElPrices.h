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
    static void update(float deltaTime);
private:
    static inline std::vector<std::shared_ptr<DrawAble>> priceDrawAbles_;
    static inline std::unique_ptr<PriceController> priceController_;
    static inline std::shared_ptr<UsageController> usageController_;
    static inline std::shared_ptr<EngineBase> engineBase_;
    static inline std::unique_ptr<MockUsageGetter> mockUsageGetter_;
};

#endif //ELPRICES_H
