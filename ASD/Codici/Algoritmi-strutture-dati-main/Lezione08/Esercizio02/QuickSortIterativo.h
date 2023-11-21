#ifndef QUICKSORTITERATIVO_H
#define QUICKSORTITERATIVO_H

#include "../../Lezione04/Stack/Stack.h"

class QuickSortIterativo{
    private:
        static int partition(int[],int,int);
        static void swap(int&,int&);
    public:
        static void quickSort(int[],int,int);
};

void QuickSortIterativo::quickSort(int a[], int l, int r) {
    // crea stack
    Stack<int> stack;

    // inserisci l ed r nello stack
    stack.Push(l);
    stack.Push(r);

    // finche ci sono elementi nello stack
    while (!stack.isEmpity()){

        // estrai l ed r nello stack
        stack.Pop(r);
        stack.Pop(l);

        int p = partition(a,l,r);
        if ( p > l ){
            stack.Push(l);
            stack.Push(p-1);
        } else if ( r > p ){
            stack.Push(p+1);
            stack.Push(r);
        }
    }
}

int QuickSortIterativo::partition(int a[], int l, int r){

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

void QuickSortIterativo::swap(int &A, int &B){
    int t=A; A=B; B=t;
}

#endif // QUICKSORTITERATIVO_H