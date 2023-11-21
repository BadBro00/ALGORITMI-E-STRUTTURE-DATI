/*
    Progettare un algoritmo ricorsivo per contare il numero id scambi necessari per ordinare un'array
*/
#include "MergeSort.h"
#include <iostream>

int cont = 0;

void contatore(int[],int,int,int);
void contatoreScambiBubbleSort(int[],int,int);
void visualizzaArray(int[],int);
int main() {

    const int n=4;
    int a[n] = {9,7,3,1};

    MergeAstrattoSulPosto::mergeSort(a,0,n-1);
    visualizzaArray(a,n);
    std::cout << "Contatore 'Scambi' Merge Sort: " << MergeAstrattoSulPosto::cont;

    int b[n] = {9,7,3,1};
    contatoreScambiBubbleSort(b,0,n-1);
    visualizzaArray(b,n);
    std::cout << "Contatore Scambi Bubble Sort: " << cont;

    return 0;
}

void contatoreScambiBubbleSort(int a[], int left, int right){

    if (left < right){
        int center = (left+right)/2;
        contatoreScambiBubbleSort(a,left,center);
        contatoreScambiBubbleSort(a,center+1,right);
        contatore(a,left,center,right);
    }
}

void contatore(int a[], int left, int center, int right){

    const int n=right-left;
    int aux[n];
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

void visualizzaArray(int a[],int n){
    std::cout << std::endl;
    for (int i=0; i<n; i++)
        std::cout << "Array[" << i << "]: " << a[i] << std::endl;
}