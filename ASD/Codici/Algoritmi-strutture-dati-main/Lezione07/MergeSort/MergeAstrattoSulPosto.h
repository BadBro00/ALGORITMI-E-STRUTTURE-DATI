#ifndef MERGESORTSULPOSTO_H
#define MERGESORTSULPOSTO_H

class MergeAstrattoSulPosto{

    private:
        static void merge(int[],int,int,int);
    public:
        static int cont;
        static void mergeSort(int[],int,int);
};

int MergeAstrattoSulPosto::cont = 0;

void MergeAstrattoSulPosto::mergeSort(int a[], int left, int right) {
    if (left<right) {
        int center = (left+right)/2;
        mergeSort(a, left, center);
        mergeSort(a, center+1, right);
        merge(a, left, center, right);
    }
}

void MergeAstrattoSulPosto::merge(int a[], int left, int center, int right){
    const int n=8;
    static int aux[n];
    int i,j;

    for (i = center+1; i > left; i--)
        aux[i-1] = a[i-1];

    for (j = center; j < right; j++)
        aux[right+center-j] = a[j+1];

    for (int k = left; k <= right; k++)
        if (aux[j] < aux[i]){
            a[k] = aux[j--];
            cont += center-i+1;
        } else
            a[k] = aux[i++];
}

#endif // MERGESORTSULPOSTO_H