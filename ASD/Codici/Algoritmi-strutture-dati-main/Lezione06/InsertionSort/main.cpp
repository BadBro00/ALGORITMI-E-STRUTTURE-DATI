/*
    Insertion Sort
*/

#include <iostream>
#include "InsertionSort.h"

using namespace std;

int main(){

    int numvar = 4;
    int ptr[numvar] = {128,2,28,18};

    InsertionSort::insertionSort(ptr,numvar);

    cout << endl << "Vettore ordinato" << endl; // Stampa del vettore ordinato
    for(int j=0; j <numvar; j++){
        cout << ptr[j] << endl;
    }

    return 0;
}