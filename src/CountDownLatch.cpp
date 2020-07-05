#include "CountDownLatch.h"

void CountDownLatch::wait() {
    guardMutexLock lock(m_lock);
    while (m_count > 0) {
        m_con.wait(m_lock);
    }
}

void CountDownLatch::countDown() {
    guardMutexLock lock(m_lock);

    m_count--;
    if (m_count == 0) {
        m_con.notify_all();
    }
}