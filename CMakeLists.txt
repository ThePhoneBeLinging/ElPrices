cmake_minimum_required(VERSION 3.28)
project(ElPrices)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG bb01c8db702fb41e5497aee9c0559ddf4bf13749)
FetchContent_MakeAvailable(cpr)

set(CMAKE_CXX_STANDARD 20)

add_executable(ElPrices main.cpp
        HTTPRequest.hpp
        PriceController.cpp
        PriceController.h
        )

target_link_libraries(ElPrices PRIVATE cpr::cpr)