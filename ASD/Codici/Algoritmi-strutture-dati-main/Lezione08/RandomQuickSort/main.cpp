/*
    Random Quick Sort con conteggio del tempo di esecuzione
*/
#include "RandomQuickSort.h"
#include <iostream>
#include <time.h>

int main(){

    clock_t start,end;
    double tempo;
    start=clock();
    

    int a[4] = {9,7,3,1};

    RandomQuickSort::randomQuickSort(a,0,3);

    for (auto i:a)
        std::cout << i << " ";

    end=clock();
    tempo=((double)(end-start))/CLOCKS_PER_SEC;

    std::cout << "Temp: " << tempo << std::endl;

    return 0;
}