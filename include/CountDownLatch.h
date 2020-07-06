#ifndef COUNTDOWNLATCH_H
#define COUNTDOWNLATCH_H

#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/lock_guard.hpp>
#include <boost/thread/condition.hpp>

#include <iostream>
#include "lock.h"
#include "condition.h"

class CountDownLatch {
public:
    //这里由于m_con只能在这里初始化，且初始化需要用到mutex,所以其顺序必须和成员变量生命顺序完全一致
    //原因是类的成员变量内存布局是根据变量声明顺序来决定的
    CountDownLatch(): m_mutex(), m_con(m_mutex) {};
    explicit CountDownLatch(int count) : m_mutex(), m_con(m_mutex),m_count(count) {
        
    }
    void wait();
    void countDown();
private:
    MutexLock m_mutex;
    Condition m_con;
    int m_count;
};

#endif