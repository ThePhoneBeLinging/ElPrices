cmake_minimum_required(VERSION 3.28)
project(ElPrices)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG bb01c8db702fb41e5497aee9c0559ddf4bf13749)
FetchContent_MakeAvailable(cpr)


include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)


set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)
add_subdirectory(dependencies/Utility)
add_subdirectory(dependencies/EngineBase)

target_link_libraries(ElPrices PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(ElPrices PRIVATE cpr::cpr)