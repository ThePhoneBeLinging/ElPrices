//
// Created by Elias Aggergaard Larsen on 16/11/2024.
//

#include "PriceController.h"

#include <iostream>

#include "cpr/api.h"
#include "cpr/response.h"

int PriceController::getPriceAtPoint(int timePoint)
{
    if (timePoint < 0 || 23 < timePoint)
    {
        throw std::invalid_argument("TimePoint must be between 0 and 23, but is:" + timePoint);
    }
    return priceList_[timePoint];
}

void PriceController::updatePriceList()
{
    std::string fromYear = "2024";
    std::string fromMonth = "10";
    std::string fromDay = "18";
    std::string toYear = "2024";
    std::string toMonth = "10";
    std::string toDay = "19";

    std::string dateFrom = fromYear + "-" + fromMonth + "-" + fromDay;
    std::string dateTo = toYear + "-" + toMonth + "-" + toDay;

    cpr::Response r = cpr::Get(cpr::Url{"https://andelenergi.dk/?obexport_format=csv&obexport_start=" + dateFrom+ "&obexport_end=" + dateTo + "&obexport_region=east&obexport_tax=0&obexport_product_id=1%231%23TIMEENERGI"});
    if (r.status_code != 200)
    {
        throw std::invalid_argument("Status code was not 200, it was: " + r.status_code);
    }
    std::cout << r.text << std::endl;
    parseData(r.text);
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
        if (first)
        {
            first = false;
            continue;
        }

        std::string dateString = priceLine[0];
        std::string priceWithoutTransportString = priceLine[1];
        std::string currentPriceOfTransportString = priceLine[2];
        std::string totalString = priceLine[3];

        std::cout << dateString << std::endl;
        std::cout << priceWithoutTransportString << std::endl;
        std::cout << currentPriceOfTransportString << std::endl;
        std::cout << totalString << std::endl;
    }
}
