//
// Created by Elias Aggergaard Larsen on 20/11/2024.
//

#include "TimeUtil.h"

#include <chrono>

tm TimeUtil::getCurrentTime()
{
    auto now = std::chrono::system_clock::now();
    time_t tt = std::chrono::system_clock::to_time_t(now);
    auto localTM =  *localtime(&tt);
    localTM.tm_year += 1900;
    localTM.tm_mon++;
    return localTM;
}
