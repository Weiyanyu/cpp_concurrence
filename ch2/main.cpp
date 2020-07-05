#include <iostream>
#include "boost/thread/mutex.hpp"
#include "boost/thread/thread.hpp"
#include <memory>

#include "Request.h"
#include "Queue.h"
#include "CountDownLatch.h"

using namespace std;

void testQueue();
void testCountDownLatch();


int main() {
    testCountDownLatch();

}

void testQueue() {
    BlockingQueue queue;
    shared_ptr<boost::thread> th1Sp = make_shared<boost::thread>([&](){
        for (int i = 0; i < 10000; i++) {
            queue.enqueue(i);
        }
    });

    shared_ptr<boost::thread> th2Sp = make_shared<boost::thread>([&](){
        for (int i = 0; i < 10000; i++) {
            queue.dequeue();
        }
    });

    th1Sp->join();
    th2Sp->join();

    assert(queue.isEmpty() == true);
}

void testCountDownLatch() {
    CountDownLatch latch(3);
    shared_ptr<boost::thread> th1Sp = make_shared<boost::thread>([&](){
        pid_t tid = gettid();
        sleep(2);
        latch.countDown();
        std::cout << "thread : " << tid << " ready go..." << std::endl;
    });

    shared_ptr<boost::thread> th2Sp = make_shared<boost::thread>([&](){
        pid_t tid = gettid();
        sleep(1);
        latch.countDown();
        std::cout << "thread : " << tid << " ready go..." << std::endl;
    });

    shared_ptr<boost::thread> th3Sp = make_shared<boost::thread>([&](){
        pid_t tid = gettid();
        sleep(3);
        latch.countDown();
        std::cout << "thread : " << tid << " ready go..." << std::endl;
    });

    std::cout << "main thread wait all sub thread finish......" << std::endl;
    latch.wait();
    std::cout << "all sub thread ready. go!!!" << std::endl;

    
}





