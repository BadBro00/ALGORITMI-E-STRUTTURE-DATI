#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include <vector>

using namespace std;

class CountingSort{
    public:
        static void countingSort(vector<int>*,int);
        static void countingSortInverse(vector<int>*,int);
};

void CountingSort::countingSort(vector<int>* vec, int n){

    int max = vec->at(0);
    int min = vec->at(0);

    for(int i=1; i<n; i++){

        if( vec->at(i) > max ) 
            max = vec->at(i);
        else if( vec->at(i) < min ) 
            min = vec->at(i);
    }

    int lengthC = max-min+1; //Costruzione dell'array
    int *C = new int[lengthC]; //crea l'array C

    for(int i=0; i<lengthC; i++)
        C[i]=0; //inizializza a zero gli elementi di C

    for(int i=0; i<n; i++)
        C[ vec->at(i)-min ]++;

    // aumenta il numero di volte che si è incontrato il valore
    // Ordinamento in base al contenuto dell'array delle frequenze
    int k=0; // indice per l'array A
    for (int i=0; i<lengthC; i++){

        //scrive C[i] volte il valore i+min nell'array A
        while ( C[i] > 0 ){
            vec->at(k++) = i+min;
            C[i]--;
        }
    }
    delete[] C;
}

void CountingSort::countingSortInverse(vector<int>* vec, int n){

    int max = vec->at(0);
    int min = vec->at(0);

    for(int i=1; i<n; i++){

        if( vec->at(i) > max ) 
            max = vec->at(i);
        else if( vec->at(i) < min ) 
            min = vec->at(i);
    }

    int lengthC = max-min+1; //Costruzione dell'array
    int *C = new int[lengthC]; //crea l'array C

    for(int i=0; i<lengthC; i++)
        C[i]=0; //inizializza a zero gli elementi di C

    for(int i=0; i<n; i++)
        C[ vec->at(i)-min ]++;

    // aumenta il numero di volte che si è incontrato il valore
    // Ordinamento in base al contenuto dell'array delle frequenze
    int k=n-1; // indice per l'array A
    for (int i=0; i<lengthC; i++){

        //scrive C[i] volte il valore i+min nell'array A
        while ( C[i] > 0 ){
            vec->at(k--) = i+min;
            C[i]--;
        }
    }
    delete[] C;
}

#endif // COUNTINGSORT_H