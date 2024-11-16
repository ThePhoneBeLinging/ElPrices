#include <iostream>

#include "PriceController.h"
#include "cpr/api.h"
#include "cpr/auth.h"
#include "cpr/cprtypes.h"
#include "cpr/parameters.h"

int main()
{
    PriceController::updatePriceList();
    return 0;
}
