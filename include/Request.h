#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
#include "boost/thread/mutex.hpp"
#include "boost/thread/lock_guard.hpp"


class Request {
public:
    typedef boost::mutex CMutex;
    typedef boost::lock_guard<CMutex> lockGruad;


    void process();

    void print();

private:
    void printWIthLockHold();

private:
    mutable boost::mutex m_lock;
};

#endif