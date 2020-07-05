#include "Queue.h"

int BlockingQueue::dequeue() {
    guardMutexLock lock(m_lock);

    while (queue.empty()) {
        std::cout << "dequeue blocking..." << std::endl;
        con.wait(m_lock);
    }

    assert(!queue.empty());
    int res = queue.front();
    queue.pop_front();
    return res;
}

void BlockingQueue::enqueue(int x) {
    guardMutexLock lock(m_lock);
    queue.push_back(x);
    con.notify_one();
}