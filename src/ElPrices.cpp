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
    int x = 250;
    for (int i = 0; i < 4; i++)
    {
        priceDrawAbles_.push_back(std::make_shared<DrawAble>());
        priceDrawAbles_.back()->setHeight(50);
        priceDrawAbles_.back()->setWidth(50);
        priceDrawAbles_.back()->setTextureIndex(2);

        priceDrawAbles_.back()->setX(x);
        priceDrawAbles_.back()->setY(250);
        engineBase_->registerDrawAble(priceDrawAbles_.back());
        x += 50;
    }
    //engineBase_->registerUpdateFunction(update);
    //priceController_ = std::make_unique<PriceController>();
    //std::cout << priceController_->getDateFromString("18.11.2024")->getPriceAtPoint(22)->getPriceWithFees() << std::endl;
    mockUsageGetter_ = std::make_unique<MockUsageGetter>();
    engineBase_->launch();
}

void ElPrices::wattHourUsed()
{
    std::cout << "Watt hour used" << std::endl;
    usageController_->wattHourUsed();
    std::cout << "Average usage: " + std::to_string(usageController_->getUsage()) << std::endl;
}

void ElPrices::update(float deltaTime)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "UPDATE" << std::endl;
}
