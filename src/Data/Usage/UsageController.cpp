//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#include "UsageController.h"

#include <utility>

UsageController::UsageController(std::shared_ptr<Text> text)
{
    lastWattHourUsed_ = std::chrono::system_clock::now();
    text_ = std::move(text);
}

void UsageController::wattHourUsed()
{
    auto currentTime = std::chrono::system_clock::now();
    auto milli = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastWattHourUsed_);
    int millisecondsToHours = 360000;
    text_->setText(std::to_string(1 / (static_cast<double>(milli.count()) / millisecondsToHours)));
    lastWattHourUsed_ = currentTime;
}