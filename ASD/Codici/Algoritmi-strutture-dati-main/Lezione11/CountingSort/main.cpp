/*
    Counting Sort
*/

#include <iostream>
#include "CountingSort.h"
#include <vector>

using namespace std;

void countingSort (int *A, int lengthA){

    int max=A[0], min=A[0]; //Calcolo elementi max e min

    for(int i=1; i<lengthA; i++){

        if(A[i]>max) 
            max=A[i];
        else if(A[i]<min) 
            min=A[i];
    }

    int lengthC = max-min+1; //Costruzione dell'array
    int *C = new int[lengthC]; //crea l'array C

    for(int i=0; i<lengthC; i++)
        C[i]=0; //inizializza a zero gli elementi di C

    for(int i=0; i<lengthA; i++)
        C[ A[i]-min ]++;

    // aumenta il numero di volte che si è incontrato il valore
    // Ordinamento in base al contenuto dell'array delle frequenze
    int k=0; // indice per l'array A
    for (int i=0; i<lengthC; i++){

        //scrive C[i] volte il valore i+min nell'array A
        while ( C[i] > 0 ){
            A[k++] = i+min;
            C[i]--;
        }
    }
    delete[] C;
}

int main(){

    int numvar = 8;
    vector<int> vec = {100,20,40,20,12,120,220,240};
    vector<int> vecInvercse = {100,20,40,22,12,120,220,240};

    CountingSort::countingSort(&vec,numvar);
    CountingSort::countingSortInverse(&vecInvercse,numvar);

    for (auto i:vec)
        cout << i << " ";
    cout << endl;
    for (auto i:vecInvercse)
        cout << i << " ";

    return 0;
}