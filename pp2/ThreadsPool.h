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
    //int y;
};

class threadsPool {
private:
    vector <thread> threads;
    unsigned int cntThreads;
   // queue <function <void()>> q;
    queue<Task> q;

    std::mutex m;
    std::condition_variable condition;

public:
    unsigned int GetThreads();
    threadsPool();
    ~threadsPool();
    void run();
   // void passQ(function<void()> f);
    void passQ(function<void(int)> f, int x);
};
