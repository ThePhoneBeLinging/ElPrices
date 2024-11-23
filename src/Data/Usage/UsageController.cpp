//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#include "UsageController.h"

#include <utility>

#include "../TimeUtil.h"

UsageController::UsageController(std::shared_ptr<Text> text, std::shared_ptr<PriceController> priceController)
{
    lastWattHourUsed_ = std::chrono::system_clock::now();
    text_ = std::move(text);
    priceController_ = std::move(priceController);
}

void UsageController::wattHourUsed()
{
    auto currentTime = std::chrono::system_clock::now();
    auto milli = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastWattHourUsed_);
    int millisecondsToHours = 360000;
    double usedRigthNow = 1 / (static_cast<double>(milli.count()) / millisecondsToHours);
    auto currentTimeTM = TimeUtil::getCurrentTime();
    auto priceRightNow = priceController_->getDateFromString(TimeUtil::getCurrentTimeAsDateString())->getPriceAtPoint(currentTimeTM.tm_hour);
    // TODO Update to take price into account
    auto priceBasedOnUsage = usedRigthNow;
    text_->setText(std::to_string(priceBasedOnUsage));
    lastWattHourUsed_ = currentTime;
}