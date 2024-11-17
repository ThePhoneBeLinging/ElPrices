//
// Created by Elias Aggergaard Larsen on 16/11/2024.
//

#include "PriceController.h"

#include <iostream>

#include "cpr/api.h"
#include "cpr/response.h"

PriceController::PriceController()
{
}

std::shared_ptr<Date> PriceController::getDateFromString(const std::string& dateString)
{
    return datesMap_[dateString];
}

void PriceController::updatePriceList()
{
    auto now = std::chrono::system_clock::now();
    time_t tt = std::chrono::system_clock::to_time_t(now);
    tm local_tm = *localtime(&tt);

    std::string fromYear = std::to_string(local_tm.tm_year + 1900);
    std::string fromMonth = std::to_string(local_tm.tm_mon + 1);
    std::string fromDay = std::to_string(local_tm.tm_mday);


    std::string toYear = "2024";
    std::string toMonth = "11";
    std::string toDay = "17";

    std::string dateFrom = fromYear + "-" + fromMonth + "-" + fromDay;
    std::string dateTo = toYear + "-" + toMonth + "-" + toDay;
    cpr::Response r = cpr::Get(cpr::Url{"https://andelenergi.dk/?obexport_format=csv&obexport_start=" + dateFrom+ "&obexport_end=" + dateFrom + "&obexport_region=east&obexport_tax=0&obexport_product_id=1%231%23TIMEENERGI"});
    if (r.status_code != 200)
    {
        throw std::invalid_argument("Status code was not 200, it was: " + r.status_code);
    }
    parseData(r.text);
}

int PriceController::parsePriceToInt(const std::string& string)
{
    std::string newString = string;
    std::erase(newString,',');
    int integer = std::stoi(newString);
    return integer * 100;
}

int PriceController::getTimeFromDateString(const std::string& dateString)
{
    std::string newString = dateString.substr(13,2);
    return std::stoi(newString);
}

void PriceController::parseData(const std::string& data)
{
    // Split by \n, then by "
    std::string parsedString;
    std::string innerParsedString;
    std::stringstream stringStream(data);
    std::vector<std::vector<std::string>> matrixStrings;

    while (getline(stringStream,parsedString,'\n'))
    {
        std::vector<std::string> stringList;
        std::stringstream innerStringStream(parsedString);

        while (getline(innerStringStream,innerParsedString,'"'))
        {
            if (innerParsedString.empty() || innerParsedString == ",")
            {
                continue;
            }
            stringList.push_back(innerParsedString);
        }
        matrixStrings.push_back(stringList);
    }

    bool first = true;
    for (auto priceLine : matrixStrings)
    {
        // We skip the first line that describes the csv format.
        if (first)
        {
            first = false;
            continue;
        }
        std::string fullDateString = priceLine[0];
        std::string dateString = fullDateString.substr(0,10);
        std::string priceWithoutTransportString = priceLine[1];
        std::string currentPriceOfTransportString = priceLine[2];
        std::string totalString = priceLine[3];

        if (not datesMap_.contains(dateString))
        {
            auto date = std::make_shared<Date>(dateString);
            datesMap_[dateString] = date;
        }
        else
        {
            int timeInHour = getTimeFromDateString(fullDateString);
            int priceWithoutFees = parsePriceToInt(priceWithoutTransportString);
            int fees = CeriusPrices::getFeeAtTimePoint(datesMap_[dateString]->getMonth(),timeInHour);
            auto price = std::make_shared<Price>(priceWithoutFees,fees);
            datesMap_[dateString]->setPriceAtPoint(std::move(price),timeInHour);
        }
    }
}
