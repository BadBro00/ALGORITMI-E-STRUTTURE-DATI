/*
    Nella classe Algorithm ci sono tutti gli algoritmi studianti ed implementati
    durante il corso di algoritmi e strutture dati parte 2 laboratorio.

    Algoritmi di ordinamento basati su confronti, dove è dimostrato che il limite inferiore è nlogn : Ω(nlogn)

        • Bubble Sort - O(n²) - non stabile - in place
        • Insertion Sort - Caso migliore: O(n) - Caso peggiore: O(n²) - non stabile - in place
        • Merge Sort - θ(nlogn) - stabile - non in place 
        • Quick Sort - Caso Migliore: θ(nlogn) - Caso peggiore: O(n²) - non è stabile - in place
        • Randomized Quick Sort - uguale al quick con un miglioramento - da considerare il valore atteso
        • Hybrid Sort - uguale al quick con un miglioramento del 25/30%
        • Heap Sort - θ(nlogn) - non stabile - in place

    Algoritmi di ordinamento non basati su confronti, in genere essi presentano un costo
    minore rispetto ai precedenti, se vengono rispettati alcuni vincoli sull'input dei dati, in tempo θ(n)

        • Counting Sort - θ(n) - in input dobbiamo avere valori di tipo intero ed m è piccolo rispetto ad n, dove n è la lunghezza dell'array e m è pari a max(A)-min(A)+1
        • Radix Sort - θ(n) - ha bisogno di più del doppio della memoria dei metodi in loco ed di essere implementato attraverso un algortimo stabile
        • Bucket Sort - θ(n) - gli elementi dell'array da ordinare sono distribuiti uniformemente
*/
#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Algorithm {
    private:
        // Bubble Sort
        template <typename T> static void compswap (T&,T&);
        template <typename T> static void swap(T&,T&);
        
        // Merge Sort
        template <typename T> static void merge(typename vector<T>::iterator, typename vector<T>::iterator, typename vector<T>::iterator);
        
        // Quick Sort
        template <typename T> static typename vector<T>::iterator partition(typename vector<T>::iterator, typename vector<T>::iterator);
        
        // Randomized Quick Sort
        template <typename T> static typename vector<T>::iterator randomizedPartition(typename vector<T>::iterator,typename vector<T>::iterator);

        // Heap Sort
        template <typename T> static void buildMaxHeap(vector<T>*,int);
        template <typename T> static void maxHeapify(vector<T>*,int,int);
    public:
        // Bubble Sort
        template <typename T> static void bubbleSort(typename vector<T>::iterator,typename vector<T>::iterator);
        
        // Insertion Sort
        template <typename T> static void insertionSort(typename vector<T>::iterator begin, typename vector<T>::iterator end);
        
        // Merge Sort
        template <typename T> static void mergeSort(typename vector<T>::iterator, typename vector<T>::iterator);
        
        // Quick Sort
        template <typename T> static void quickSort(typename vector<T>::iterator, typename vector<T>::iterator);
        
        // Randomized Quick Sort
        template <typename T> static void randomQuickSort(typename vector<T>::iterator,typename vector<T>::iterator);

        // Hybrid Sort
        template <typename T> static void hybridSort(typename vector<T>::iterator,typename vector<T>::iterator);

        // Heap Sort
        template <typename T> static void HeapSort(vector<T>*);

        // Counting Sort
        static void countingSort(vector<int>*,int);

        // Radix Sort
        // Bucket Sort
};

// Bubble Sort
template <typename T>
void Algorithm::bubbleSort(typename vector<T>::iterator begin, typename vector<T>::iterator end){
    typename vector<T>::iterator i;
    typename vector<T>::iterator j;

    for (i = begin; i != end; i++)
        for (j = end; j != i; j--)
            compswap(*(j-1),*j);
}

template <typename T>
void Algorithm::compswap(T& A, T& B){
    if (B < A) swap(A, B);
}

template <typename T>
void Algorithm::swap(T& A, T& B){
    T t=A; A=B; B=t;
}

// Insertion Sort
template <typename T>
void Algorithm::insertionSort(typename vector<T>::iterator begin, typename vector<T>::iterator end){
    typename vector<T>::iterator i;
    typename vector<T>::iterator j;
    T key;

    for ( j = begin+1; j != end; j++ ){
        key = *j;
        i = j-1;

        while ( i >= begin && *i > key ){
            *(i+1) = *i;
            i--;
        }
        *(i+1) = key;
    }
}

