#ifndef MERGEDUEVIE_H
#define MERGEDUEVIE_H

class MergeDueVie {
    private:
        static void merge(int[],int[],int,int[],int);
        static int* merge(int[],int[],int,int[],int,int,int,int);
    public:
        static void mergeSort(int[],int,int);
        static void mergeSortRic(int[],int,int);
};

void MergeDueVie::mergeSort(int a[], int left, int right) {

        if (left<right) {

        // Stabilisce la posizione centrale del vettore
        int center = (left+right)/2;

        mergeSort(a, left, center);
        mergeSort(a, center+1, right);

        int tot_elem_sx = center-left+1;
        int tot_elem_dx = right-center;

        int dim_out = right-left+1;

        // Alloca il vettore di appoggio
        int *out = new int[dim_out];

        // Fonde le due parti del vettore nel vettore di out
        merge(out, a+left, tot_elem_sx, a+(center+1), tot_elem_dx);

        // Ricopia il vettore di appoggio nel vettore originale
        for (int idx=0;idx<right-left+1;idx++)
            a[left+idx]=out[idx];

        delete []out;
    }
}

void MergeDueVie::merge(int c[], int a[], int N, int b[],int M){

    for( int i=0, j=0, k=0; k< N+M; k++){
        if ( i == N) { c[k] = b[j++]; continue;}
        if ( j == M) { c[k] = a[i++]; continue;}
        c[k] = (a[i] < b[j]) ? a[i++] : b[j++];
    }
}

void MergeDueVie::mergeSortRic(int a[], int left, int right) {

        if (left<right) {

        // Stabilisce la posizione centrale del vettore
        int center = (left+right)/2;

        mergeSortRic(a, left, center);
        mergeSortRic(a, center+1, right);

        int tot_elem_sx = center-left+1;
        int tot_elem_dx = right-center;

        int dim_out = right-left+1;

        // Alloca il vettore di appoggio
        int *out = new int[dim_out];

        // Fonde le due parti del vettore nel vettore di out
        out = merge(out, a+left, tot_elem_sx, a+(center+1), tot_elem_dx, 0, 0, 0);

        // Ricopia il vettore di appoggio nel vettore originale
        for (int idx=0;idx<right-left+1;idx++)
            a[left+idx]=out[idx];

        delete []out;
    }
}

//Overload
int* MergeDueVie::merge(int c[], int a[], int N, int b[],int M, int i, int j, int k){

    if ( k >= N+M )
        return c;    

    if ( i == N) { c[k++] = b[j++]; return merge(c,a,N,b,M,i,j,k);}
    if ( j == M) { c[k++] = a[i++]; return merge(c,a,N,b,M,i,j,k);}
    c[k++] = (a[i] < b[j]) ? a[i++] : b[j++];

    return merge(c,a,N,b,M,i,j,k);
}

#endif // MERGEDUEVIE_H