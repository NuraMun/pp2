#pragma once

#include <iostream>
#include <vector>
#include <future>
#include <thread>
#include <queue>
#include <functional>

using namespace std;

struct Task {
    function<void(int)> func; 
    int x;
    Task() {
        x = 0;
    }
    Task(function<void(int)> &func_, int& x_) {
        x = x_;
        func = func_;
    }
 
};

class threadsPool {
private:
    vector <thread> threads;
    unsigned int cntThreads;
    queue<Task> q;
    bool stop = false;
    std::mutex m;
    std::condition_variable condition;

public:
    unsigned int GetThreads();
    threadsPool();
    ~threadsPool();
    void run();
    void passQ(function<void(int)> f, int x);
};
