//
// Created by Elias Aggergaard Larsen on 16/11/2024.
//

#ifndef PRICECONTROLLER_H
#define PRICECONTROLLER_H
#include <vector>
#include "Date.h"


class PriceController
{
public:
    static int getPriceAtPoint(int timePoint);
    static void updatePriceList();
private:
    static int parsePriceToInt(std::string& string);
    static void parseData(const std::string& data);
    static inline std::vector<std::unique_ptr<Date>> dates_;
};



#endif //PRICECONTROLLER_H
