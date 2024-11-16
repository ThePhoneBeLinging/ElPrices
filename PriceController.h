//
// Created by Elias Aggergaard Larsen on 16/11/2024.
//

#ifndef PRICECONTROLLER_H
#define PRICECONTROLLER_H
#include <vector>


class PriceController
{
public:
    static int getPriceAtPoint(int timePoint);
private:
    static inline std::vector<int> priceList_;
};



#endif //PRICECONTROLLER_H
