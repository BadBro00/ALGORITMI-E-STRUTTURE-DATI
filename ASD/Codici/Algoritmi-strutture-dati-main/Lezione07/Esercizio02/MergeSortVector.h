
#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include <iostream>

using namespace std;

class MergeSortVector{
    private:
        template <typename T> static void merge(typename vector<T>::iterator, typename vector<T>::iterator, typename vector<T>::iterator);
    public:
        template <typename T> static void mergeSortVec(typename vector<T>::iterator, typename vector<T>::iterator);
};

template <typename T>
void MergeSortVector::mergeSortVec(typename vector<T>::iterator low, typename vector<T>::iterator high){
    
    // distance ritorna la distanza tra i due iteratori
    // che riceve in input, quini il size
    auto size = distance(low, high);

    // caso base: c'è un solo elemento
    if (size >= 2) {

        // next ritorna un iteratore, in questo caso il mediano
        auto mid = next(low, size / 2);
        mergeSortVec(low,mid);
        mergeSortVec(mid,high);
        merge(low,mid,high);
    }
}

template <typename T>
void MergeSortVector::merge(typename vector<T>::iterator low, typename vector<T>::iterator mid, typename vector<T>::iterator high){

    // la n equivale al size del vector preso in input
    auto n = distance(low,high);

    // è necessario utilizzare un indice che mi permettere di scorrere il vector
    // questo perchè è necessario instanziare un vector grande qaunto è il size
    // del vector perso in input, perchè se andassimo a lavorare con il metodo 
    // push_back non otterremo un risultato corretto
    auto indice = (int) (n / 2) - 1;

    vector<T> aux(n);
    typename vector<T>::iterator i;
    typename vector<T>::iterator j;
    typename vector<T>::iterator k;

    for (i = low; i != mid; i++)
        aux.at(indice--) = *i;
    
    indice = (int) n - 1;

    for (j = mid; j != high; j++)
        aux.at(indice--) = *j;

    // a differenza del classico merge qui prima di andare a fare la fusione dei vector ordinati
    // prima ho bisogno di far puntare i rispettivi iteratori al posto giusto, quindi:
    // i punta al primo elemento del vector e j all'ultimo elemento
    i = aux.begin();
    j = aux.end() - 1;

    for ( k = low; k != high; k++ )
        if ( *j < *i )
            *k = *j--;
        else
            *k = *i++;
}

#endif // MERGESORT_H