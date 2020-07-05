#include "Observer.h"

void Observer::update() {
    std::cout << "update" << std::endl;
}

void Observable::registers(const std::weak_ptr<Observer> &ob) {
    observers.push_back(ob);
}

void Observable::notifyObservers() {
    boost::mutex::scoped_lock lock(m_lock);
    auto it = observers.begin();
    while (it != observers.end()) {
        auto obj = it->lock(); 
        if (obj) {
            obj->update();
            it++;
        } else {
            it = observers.erase(it);
        }
    }
    

}