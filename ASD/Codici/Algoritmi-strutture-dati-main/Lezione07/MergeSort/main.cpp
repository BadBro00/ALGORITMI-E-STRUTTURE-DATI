/*
    Merge Sort
*/
#include "MergeAstrattoSulPosto.h"
#include "MergeDueVie.h"
#include <iostream>

void visualizzaArray(int[],int);
int main() {

    const int n=4;
    int a[n] = {9,7,3,1};

    MergeAstrattoSulPosto::mergeSort(a,0,n-1);
    visualizzaArray(a,n);
    std::cout << "Contatore 'Scambi' Merge Sort: " << MergeAstrattoSulPosto::cont;

    int b[n] = {10,22,100,4};
    MergeDueVie::mergeSort(b,0,n-1);
    visualizzaArray(b,n);

    int c[n] = {120,20,26,18};
    MergeDueVie::mergeSortRic(c,0,n-1);
    visualizzaArray(c,n);

    return 0;
}

void visualizzaArray(int a[],int n){
    std::cout << std::endl;
    for (int i=0; i<n; i++)
        std::cout << "Array[" << i << "]: " << a[i] << std::endl;
}