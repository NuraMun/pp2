
#include <iostream> 
#include "ThreadsPool.h"
#include<cmath>

using namespace std;

//void printOk() {
//    for (int i = 0; i < 5; i++) {
//        printf("Ok ");
//        this_thread::sleep_for(std::chrono::seconds(5)); 
//    }
//    
//}
//
//void printNumbers(int x, int y) {
//    for (int i = 0; i < 5; i++) {
//        printf("%i, %i\n", x,y);
//        this_thread::sleep_for(std::chrono::seconds(3)); 
//    }
//
//}


//Формула Бине для нахождения n-го члена последовательности Фибоначчи
//void FBinet(int n) {
//    double f = (pow(((1 + sqrt(5)) / 2), n) - pow((1 - (1 + sqrt(5)) / 2), n))/sqrt(5);
//    printf("Fibonachi value for %d element = %lf\n", n, f);
//}

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
    int n = pool.GetThreads();
    cout <<"Number Threads: " << pool.GetThreads() << endl;
    for (int i = 0; i < n; i++) {
        pool.passQ(Binet, i*10);
        
    }
    

}