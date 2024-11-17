//
// Created by Elias Aggergaard Larsen on 16/11/2024.
//

#ifndef DATE_H
#define DATE_H
#include <string>
#include <vector>


class Date
{
public:
    explicit Date(const std::string& dateString);
    [[nodiscard]] int getYear() const;
    void setYear(int year);
    [[nodiscard]] int getMonth() const;
    void setMonth(int month);
    [[nodiscard]] int getDay() const;
    void setDay(int day);
    void setPriceAtPoint(int time, int price);
    int getPriceAtPoint(int time);

    bool operator==(const Date&) const;

private:
    int year_;
    int month_;
    int day_;
    std::vector<int> priceList_;
};



#endif //DATE_H
