#ifndef COUNTDOWNLATCH_H
#define COUNTDOWNLATCH_H

#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/lock_guard.hpp>
#include <boost/thread/condition.hpp>

#include <iostream>

class CountDownLatch {
public:
    //type def
    typedef boost::lock_guard<boost::mutex> guardMutexLock;


    CountDownLatch() = default;
    explicit CountDownLatch(int count) : m_count(count) {}
    void wait();
    void countDown();
private:
    mutable boost::mutex m_lock;
    boost::condition m_con;
    int m_count;
};

#endif