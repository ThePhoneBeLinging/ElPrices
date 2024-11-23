//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#ifndef USAGECONTROLLER_H
#define USAGECONTROLLER_H
#include <mutex>
#include <EngineBase/Text.h>

#include "../Pricing/PriceController.h"


class UsageController
{
public:
    UsageController(std::shared_ptr<Text> text, std::shared_ptr<PriceController> priceController);
    void wattHourUsed();
private:
    std::shared_ptr<Text> text_;
    std::shared_ptr<PriceController> priceController_;
    std::chrono::time_point<std::chrono::system_clock> lastWattHourUsed_;
};



#endif //USAGECONTROLLER_H
