#ifndef MAXKAPPAHEAP_H
#define MAXKAPPAHEAP_H

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class MaxKappaHeap{
    private:
        vector<T>* tree;
        int heapSize;
        int k;

        void buildMaxKappaHeap();
        void maxKappaHeapify(int);
        void swap(T&,T&);
    public:
        MaxKappaHeap(vector<T>*,int);
        MaxKappaHeap(int);
        ~MaxKappaHeap();

        void insert(T);
        void print();
};

template <typename T>
MaxKappaHeap<T>::MaxKappaHeap(vector<T>* tree, int k){
    this->tree = tree;
    this->heapSize = tree->size();
    this->k = k;
    buildMaxKappaHeap();
}

template <typename T>
MaxKappaHeap<T>::MaxKappaHeap(int k){
    this->tree = new vector<T>;
    this->heapSize = 0;
    this->k = k;
}

template <class T>
MaxKappaHeap<T>::~MaxKappaHeap(){
    delete tree;
}

template<typename T> 
void MaxKappaHeap<T>::maxKappaHeapify(int i){

    int ind = i+1;
    int last = k*ind; // ultimo figlio
    int first = last-k; // primo filgio

    int max = i;

    // prendo il massimo tra i figli
    for (int j=last; j>first; j--)
        if ( j < heapSize &&  this->tree->at(max) < this->tree->at(j))
            max = j;
    
    if ( max != i ){
        swap(this->tree->at(i),this->tree->at(max));
        maxKappaHeapify(max);
    }
}

template <typename T>
void MaxKappaHeap<T>::swap(T& a, T& b){
    T temp = a; a = b; b = temp;
}

template <typename T>
void MaxKappaHeap<T>::buildMaxKappaHeap(){
    for (int i=heapSize/k; i>=0; i--)
        maxKappaHeapify(i);
}

template <typename T>
void MaxKappaHeap<T>::insert(T key){
    this->tree->push_back(key);
    heapSize++;
    buildMaxKappaHeap();
}

template <typename T>
void MaxKappaHeap<T>::print(){
    cout << "***Max Kappa Heap***" << endl;
    for (int i=0; i<heapSize; i++)
        cout << tree->at(i) << " ";
}

#endif // MAXKAPPAHEAP_H