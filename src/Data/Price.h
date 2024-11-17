//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#ifndef PRICE_H
#define PRICE_H



class Price
{
public:
    Price(int priceWithotFees, int fees);
    [[nodiscard]] int getPriceWithoutFees() const;
    [[nodiscard]] int getFees() const;
    [[nodiscard]] int getPriceWithFees() const;
private:
    int priceWithoutFees_;
    int fees_;
};



#endif //PRICE_H
