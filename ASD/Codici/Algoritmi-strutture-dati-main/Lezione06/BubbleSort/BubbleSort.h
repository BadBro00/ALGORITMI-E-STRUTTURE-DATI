#ifndef BUBBLESORT_H
#define BUBBLESORT_H

class BubbleSort{

    private:
        static int cont;
        static void compswap (int&,int&);
        static void swap(int&,int&);
    public:
        static void bubble (int a[], int l, int r);
        static int getCont(){return cont;}
};

int BubbleSort::cont = 0;

void BubbleSort::bubble(int a[], int l, int r){
    for (int i=l; i < r; i++)
        for (int j=r; j>i; j--)
            compswap(a[j-1], a[j]);
}

void BubbleSort::compswap(int &A, int &B){
    if (B < A) swap(A, B);
}

void BubbleSort::swap(int &A, int &B){
    int t=A; A=B; B=t;
    cont++;
}

#endif // BUBBLESORT_H