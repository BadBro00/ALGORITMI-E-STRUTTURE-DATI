#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <vector>
#include "../CountingSort/CountingSort.h"

using namespace std;

class RadixSort{
    private:
        template <typename T> static int getMax(vector<T>,int);
        template <typename T> static void countingSortRadix(vector<T>,int);
    public:
        template <typename T> static void radixSort(vector<T>,int);
};

template <typename T>
void RadixSort::radixSort(vector<T> vec, int n){

    int max = getMax(vec,vec.size());

    // Esegui il conteggio per ogni cifra. Nota che invece
    // del numero di cifra che passa, exp è passato. exp è 10^i
    // dove i è il numero della cifra corrente
    for (int exp = 1; m / exp > 0; exp *= 10)
}

template <typename T>
int RadixSort::getMax(vector<T> vec, int n){
    
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

template <typename T>
void RadixSort::countingSortRadix(vector<T> vec, int n){

    int *output = new int[n]; // output array
    int i, count[10] = { 0 };
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 0; i < n; i++)
        cout << "A: " << arr[i]/exp % 10;
    cout << endl;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];

}

#endif // RADIXSORT_H