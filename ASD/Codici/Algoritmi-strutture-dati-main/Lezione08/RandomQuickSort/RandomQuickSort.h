#ifndef RANDOMQUIKSORT_H
#define RANDOMQUIKSORT_H

#include <ctime>
#include <cstdlib>

class RandomQuickSort{
    private:
        static int randomizedPartition(int[],int,int); 
        static int partition(int[],int,int);
        static void compswap (int&,int&);
        static void swap(int&,int&);
    public:
        static void randomQuickSort(int[],int,int);
};

void RandomQuickSort::randomQuickSort(int a[], int l, int r) {

    srand(1);
    srand ((unsigned)time(0));

    if (r <= l)
        return;

    int i = randomizedPartition(a,l,r);
    randomQuickSort(a,l,i-1);
    randomQuickSort(a,i+1,r);
}

int RandomQuickSort::randomizedPartition(int a[], int l, int r){

    int i= rand()%r+l; //numero pseudocasuale p<=i<=r

    swap(a[i],a[l]);

    return partition(a,l,r);
}

int RandomQuickSort::partition(int a[], int l, int r){

    // i punta all'ultimo elemento della porzione di sinistra prima del pivot
    // i+1 punta al primo elemento della porzione di destra dopo il pivot
    int i = l-1;
    int j = r;

    // pivot uguale all'ultimo elemento
    int v = a[r];

    // questo ciclo while continua la sua iterazione all'infinito
    // e verrà stoppato quando viene eseguito il break
    while(1){

        while (a[++i] < v); // cerco tutti gli elementi più piccoli del pivot, la condizione di uscita è quella che siano uguali
        while (v < a[--j]) // cerco tutti gli elementi più grandi del pivot, la condizione di uscita è quella che siano uguali
            if( j == l ) // se ho finito il sottoarray l'array
                break;

        if (i >= j)
            break;

        swap(a[i],a[j]);
    }

    swap(a[i],a[r]);
    return i;
}

void RandomQuickSort::compswap(int &A, int &B){
    if (B < A) swap(A, B);
}

void RandomQuickSort::swap(int &A, int &B){
    int t=A; A=B; B=t;
}

#endif // RANDOMQUIKSORT_H