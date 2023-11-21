#ifndef ISHEAP_H
#define ISHEAP_H

class IsHeap{
    private:
        template <typename T> static bool isMinHeap(T[],int,int);
        template <typename T> static bool isMaxHeap(T[],int,int);
    public:
        template <typename T> static int isHeap(T[],int,int);
};

template <typename T>
bool IsHeap::isMinHeap(T array[], int heapSize, int i){

    if (i > heapSize/2) // se è una folgia
        return true;
    
    int leftTree = 2*i+1; // figlio sinistro
    int rightTree = 2*i+2; // figlio destro

    if ( (leftTree < heapSize && array[i] > array[leftTree]) || (rightTree < heapSize && array[i] > array[rightTree]) )
        return false;

    return isMinHeap(array,heapSize,leftTree) && isMinHeap(array,heapSize,rightTree);
}

template <typename T>
bool IsHeap::isMaxHeap(T array[], int heapSize, int i){

    if (i > heapSize/2) // se è una folgia
        return true;
    
    int leftTree = 2*i+1; // figlio sinistro
    int rightTree = 2*i+2; // figlio destro

    if ( (leftTree < heapSize && array[i] < array[leftTree]) || (rightTree < heapSize && array[i] < array[rightTree]) )
        return false;

    return isMaxHeap(array,heapSize,leftTree) && isMaxHeap(array,heapSize,rightTree);
}

template <typename T>
int IsHeap::isHeap(T array[], int heapSize, int i){

    if ( isMinHeap<T>(array,heapSize,i) )
        return 1;
    else if ( isMaxHeap<T>(array,heapSize,i) )
        return 2;
    else
        return 0;
    
    return false;
}

#endif // ISHEAP_H