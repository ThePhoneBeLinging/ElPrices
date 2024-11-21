//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#include "ElPrices.h"

#include <iostream>
#include <thread>
#include "Data/Usage/MockUsageGetter.h"


void ElPrices::launch()
{
    engineBase_ = std::make_shared<EngineBase>();
    usageController_ = std::make_shared<UsageController>();
    engineBase_->getGraphicsLibrary()->loadTexture("../Resources/number1.png");
    currentPrice_ = std::make_shared<Text>("", 525,150,50);
    engineBase_->registerText(currentPrice_);
    priceController_ = std::make_unique<PriceController>();
    mockUsageGetter_ = std::make_unique<MockUsageGetter>();
    engineBase_->launch();
}

void ElPrices::wattHourUsed()
{
    std::cout << "Watt hour used" << std::endl;
    usageController_->wattHourUsed();
    std::cout << "Average usage: " + std::to_string(usageController_->getUsage()) << std::endl;
    currentPrice_->setText(std::to_string(usageController_->getUsage()));
}

