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
    //int y;
};

class threadsPool {
private:
    vector <thread> threads;
    size_t cntThreads = thread::hardware_concurrency();;
   // queue <function <void()>> q;
    queue<Task> q;

    std::mutex m;
    std::condition_variable condition;

public:
    int GetThreads();
    threadsPool();
    ~threadsPool();
    void run();
   // void passQ(function<void()> f);
    void passQ(function<void(int)> f, int x);
};
