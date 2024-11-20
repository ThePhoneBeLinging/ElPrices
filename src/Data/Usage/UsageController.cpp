//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#include "UsageController.h"

UsageController::UsageController() : averageWattSinceLastPing(0)
{
}

void UsageController::wattHourUsed()
{
    std::lock_guard lock(mutex_);
    auto currentTime = std::chrono::system_clock::now();
    auto milli = std::chrono::duration_cast<std::chrono::milliseconds>(lastWattHourUsed_ - currentTime);
    int millisecondsToHours = 360000;
    averageWattSinceLastPing = 1.0 / static_cast<double>(milli.count() / millisecondsToHours);
    lastWattHourUsed_ = currentTime;
}

double UsageController::getUsage()
{
    std::lock_guard lock(mutex_);
    return averageWattSinceLastPing;
}
