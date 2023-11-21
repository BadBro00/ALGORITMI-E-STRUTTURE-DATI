/*
    Quick Sort
*/
#include "QuickSort.h"
#include <iostream>

int main(){

    int a[4] = {9,7,3,1};

    QuickSort::quickSort(a,0,3);

    for (auto i:a)
        std::cout << i << " ";

    std::cout << "Scambi: " << QuickSort::getCont() << std::endl;

    return 0;
}