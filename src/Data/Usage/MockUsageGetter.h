//
// Created by Elias Aggergaard Larsen on 20/11/2024.
//

#ifndef MOCKUSAGEGETTER_H
#define MOCKUSAGEGETTER_H
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
};



#endif //MOCKUSAGEGETTER_H
