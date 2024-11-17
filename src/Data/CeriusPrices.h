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
    static int getFeeAtTimePoint(int month, int timePoint);
private:
    static int getTariffsFromPeriods(Period period, TimePeriod timePeriod);
    static TimePeriod getCurrentTimePeriod(int timePoint);
    static Period getCurentPeriod(int month);
};



#endif //CERIUSPRICES_H
