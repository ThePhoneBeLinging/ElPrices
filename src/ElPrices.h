//
// Created by Elias Aggergaard Larsen on 17/11/2024.
//

#ifndef ELPRICES_H
#define ELPRICES_H

#include "Data/PriceController.h"


class ElPrices
{
public:
    ElPrices();
private:
    std::unique_ptr<PriceController> priceController_;
};

#endif //ELPRICES_H
