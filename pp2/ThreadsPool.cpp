#include "ThreadsPool.h"

threadsPool::threadsPool() {
    cntThreads = thread::hardware_concurrency();
    for (unsigned int i = 0; i <= cntThreads; i++) {
        //thread th(&threadsPool::run, this);
        threads.emplace_back(&threadsPool::run, this);
    }
    lock_guard<mutex> M(m);
}

threadsPool::~threadsPool() {
    for (unsigned int i = 0; i <= cntThreads; i++) {
        if (threads[i].joinable())
            threads[i].join();
    }
    unique_lock<std::mutex> M1(m);
}
unsigned int threadsPool::GetThreads() {
    return thread::hardware_concurrency();
}
void threadsPool::run() {
    Task task;
    while (true) {
        unique_lock<mutex>lk(m);
        condition.wait(lk, [this]() {return !q.empty(); });
         task = q.front();

        q.pop();
        lk.unlock();

        task.func(task.x);
     
    }
}
void threadsPool::passQ(function<void(int)> f, int x) {
    
    std::lock_guard<std::mutex> lg(m);
    
    q.push(Task{f, x});
    condition.notify_one(); 
}
//void threadsPool::passQ(function<void()> f)
//{
//    std::lock_guard<std::mutex>lg(m);
//    q.push(f);
//    condition.notify_one();
//}
