//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#include "UsageController.h"

UsageController::UsageController() : wattHoursUsed_(0)
{
}

int UsageController::getWattHoursUsed()
{
    std::lock_guard lock(mutex_);
    return wattHoursUsed_;
}

void UsageController::wattHourUsed()
{
    std::lock_guard lock(mutex_);
    wattHoursUsed_++;
}
