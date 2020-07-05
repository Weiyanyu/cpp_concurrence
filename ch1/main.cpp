#include <iostream>
#include <memory>
#include "boost/thread/thread.hpp"
#include <algorithm>


#include "Counter.h"

void count1();

Counter counter;

int main() {
    
    boost::thread th1(&count1);
    boost::thread th2(&count1);
    th1.join();
    th2.join();

    std::cout << counter.value() << std::endl;
}

void count1() {
    for (int i = 0; i < 100000; i++) {
        counter.getAndIncrease();
    }
}


