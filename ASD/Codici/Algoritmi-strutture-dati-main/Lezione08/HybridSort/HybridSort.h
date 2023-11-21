#ifndef HYBRIDSORT_H
#define HYBRIDSORT_H

#include "../QuickSort/QuickSort.h"

class HybridSort{
    private:
        static void compswap (int&,int&);
        static void swap(int&,int&);
        static void insertionSort(int[],int,int);
    public:
        static void hybridSort(int[],int,int);
};

void HybridSort::hybridSort(int a[], int l, int r){

    if (r - l > 25) { 

        swap(a[(l+r)/2],a[r-1]);
        compswap(a[r-1],a[l]);
        compswap(a[r],a[l]);
        compswap(a[r],a[r-1]);
        int i = QuickSort::partition(a,l+1,r-1);
        QuickSort::quickSort(a,l,i-1);
        QuickSort::quickSort(a,i+1,r);

    }
    insertionSort(a,l,r);
}

void HybridSort::insertionSort(int ptr[], int l, int r){
    int key,i;

    for (int j=l+1; j<r+1; j++){
        key = ptr[j];
        i = j-1;

        while ( i >= 0 && ptr[i] > key ){
            ptr[i+1] = ptr[i];
            i--;
        }
        ptr[i+1] = key;
    }
}

void HybridSort::compswap(int &A, int &B){
    if (B < A) swap(A, B);
}

void HybridSort::swap(int &A, int &B){
    int t=A; A=B; B=t;
}

#endif // HYBRIDSORT_H