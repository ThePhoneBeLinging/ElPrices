//
// Created by Elias Aggergaard Larsen on 16/11/2024.
//

#ifndef PRICECONTROLLER_H
#define PRICECONTROLLER_H
#include <unordered_map>
#include <vector>
#include <string>

#include "CeriusPrices.h"
#include "Date.h"


class PriceController
{
public:
    PriceController();
    std::shared_ptr<Date> getDateFromString(const std::string& dateString);
    void updatePriceList();
private:
    static int parsePriceToInt(const std::string& string);
    static int getTimeFromDateString(const std::string& dateString);
    void parseData(const std::string& data);
    std::unordered_map<std::string,std::shared_ptr<Date>> datesMap_;
};



#endif //PRICECONTROLLER_H
