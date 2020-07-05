#ifndef COUNTER_H
#define COUNTER_H

#include "boost/thread/mutex.hpp"

class Counter {
public:
    Counter() = default;
    int64_t value() const;
    int64_t getAndIncrease();

private:
    int64_t m_value;
    mutable boost::mutex valueLock;
};

#endif