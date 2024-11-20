//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#include "UsageController.h"

UsageController::UsageController() : averageWattSinceLastPing(0)
{
}

void UsageController::wattHourUsed()
{
    auto currentTime = std::chrono::system_clock::now();
    auto milli = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastWattHourUsed_);
    int millisecondsToHours = 360000;
    averageWattSinceLastPing = 1 / (static_cast<double>(milli.count()) / millisecondsToHours);
    lastWattHourUsed_ = currentTime;
}

double UsageController::getUsage()
{
    return averageWattSinceLastPing;
}
