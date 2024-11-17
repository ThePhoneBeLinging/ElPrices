//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#ifndef CERIUSPRICES_H
#define CERIUSPRICES_H


enum TimePeriod
{
    LOWLOAD,
    HIGHLOAD,
    PEAKLOAD
};

enum Period
{
    SUMMER,
    WINTER
};

class CeriusPrices
{
public:
    CeriusPrices() = default;
    int getFeeAtTimePoint(int month, int timePoint);
private:
    int getTariffsFromPeriods(Period period, TimePeriod timePeriod);
    TimePeriod getCurrentTimePeriod(int timePoint);
    Period getCurentPeriod(int month);
};



#endif //CERIUSPRICES_H
