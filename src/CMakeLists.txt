cmake_minimum_required(VERSION 3.28)
project(ElPrices)

set(CMAKE_CXX_STANDARD 20)

add_executable(ElPrices main.cpp
        Data/PriceController.cpp
        Data/PriceController.h
        Data/Date.cpp
        Data/Date.h
        ElPrices.cpp
        ElPrices.h
        Data/CeriusPrices.cpp
        Data/CeriusPrices.h
)