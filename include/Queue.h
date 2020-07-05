#ifndef QUEUE_H
#define QUEUE_H

#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/lock_guard.hpp>
#include <boost/thread/condition.hpp>

#include <deque>
#include <iostream>

class BlockingQueue {

public:
    typedef boost::lock_guard<boost::mutex> guardMutexLock;
    int dequeue();
    void enqueue(int x);

    bool isEmpty() {
        return queue.empty();
    }


private:
    mutable boost::mutex m_lock;
    boost::condition con;
    std::deque<int> queue;
};

#endif