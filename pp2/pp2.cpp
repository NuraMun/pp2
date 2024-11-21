
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
void Binet(int n) {
    double f = (pow(((1 + sqrt(5)) / 2), n) - pow((1 - (1 + sqrt(5)) / 2), n))/sqrt(5);
    cout << f << endl;
}
int main()
{
    threadsPool pool;
    int n = pool.GetThreads();
    cout <<"Number Threads: " << pool.GetThreads() << endl;
    for (int i = 0; i < n; i++) {
        pool.passQ(Binet, i);
        
    }
   

}