//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#include "CeriusPrices.h"

#include <stdexcept>

int CeriusPrices::getFeeAtTimePoint(int month,int timePoint)
{
    // Ratio is 10000 -> 1kr
    int totalFees = 0;
    int electricityFee = 9513;
    totalFees += electricityFee;

    totalFees += getTariffsFromPeriods(getCurentPeriod(month),getCurrentTimePeriod(timePoint));

    return totalFees;
}

int CeriusPrices::getTariffsFromPeriods(Period period, TimePeriod timePeriod)
{
    if (period == WINTER)
    {
        switch (timePeriod)
        {
            case LOWLOAD: return 1388;
            case HIGHLOAD: return 4164;
            case PEAKLOAD: return 12491;
        }
    }

    if (period == SUMMER)
    {
        switch (timePeriod)
        {
            case LOWLOAD: return 1388;
            case HIGHLOAD: return 2082;
            case PEAKLOAD: return 5413;
        }
    }
    throw std::invalid_argument("getTariffsFromPeriods recieved invalid args: " + period + timePeriod);
}

TimePeriod CeriusPrices::getCurrentTimePeriod(int timePoint)
{
    if (timePoint < 6)
    {
        return LOWLOAD;
    }
    if (timePoint < 17)
    {
        return HIGHLOAD;
    }
    if (timePoint < 21)
    {
        return PEAKLOAD;
    }
    if (timePoint < 24)
    {
        return HIGHLOAD;
    }
    throw std::invalid_argument("Time point was not valid" + timePoint);
}


Period CeriusPrices::getCurentPeriod(int month)
{
    if (month < 4 || 10 < month)
    {
        return WINTER;
    }
    if (4 < month && month < 10)
    {
        return SUMMER;
    }
    throw std::invalid_argument("Month was not valid: " + month);
}
