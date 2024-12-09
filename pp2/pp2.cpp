﻿
#include <iostream> 
#include "ThreadsPool.h"
#include<cmath>

using namespace std;

void Binet(int n)
{
    double f{ 0.0 };
    
    for (size_t i = 0; i < 10000; ++i)
    {
        double fff = (pow(((1 + sqrt(5)) / 2), n) - pow((1 - (1 + sqrt(5)) / 2), n)) / sqrt(5);

        for (size_t j = 0; j < 10000; ++j)
        {
            fff = sqrt(fff * fff);
        }
        f += fff;
    }
    f = (round)(f / 10000.0);
    printf("Fibonachi value for %d element = %lf\n", n, f);
}

int main()
{
    threadsPool pool;
    unsigned int n = pool.GetThreads();
    if (n == 0) {
        printf("Number Threads = 0.The program will not be completed");
    }
    else {
        cout << "Number of Threads: " << pool.GetThreads() << endl;
        for (unsigned int i = 0; i < n; i++) {
            pool.passQ(Binet, i * 10);

        }
    }
    
}