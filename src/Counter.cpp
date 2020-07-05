#include "Counter.h"

int64_t Counter::value() const 
{
    return this->m_value;
}

int64_t Counter::getAndIncrease() {
    boost::mutex::scoped_lock lock(valueLock);
    this->m_value++;
    return this->m_value;
}