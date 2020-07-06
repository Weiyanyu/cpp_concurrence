#ifndef CONDITION_H
#define CONDITION_H

#include "lock.h"

class Condition {
public:
    Condition(const MutexLock &mutex) : m_mutex(mutex) {
        pthread_cond_init(&m_con, nullptr);
    }

    ~Condition() {
        pthread_cond_destroy(&m_con);
    }

    void wait() {
        pthread_cond_wait(&m_con, m_mutex.getMutex());
    }

    void notify_one() {
        pthread_cond_signal(&m_con);
    }

    void notify_all() {
        pthread_cond_broadcast(&m_con);
    }

private:
    mutable MutexLock m_mutex;
    pthread_cond_t m_con;
};

#endif