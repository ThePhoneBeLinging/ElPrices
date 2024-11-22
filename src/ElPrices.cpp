//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#include "ElPrices.h"
#include <iostream>
#include "Data/Usage/MockUsageGetter.h"


ElPrices::ElPrices()
{
    engineBase_ = std::make_shared<EngineBase>();
    currentPrice_ = std::make_shared<Text>("", 525, 150, 50);
    usageController_ = std::make_shared<UsageController>(currentPrice_);
    engineBase_->registerText(currentPrice_);
    priceController_ = std::make_unique<PriceController>();
    mockUsageGetter_ = std::make_unique<MockUsageGetter>(usageController_);
    engineBase_->launch();
}
