/*
    • Progettare ed implementare una procedura Merge
      ricorsiva
*/
#include <iostream>
#include "MergeRicorsivo.h"

int main(){

    const int n=4;
    int a[n] = {9,7,3,1};

    MergeDueVie::mergeSortRic(a,0,n-1);

    for (int i=0; i<n; i++)
        std::cout << "A: " << a[i] << std::endl;

    return 0;
}