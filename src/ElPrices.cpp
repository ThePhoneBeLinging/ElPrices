//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#include "ElPrices.h"

#include <iostream>
#include <thread>


void ElPrices::launch()
{
    engineBase_ = std::make_shared<EngineBase>();
    engineBase_->registerUpdateFunction(update);
    //priceController_ = std::make_unique<PriceController>();
    usageController_ = std::make_shared<UsageController>();
    //std::cout << priceController_->getDateFromString("18.11.2024")->getPriceAtPoint(22)->getPriceWithFees() << std::endl;
    engineBase_->launch();
}

void ElPrices::update(float deltaTime)
{
    std::cout << "UPDATE" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
}
