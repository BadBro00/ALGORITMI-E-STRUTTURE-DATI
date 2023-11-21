#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>
#include <iostream>
#define vuoto 5

using namespace std;

template <typename T>
class MaxHeap{
    private:
        vector<T>* tree;
        int heapSize;

        int parent(int i){return (i-1)/2;}
        int left(int i){return 2*i+1;}
        int right(int i){return 2*i+2;}

        void buildMaxHeap();
        void maxHeapify(int i);
        void swap(T& a,T& b);
        void inOrderAscii(int i, int spazio);
        int max(int a, int b);
    public:
        MaxHeap(vector<T>* tree, int heapSize);
        ~MaxHeap();

        void insert(T key);
        void print();
        void printAsciiTree();

        int altezza(int x, int h);
        int profondita(int x, int h);
};

template <typename T>
MaxHeap<T>::MaxHeap(vector<T>* tree, int heapSize){
    this->tree = tree;
    this->heapSize = heapSize;
    buildMaxHeap();
}

template <class T>
MaxHeap<T>::~MaxHeap(){
    delete tree;
}

template<typename T> 
void MaxHeap<T>::maxHeapify(int i){

    int leftTree = left(i); // figlio sinistro
    int rightTree = right(i); // figlio destro

    int max = i;

    if ( leftTree < heapSize && this->tree->at(max) < this->tree->at(leftTree) )
        max = leftTree;
    
    if ( rightTree < heapSize && this->tree->at(max) < this->tree->at(rightTree) )
        max = rightTree;

    if (max != i){
        swap(this->tree->at(i),this->tree->at(max));
        maxHeapify(max);
    }
}

template <typename T>
void MaxHeap<T>::swap(T& a, T& b){
    T temp = a; a = b; b = temp;
}

template <typename T>
void MaxHeap<T>::buildMaxHeap(){
    for (int i=heapSize/2; i>=0; i--)
        maxHeapify(i);
}

template <typename T>
void MaxHeap<T>::insert(T key){
    this->tree->push_back(key);
    heapSize++;
    buildMaxHeap(); // mettere heapify bottom up
}

template <typename T>
void MaxHeap<T>::print(){
    cout << endl << "***Max Heap***" << endl;
    for (int i=0; i<heapSize; i++)
        cout << tree->at(i) << " ";
}

template <typename T>
void MaxHeap<T>::printAsciiTree(){
    cout << endl << "***Max Ascii Heap***" << endl;
    inOrderAscii(0,0);
}

template <typename T>
void MaxHeap<T>::inOrderAscii(int i, int spazio){

    if (i >= heapSize)
        return;

    spazio += vuoto;

    inOrderAscii(right(i),spazio);

    cout << endl;
    for (int i = vuoto; i < spazio; i++)
        cout << " ";
    cout << this->tree->at(i) << endl;

    inOrderAscii(left(i),spazio);
}

template <typename T>
int MaxHeap<T>::max(int a,int b){
    return a > b ? a : b;
}
// NON STO CONSIDERANDO UN HEAP
template <typename T>
int MaxHeap<T>::altezza(int x, int h){

    if (x >= heapSize/2 && x < heapSize)
        return h;
    
    else if(x > heapSize) 
        return -1;
    // else{
    //     int leftTree = left(x); // figlio sinistro
    //     int rightTree = right(x); // figlio destro
    //     return max(altezza(leftTree,h+1),altezza(rightTree,h+1));
    // }
    int leftTree = left(x); // figlio sinistro
    int rightTree = right(x); // figlio destro

    if (leftTree < heapSize && rightTree < heapSize)
        return max(altezza(leftTree,h+1),altezza(rightTree,h+1));
    else if ( leftTree < heapSize )
        return altezza(leftTree,h+1);
    else
        return altezza(rightTree,h+1);
}

template <typename T>
int MaxHeap<T>::profondita(int x, int h){

    if (x == 0)
        return h;

    return profondita(parent(x),h+1);
}

#endif // MAXHEAP_H