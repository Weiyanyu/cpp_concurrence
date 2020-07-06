#include "CountDownLatch.h"

void CountDownLatch::wait() {
    MutexLockGuard lock(m_mutex);
    while (m_count > 0) {
        m_con.wait();
    }
}

void CountDownLatch::countDown() {
    MutexLockGuard lock(m_mutex);

    m_count--;
    if (m_count == 0) {
        m_con.notify_all();
    }
}