//
// Created by Elias Aggergaard Larsen on 20/11/2024.
//

#include "TimeUtil.h"

#include <chrono>

tm TimeUtil::getCurrentTime()
{
    auto now = std::chrono::system_clock::now();
    return timeToTM(now);
}

tm TimeUtil::getTommorowTime()
{
    auto now = std::chrono::system_clock::now();
    now += std::chrono::hours(24);
    return timeToTM(now);
}

tm TimeUtil::timeToTM(const std::chrono::time_point<std::chrono::system_clock> time)
{
    time_t tt = std::chrono::system_clock::to_time_t(time);
    auto localTM =  *localtime(&tt);
    localTM.tm_year += 1900;
    localTM.tm_mon++;
    return localTM;
}
