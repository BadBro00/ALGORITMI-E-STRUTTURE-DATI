#ifndef MERGERICORSVIO_H
#define MERGERICORSVIO_H

class MergeDueVie {
    private:
        static int* merge(int[],int[],int,int[],int,int,int,int);
        static void merge(int*,int*,int,int*,int);
    public:
        static void mergeSortRic(int[],int,int);
};

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
        //out = merge(out, a+left, tot_elem_sx, a+(center+1), tot_elem_dx, 0, 0, 0);
        merge(out,a+left,tot_elem_sx,a+(center+1),tot_elem_dx);

        // Ricopia il vettore di appoggio nel vettore originale
        for (int idx=0;idx<right-left+1;idx++)
            a[left+idx]=out[idx];

        delete []out;
    }
}

int* MergeDueVie::merge(int c[], int a[], int N, int b[],int M, int i, int j, int k){

    if ( k >= N+M )
        return c;    

    if ( i == N) { c[k++] = b[j++]; return merge(c,a,N,b,M,i,j,k);}
    if ( j == M) { c[k++] = a[i++]; return merge(c,a,N,b,M,i,j,k);}
    c[k++] = (a[i] < b[j]) ? a[i++] : b[j++]; 
    
    return merge(c,a,N,b,M,i,j,k);
}

void MergeDueVie::merge(int* c, int* a, int N, int* b, int M){

    if ( N+M == 0 )
        return;

    if ( N == 0 ) { *c = *b; merge(c+1,a,N,b+1,M-1); }
    else if ( M == 0 ) { *c = *a; merge(c+1,a+1,N-1,b,M); }

    else if ( *a < *b ){ *c = *a; merge(c+1,a+1,N-1,b,M); }
    else { *c = *b; merge(c+1,a,N,b+1,M-1); }
}

#endif // MERGERICORSVIO_H