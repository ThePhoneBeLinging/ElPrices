//
// Created by Elias Aggergaard Larsen on 20/11/2024.
//

#include "MockUsageGetter.h"

#include <iostream>
#include <thread>

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
        std::cout << "DEAN" << std::endl;
    }
}
