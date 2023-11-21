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
        void maxHeapify(int);
        void swap(T&,T&);
        void inOrderAscii(int,int);
    public:
        MaxHeap(vector<T>*);
        MaxHeap();
        ~MaxHeap();

        void insert(T);
        void print();
        void printAsciiTree();
        void heapSort();
        void printVector();
};

template <typename T>
MaxHeap<T>::MaxHeap(vector<T>* tree){
    this->tree = tree;
    this->heapSize = tree->size();
    buildMaxHeap();
}

template <typename T>
MaxHeap<T>::MaxHeap(){
    this->tree = new vector<T>;
    this->heapSize = 0;
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
    // this->tree->push_back(key);
    // heapSize++;
    // buildMaxHeap(); // mettere heapify bottom up

    heapSize++;
    this->tree->push_back(key);
    int i = heapSize - 1;
    while (i != 0 && this->tree->at(parent(i)) < this->tree->at(i) ){
        swap(this->tree->at(i),this->tree->at(parent(i)));
        i = parent(i);
    }
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
void MaxHeap<T>::heapSort(){
    //buildMaxHeap() in questo caso non serve
    for(int i = heapSize - 1; i > 0; i--){
        swap(this->tree->at(0),this->tree->at(i));
        heapSize--;
        maxHeapify(0);
    }
}

template <typename T>
void MaxHeap<T>::printVector(){
    cout << endl << "Vector: ";
    for(int i = 0; i < this->tree->size(); i++)
        cout << this->tree->at(i) << " ";
    cout << endl;
}

#endif // MAXHEAP_H