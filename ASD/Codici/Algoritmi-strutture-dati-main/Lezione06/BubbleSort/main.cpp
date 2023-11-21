/*
    Implementazione del Bubble Sort
*/
#include <vector>
#include <iostream>
#include "BubbleSort.h"

void visualizzaVec(std::vector<int> vec){
    for (int i: vec)
        std::cout << i << " ";
}

void visualizzaArray(int a[], int n){
    for (int i=0; i<n; i++)
        std::cout << a[i] << " ";
}

int main(){

    int a[] = {230,2,6,7,123,56,200};

    BubbleSort::bubble(a,0,6);
    visualizzaArray(a,7);
    std::cout << "\nCont: " << BubbleSort::getCont();

    return 0;
}