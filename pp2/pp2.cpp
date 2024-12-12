
#include <iostream> 
#include "ThreadsPool.h"
#include<cmath>

using namespace std;

void Binet(uint32_t n)
{
    double f{ 0.0 };
    
    for (uint32_t i = 0; i < 10000; ++i)
    {
        double fff = (pow(((1 + sqrt(5)) / 2), n) - pow((1 - (1 + sqrt(5)) / 2), n)) / sqrt(5);

        for (uint32_t j = 0; j < 10000; ++j)
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
    uint32_t n = pool.GetThreads();
    if (n == 0) {
        printf("Number Threads = 0.The program will not be completed");
    }
    else {
        cout << "Number of Threads: " << pool.GetThreads() << endl;
        for (uint32_t i = 0; i < n; i++) {
            pool.passQ(Binet, i * 10);

        }
    }
    
}