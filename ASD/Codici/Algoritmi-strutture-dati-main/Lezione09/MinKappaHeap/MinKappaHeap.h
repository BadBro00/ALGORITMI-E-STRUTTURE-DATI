#ifndef MINKAPPAHEAP_H
#define MINKAPPAHEAP_H

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class MinKappaHeap{
    private:
        vector<T>* tree;
        int heapSize;
        int k;

        void buildMinKappaHeap();
        void minKappaHeapify(int);
        void swap(T&,T&);
    public:
        MinKappaHeap(vector<T>*,int);
        MinKappaHeap(int);
        ~MinKappaHeap();

        void insert(T key);
        void print();
};

template <typename T>
MinKappaHeap<T>::MinKappaHeap(vector<T>* tree, int k){
    this->tree = tree;
    this->heapSize = tree->size();
    this->k = k;
    buildMinKappaHeap();
}

template <typename T>
MinKappaHeap<T>::MinKappaHeap(int k){
    this->tree = new vector<T>;
    this->heapSize = 0;
    this->k = k;
}


template <class T>
MinKappaHeap<T>::~MinKappaHeap(){
    delete tree;
}

template<typename T> 
void MinKappaHeap<T>::minKappaHeapify(int i){

    int ind = i+1;
    int last = k*ind; // ultimo figlio
    int first = last-k; // primo filgio

    int min = i;

    // prendo il massimo tra i figli
    for (int j=last; j>first; j--)
        if ( j < heapSize &&  this->tree->at(min) > this->tree->at(j))
            min = j;
    
    if ( min != i ){
        swap(this->tree->at(i),this->tree->at(min));
        minKappaHeapify(min);
    }
}

template <typename T>
void MinKappaHeap<T>::swap(T& a, T& b){
    T temp = a; a = b; b = temp;
}

template <typename T>
void MinKappaHeap<T>::buildMinKappaHeap(){
    for (int i=heapSize/k; i>=0; i--)
        minKappaHeapify(i);
}

template <typename T>
void MinKappaHeap<T>::insert(T key){
    this->tree->push_back(key);
    heapSize++;
    buildMinKappaHeap();

    // heapSize++;
    // this->tree->push_back(key);
    // int i = heapSize - 1;

    // int parent = i%k == 0 ? i/k-1 : i/k;

    // while (i != 0 && this->tree->at(parent) > this->tree->at(i) ){
    //     swap(this->tree->at(i),this->tree->at(parent));
    //     i = parent;
    // }
}

template <typename T>
void MinKappaHeap<T>::print(){
    cout << "***Max Kappa Heap***" << endl;
    for (int i=0; i<heapSize; i++)
        cout << tree->at(i) << " ";
}

#endif // MINKAPPAHEAP_H