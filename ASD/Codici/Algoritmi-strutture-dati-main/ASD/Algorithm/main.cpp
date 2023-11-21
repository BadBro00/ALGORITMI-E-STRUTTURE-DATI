/*
    Nella classe Algorithm ci sono tutti gli algoritmi studianti ed implementati
    durante il corso di algoritmi e strutture dati parte 2 laboratorio.

    Test Algoritmi di ordinamento basati su confronti:

        • Bubble Sort - O(n²) - non stabile - in place
        • Insertion Sort - Caso migliore: O(n) - Caso peggiore: O(n²) - non stabile - in place
        • Merge Sort - θ(nlogn) - stabile - non in place 
        • Quick Sort - Caso Migliore: θ(nlogn) - Caso peggiore: O(n²) - non è stabile - in place
        • Randomized Quick Sort - uguale al quick con un miglioramento - da considerare il valore atteso
        • Hybrid Sort - uguale al quick con un miglioramento del 25/30%
        • Heap Sort - θ(nlogn) - non stabile - in place

    Test Algoritmi di ordinamento non basati su confronti, in genere essi presentano un costo
    minore rispetto ai precedenti, se vengono rispettati alcuni vincoli sull'input dei dati

        • Counting Sort - θ(n) - in input dobbiamo avere valori di tipo intero ed m è piccolo rispetto ad n, dove n è la lunghezza dell'array e m è pari a max(A)-min(A)+1
        • Radix Sort - θ(n) - ha bisogno di più del doppio della memoria dei metodi in loco
        • Bucket Sort - θ(n) - gli elementi dell'array da ordinare sono distribuiti uniformemente
*/

#include "Algorithm.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

template <typename T> void visualizzaVec(vector<T>);
int main(){

    vector<int> bubble = {100,34,23,12,56,78,89};
    vector<string> insertion = {"colorato", "viola", "baleno", "acro"};
    vector<float> merge = {10.1,56.30,322.22,44.80,44.82};
    vector<string> quick = {"Conoscente", "Caro", "Buonasera"};
    vector<double> rQuick = {567.22,432.12,678.1,23.24,11.1,1.16};
    vector<string> hybrid = {"F","H","J","L","A","C"};
    vector<int> heapSort = {100,20,80,22,11,98};
    vector<int> countingSort = {26,22,12,18,30,26};

    Algorithm::bubbleSort<int>(bubble.begin(),bubble.end()-1);
    Algorithm::insertionSort<string>(insertion.begin(),insertion.end());
    Algorithm::mergeSort<float>(merge.begin(),merge.end());
    Algorithm::quickSort<string>(quick.begin(),quick.end()-1);
    Algorithm::randomQuickSort<double>(rQuick.begin(),rQuick.end()-1);
    Algorithm::hybridSort<string>(hybrid.begin(),hybrid.end()-1);
    Algorithm::HeapSort<int>(&heapSort);
    Algorithm::countingSort(&countingSort,countingSort.size());

    cout << endl << "bubble:" << endl;
    visualizzaVec(bubble);

    cout << endl << "insertion:" << endl;
    visualizzaVec(insertion);

    cout << endl << "merge:" << endl;
    visualizzaVec(merge);

    cout << endl << "quick:" << endl;
    visualizzaVec(quick);

    cout << endl << "rQuick:" << endl;
    visualizzaVec(rQuick);

    cout << endl << "hybrid:" << endl;
    visualizzaVec(hybrid);

    cout << endl << "heapSort:" << endl;
    visualizzaVec(heapSort);

    cout << endl << "countingSort:" << endl;
    visualizzaVec(countingSort);

    return 0;
}

template <typename T>
void visualizzaVec(vector<T> vec){
    for (auto i: vec)
        cout << i << " ";
}