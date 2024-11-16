//
// Created by Elias Aggergaard Larsen on 16/11/2024.
//

#include "Date.h"

Date::Date(int year, int month, int day, std::vector<int>& prices)
{
    year_ = year;
    month_ = month;
    day_ = day;
    priceList_ = prices;
}

int Date::getYear() const
{
    return year_;
}

void Date::setYear(int year)
{
    this->year_ = year;
}

int Date::getMonth() const
{
    return month_;
}

void Date::setMonth(int month)
{
    this->month_ = month;
}

int Date::getDay() const
{
    return day_;
}

void Date::setDay(int day)
{
    this->day_ = day;
}

int Date::getPriceAtPoint(int time)
{
    if (time < 0 || 23 < time)
    {
        throw std::invalid_argument("Time must be between 0 and 23 but was: " + time);
    }
    return priceList_[time];
}

bool Date::operator==(const Date& otherDate) const
{
    bool result = true;

    result &= this->day_ == otherDate.day_;
    result &= this->month_ == otherDate.month_;
    result &= this->year_ == otherDate.year_;

    return result;
}
