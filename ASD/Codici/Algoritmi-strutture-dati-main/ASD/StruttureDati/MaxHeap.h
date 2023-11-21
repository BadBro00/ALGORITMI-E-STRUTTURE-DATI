#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>
#include <iostream>
#define space 5

using namespace std;

template <typename T>
class MaxHeap{
    private:
        vector<T>* tree;
        int heapSize;

        int left(int i){return 2*i+1;}
        int right(int i){return 2*i+2;}

        void buildMaxHeap();
    protected:
        int parent(int i){return (i-1)/2;}

        T getRoot(){return this->tree->at(0);}
        T getTail(){return this->tree->at(heapSize-1);}

        vector<T>* getTree(){return this->tree;}
        void setTree(int i,T key){this->tree->at(i) = key;}

        void setHeapSize(int heapSize){this->heapSize = heapSize;}
        int getHeapSize(){return this->heapSize;}

        void inOrderAscii(int,int);
        void maxHeapify(int);
        void swap(T&,T&);
    public:
        MaxHeap(vector<T>*);
        MaxHeap();
        ~MaxHeap();

        void insert(T);
        void print();
        void printAsciiTree();
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

    spazio += space;

    inOrderAscii(right(i),spazio);

    cout << endl;
    for (int i = space; i < spazio; i++)
        cout << " ";
    cout << this->tree->at(i) << endl;

    inOrderAscii(left(i),spazio);
}

#endif // MAXHEAP_H