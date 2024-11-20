//
// Created by Elias Aggergaard Larsen on 20/11/2024.
//

#include "MockUsageGetter.h"

#include <iostream>
#include <thread>

#include "../../ElPrices.h"

MockUsageGetter::MockUsageGetter()
{
    keepRunningBool_ = true;
    dataThread_ = std::thread(&MockUsageGetter::mockData,this);
}

MockUsageGetter::~MockUsageGetter()
{
    keepRunningBool_ = false;
    dataThread_.join();
}

void MockUsageGetter::mockData()
{
    while (keepRunningBool_)
    {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        ElPrices::wattHourUsed();
    }
}
