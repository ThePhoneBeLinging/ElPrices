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
    int getWattHoursUsed();
    void wattHourUsed();
private:
    std::mutex mutex_;
    int wattHoursUsed_;
};



#endif //USAGECONTROLLER_H
