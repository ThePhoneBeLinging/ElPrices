cmake_minimum_required(VERSION 3.28)
project(ElPrices)

set(CMAKE_CXX_STANDARD 20)

add_executable(ElPrices main.cpp
        Data/Pricing/PriceController.cpp
        Data/Pricing/PriceController.h
        Data/Pricing/Date.cpp
        Data/Pricing/Date.h
        ElPrices.cpp
        ElPrices.h
        Data/Pricing/CeriusPrices.cpp
        Data/Pricing/CeriusPrices.h
        Data/Pricing/Price.cpp
        Data/Pricing/Price.h
        Data/Usage/UsageController.cpp
        Data/Usage/UsageController.h
)