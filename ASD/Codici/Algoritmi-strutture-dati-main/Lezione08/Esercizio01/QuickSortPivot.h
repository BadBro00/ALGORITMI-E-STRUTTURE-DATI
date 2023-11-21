#ifndef QUICKSORTPIVOT_H
#define QUICKSORTPIVOT_H

class QuickSortPivot{
    private:
        static int partition(int[],int,int);
        static void swap(int&,int&);
    public:
        static void quickSort(int[],int,int);
};

void QuickSortPivot::quickSort(int a[], int l, int r) {
    if (r <= l)
        return;

    // in questo caso i due pivot potrebbero essere uguali
    // quindi c'è da rivedere la soluzione
    int i = partition(a,l,r);
    int j = partition(a,i,r);

    quickSort(a,l,i-1);
    quickSort(a,i+1,j-1);
    quickSort(a,j+1,r);
}

int QuickSortPivot::partition(int a[], int l, int r){

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

void QuickSortPivot::swap(int &A, int &B){
    int t=A; A=B; B=t;
}

#endif // QUICKSORTPIVOT_H