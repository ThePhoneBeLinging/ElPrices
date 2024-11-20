//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#ifndef USAGECONTROLLER_H
#define USAGECONTROLLER_H
#include <mutex>


class UsageController
{
public:
    UsageController();
    void wattHourUsed();
    [[nodiscard]] double getUsage();
private:
    std::mutex mutex_;
    std::chrono::time_point<std::chrono::system_clock> lastWattHourUsed_;
    double averageWattSinceLastPing;
};



#endif //USAGECONTROLLER_H
