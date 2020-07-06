#ifndef LOCK_H
#define LOCK_H

#include <pthread.h>
#include <cassert>

#include <unistd.h>

class MutexLock {
public:
    MutexLock() : m_tid(0) {
        pthread_mutex_init(&m_mutex, nullptr);
    }

    ~MutexLock() {
        assert(m_tid == 0);
        pthread_mutex_destroy(&m_mutex);
    }

    bool isLockedByThisThread() {
        return m_tid == gettid();
    }

    void assertLocked() {
        assert(isLockedByThisThread());
    }

    void lock() {
        pthread_mutex_lock(&m_mutex);
        m_tid = gettid();
    }

    void unlock() {
        m_tid = 0;
        pthread_mutex_unlock(&m_mutex);
    }

    pthread_mutex_t* getMutex() {
        return &m_mutex;
    }

private:
    pthread_mutex_t m_mutex;
    pid_t m_tid;
};


class MutexLockGuard {
public:
    MutexLockGuard() = default;
    MutexLockGuard(const MutexLock &mutex) : m_mutex(mutex) {
        m_mutex.lock();
    }
    ~MutexLockGuard() {
        m_mutex.unlock();
    }
private:
    MutexLock m_mutex;
};

#endif