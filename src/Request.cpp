#include "Request.h"

void Request::process() {
    lockGruad lock(m_lock);
    std::cout << "procesing...." << std::endl;
    printWIthLockHold();
}

void Request::print() {
    lockGruad lock(m_lock);
    printWIthLockHold();
}

void Request::printWIthLockHold() {
    std::cout << "print...." << std::endl;
}