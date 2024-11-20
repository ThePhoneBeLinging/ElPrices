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
    mockUsageGetter_ = std::make_unique<MockUsageGetter>();
    //engineBase_->registerUpdateFunction(update);
    //priceController_ = std::make_unique<PriceController>();
    usageController_ = std::make_shared<UsageController>();
    //std::cout << priceController_->getDateFromString("18.11.2024")->getPriceAtPoint(22)->getPriceWithFees() << std::endl;
    engineBase_->launch();
}

void ElPrices::update(float deltaTime)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "UPDATE" << std::endl;
}
