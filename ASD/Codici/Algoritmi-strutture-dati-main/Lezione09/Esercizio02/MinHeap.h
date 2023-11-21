#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include <iostream>
#define vuoto 10

using namespace std;

template <typename T>
class MinHeap{
    private:
        vector<T>* tree;
        int heapSize;

        int parent(int i){return (i-1)/2;}
        int left(int i){return 2*i+1;}
        int right(int i){return 2*i+2;}

        void buildMinHeap();
        void minHeapify(int);
        void swap(T&,T&);
        void inOrderAscii(int,int);
    public:
        MinHeap(vector<T>*);
        MinHeap();
        ~MinHeap();

        void insert(T);
        void print();
        void printAsciiTree();

        double sumValue(int,double);
        void sumValue(int,double,double&);
};

template <typename T>
MinHeap<T>::MinHeap(vector<T>* tree){
    this->tree = tree;
    this->heapSize = tree->size();
    buildMinHeap();
}

template <typename T>
MinHeap<T>::MinHeap(){
    this->tree = new vector<T>;
    this->heapSize = 0;
}

template <class T>
MinHeap<T>::~MinHeap(){
    delete tree;
}

template<typename T> 
void MinHeap<T>::minHeapify(int i){

    int leftTree = left(i); // figlio sinistro
    int rightTree = right(i); // figlio destro

    int max = i;

    if ( leftTree < heapSize && this->tree->at(max) > this->tree->at(leftTree) )
        max = leftTree;
    
    if ( rightTree < heapSize && this->tree->at(max) > this->tree->at(rightTree) )
        max = rightTree;

    if (max != i){
        swap(this->tree->at(i),this->tree->at(max));
        minHeapify(max);
    }
}

template <typename T>
void MinHeap<T>::swap(T& a, T& b){
    T temp = a; a = b; b = temp;
}

template <typename T>
void MinHeap<T>::buildMinHeap(){
    for (int i=heapSize/2; i>=0; i--)
        minHeapify(i);
}

template <typename T>
void MinHeap<T>::insert(T key){
    // this->tree->push_back(key);
    // heapSize++;
    // buildMinHeap(); // mettere heapify bottom up

    heapSize++;
    this->tree->push_back(key);
    int i = heapSize - 1;
    while (i != 0 && this->tree->at(parent(i)) > this->tree->at(i) ){
        swap(this->tree->at(i),this->tree->at(parent(i)));
        i = parent(i);
    }
}

template <typename T>
void MinHeap<T>::print(){
    cout << endl << "***Min Heap***" << endl;
    for (int i=0; i<heapSize; i++)
        cout << tree->at(i) << " ";
}

template <typename T>
double MinHeap<T>::sumValue(int root, double x){

    if ( root >= heapSize )
        return 0;

    if ( this->tree->at(root) < x )
        return this->tree->at(root) + sumValue(left(root),x) + sumValue(right(root),x);

    return 0;
}

template <typename T>
void MinHeap<T>::sumValue(int root, double x,double& sum){

    // se è una foglia return implicito

    if ( x <= this->tree->at(root) ) // se è minore uguale della radice
        return;

    sum += this->tree->at(root);

    int leftTree = left(root); // figlio sinistro
    int rightTree = right(root); // figlio destro

    if ( leftTree < heapSize && x > this->tree->at(leftTree)) sumValue(leftTree,x,sum);
    if ( rightTree < heapSize && x > this->tree->at(rightTree) ) sumValue(rightTree,x,sum);
}

template <typename T>
void MinHeap<T>::printAsciiTree(){
    cout << endl << "***Max Ascii Heap***" << endl;
    inOrderAscii(0,0);
}

template <typename T>
void MinHeap<T>::inOrderAscii(int i, int spazio){

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

#endif // MAXHEAP_H