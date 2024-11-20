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
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 8.0);
    mt_ = mt;
    dist_ = dist;
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
        //TODO Does not quit gracefully because we might get stuck here.
        //But as this is for testing, i wont do anything for now
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(dist_(mt_) * 1000)));
        ElPrices::wattHourUsed();
    }
}
