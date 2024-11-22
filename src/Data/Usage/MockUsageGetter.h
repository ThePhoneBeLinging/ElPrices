//
// Created by Elias Aggergaard Larsen on 20/11/2024.
//

#ifndef MOCKUSAGEGETTER_H
#define MOCKUSAGEGETTER_H
#include <random>
#include <thread>


class MockUsageGetter
{
public:
    MockUsageGetter();
    ~MockUsageGetter();
private:
    void mockData();
    std::thread dataThread_;
    std::atomic_bool keepRunningBool_;
    // Variables for random wait-period generation.
    std::mt19937 mt_;
    std::uniform_real_distribution<double> dist_;
};



#endif //MOCKUSAGEGETTER_H