// Merge Sort
template <typename T>
void Algorithm::mergeSort(typename vector<T>::iterator low, typename vector<T>::iterator high){
    
    // distance ritorna la distanza tra i due iteratori
    // che riceve in input, quini il size
    auto size = distance(low, high);

    // caso base: c'è un solo elemento
    if (size >= 2) {

        // next ritorna un iteratore, in questo caso il mediano
        auto mid = next(low, size / 2);
        mergeSort<T>(low,mid);
        mergeSort<T>(mid,high);
        merge<T>(low,mid,high);
    }
}

template <typename T>
void Algorithm::merge(typename vector<T>::iterator low, typename vector<T>::iterator mid, typename vector<T>::iterator high){

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

// Quick Sort
template <typename T>
void Algorithm::quickSort(typename vector<T>::iterator begin, typename vector<T>::iterator end){

    auto size = distance(begin, end);

    if (size <= 0)
        return;

    typename vector<T>::iterator i = partition<T>(begin,end);
    quickSort<T>(begin,i-1);
    quickSort<T>(i+1,end);
}

template <typename T>
typename vector<T>::iterator Algorithm::partition(typename vector<T>::iterator begin, typename vector<T>::iterator end){

    typename vector<T>::iterator i = begin-1;
    typename vector<T>::iterator j = end;

    T v = *end;

    while(1){

        while(*(++i) < v);
        while(v < *(--j))
            if ( j == begin)
                break;

        if ( i >= j)
            break;
        
        swap(*i,*j);
    }
    swap(*i,*end);
    return i;
}

// Randomized Quick Sort
template <typename T>
void Algorithm::randomQuickSort(typename vector<T>::iterator begin, typename vector<T>::iterator end) {

    srand(1);
    srand ((unsigned)time(0));

    if (end <= begin)
        return;

    typename vector<T>::iterator i = randomizedPartition<T>(begin,end);
    randomQuickSort<T>(begin,i-1);
    randomQuickSort<T>(i+1,end);
}

template <typename T>
typename vector<T>::iterator Algorithm::randomizedPartition(typename vector<T>::iterator begin, typename vector<T>::iterator end){

    int i = rand()%distance(begin,end);

    swap(*(begin+i),*begin);

    return partition<T>(begin,end);
}

// Hybrid Sort
template <typename T>
void Algorithm::hybridSort(typename vector<T>::iterator begin, typename vector<T>::iterator end){

    auto x = distance(begin,end);
    
    if (x > 2) {

        swap(*(next(begin,x)),*(end-1));
        compswap(*(end-1),*begin);
        compswap(*end,*begin);
        compswap(*end,*(end-1));
        typename vector<T>::iterator i = partition<T>(begin,end);
        quickSort<T>(begin,i-1);
        quickSort<T>(i+1,end);

    }
    insertionSort<T>(begin,end);
}

// Heap Sort
template <typename T>
void Algorithm::HeapSort(vector<T>* tree){
    int heapSize = tree->size();
    buildMaxHeap(tree,heapSize);
    for(int i = heapSize - 1; i > 0; i--){
        swap(tree->at(0),tree->at(i));
        heapSize--;
        maxHeapify(tree,0,heapSize);
    }
}

template <typename T>
void Algorithm::buildMaxHeap(vector<T>* tree, int heapSize){
    for (int i=heapSize/2; i>=0; i--)
        maxHeapify(tree,i,heapSize);
}

template <typename T>
void Algorithm::maxHeapify(vector<T>* tree, int i, int heapSize){
    int leftTree = 2*i+1; // figlio sinistro
    int rightTree = 2*i+2; // figlio destro

    int max = i;

    if ( leftTree < heapSize && tree->at(max) < tree->at(leftTree) )
        max = leftTree;
    
    if ( rightTree < heapSize && tree->at(max) < tree->at(rightTree) )
        max = rightTree;

    if (max != i){
        swap(tree->at(i),tree->at(max));
        maxHeapify(tree,max,heapSize);
    }
}

// Counting Sort
void Algorithm::countingSort(vector<int>* vec, int n){

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

#endif // ALGORITHM_H