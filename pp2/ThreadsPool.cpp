#include "ThreadsPool.h"

threadsPool::threadsPool() {
    cntThreads = thread::hardware_concurrency();
    for (uint32_t i = 0; i <= cntThreads; i++) {
        threads.emplace_back(&threadsPool::run, this);
    }
}

threadsPool::~threadsPool() {
    stop = true;
    condition.notify_all();
    for (unsigned int i = 0; i <= cntThreads; i++) {
        if (threads[i].joinable())
            threads[i].join();
    }
}
unsigned int threadsPool::GetThreads() {
    return cntThreads;
}
void threadsPool::run() {
    Task task;
    while (true) {
        unique_lock<mutex>lk(m);
        condition.wait(lk, [this]() {return !q.empty() || stop; });
        if (!q.empty()) {

            task = q.front();

            q.pop();
            lk.unlock();

            task.func(task.x);
        }
        if (stop) {
            break;
        }
        
     
    }

}
void threadsPool::passQ(function<void(int)> f, int x) {
    {
        std::lock_guard<std::mutex> lg(m);
        q.push(Task{ f, x });
    }
    condition.notify_one(); 
}

