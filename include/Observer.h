#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
#include <iostream>
#include <memory>
#include "boost/thread/mutex.hpp"

class Observable;

class Observer {
public:
    Observer() = default;
    // Observer(Observable* s);

    virtual ~Observer() = default;
    virtual void update() = 0;
};

class Observable {
public:
    void registers(const std::weak_ptr<Observer> &ob);
    
    void notifyObservers();

private:
    mutable boost::mutex m_lock;
    std::vector<std::weak_ptr<Observer>> observers;
};

#endif