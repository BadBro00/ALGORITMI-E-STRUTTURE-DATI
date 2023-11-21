/*
    Esercizio

    • Progettare ed implementare una procedura quicksort
    iterativa
    • Usare lo stack illustrato nella lezione 4
*/

#include "QuickSortIterativo.h"
#include <iostream>

int main(){

    int a[4] = {9,7,3,1};

    QuickSortIterativo::quickSort(a,0,3);

    for (auto i:a)
        std::cout << i << " ";

    return 0;
}