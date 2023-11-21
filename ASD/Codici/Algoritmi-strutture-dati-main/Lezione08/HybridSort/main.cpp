/*
    Hybrid Sort
*/

#include <iostream>
#include "HybridSort.h"
#include <time.h>

// 10 -- Temp: 0.11337 -- Temp: 0.112823 -- Temp: 0.125896
// 15 -- Temp: 0.119364 -- Temp: 0.123548 -- Temp: 0.120179
// 20 -- Temp: 0.14449 -- Temp: 0.131449 -- Temp: 0.115412
// 25 -- Temp: 0.125207 -- Temp: 0.12031 -- Temp: 0.12405
// 30 -- Temp: 0.120479 -- Temp: 0.148182 -- Temp: 0.120727
// 1000 -- Temp: 0.128507 -- Temp: 0.124652 -- Temp: 0.128885
// 100000 -- Temp: 0.117393

int main(){

    clock_t start,end;
    double tempo;
    int n = 1000000;

    srand(1);
    srand ((unsigned)time(0));

    int a[n];

    for (int i=0; i<n; i++){
        a[i] = rand()%1000+1;
    }

    std::cout << "\nDisordinato\n";
    for (auto i: a)
        std::cout << i << " ";

    start=clock();
    HybridSort::hybridSort(a,0,n-1);
    end=clock();

    std::cout << "\nOrdinato\n";
    for (auto i: a)
        std::cout << i << " ";


    tempo=((double)(end-start))/CLOCKS_PER_SEC;

    std::cout << "Temp: " << tempo << std::endl;
 
    return 0;
}