//
// Created by Elias Aggergaard Larsen on 16/11/2024.
//

#include "Date.h"

#include <iostream>
#include <sstream>

#include "CeriusPrices.h"

Date::Date(const std::string& dateString)
{
    std::stringstream stream(dateString);
    std::string parsedString;
    std::vector<std::string> strings;
    while (getline(stream,parsedString,'.'))
    {
        strings.push_back(parsedString);
    }
    strings[2] = strings[2].substr(0,4);
    year_ = std::stoi(strings[2]);
    month_ = std::stoi(strings[1]);
    day_ = std::stoi(strings[0]);
    priceList_.reserve(23);
    ceriusPrices_ = CeriusPrices();
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

void Date::setPriceAtPoint(int time, int price)
{
    if (time < 0 || 23 < time)
    {
        throw std::invalid_argument("Time must be between 0 and 23 but was: " + time);
    }
    price += ceriusPrices_.getFeeAtTimePoint(month_,time);
    priceList_[time] = price;
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
