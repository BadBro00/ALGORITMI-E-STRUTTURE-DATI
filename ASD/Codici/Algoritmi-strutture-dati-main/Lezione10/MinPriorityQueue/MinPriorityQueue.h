#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H

#include "MinHeap.h"
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MinPriorityQueue:private MinHeap<T>{
    public:
        MinPriorityQueue(vector<T>*);
        MinPriorityQueue();
        virtual ~MinPriorityQueue();

        T minimum(); // Il tempo di esecuzione di Heap-Minimum è Θ(1)
        T extractMin(); // Il tempo di esecuzione di Heap-Extract-Min è O(log n)

        void queueInsert(T); // Il tempo di esecuzione è O(log n)

        // • Per ripristinare la proprietà del min-heap, la procedura
        //   confronta un elemento con suo padre e scambia le chiavi se
        //   l'elemento è più piccolo. L'operazione termina quando la
        //   chiave dell'elemento è più grande
        // • Il tempo di esecuzione di Heap-Decrease-Key è O(log n)
        void decreasePriority(int,T);

        void print();
        void printAsciiTree();
};

template <typename T>
MinPriorityQueue<T>::MinPriorityQueue(vector<T>* tree):MinHeap<T>(tree){

}

template <typename T>
MinPriorityQueue<T>::MinPriorityQueue(){

}

template <typename T>
MinPriorityQueue<T>::~MinPriorityQueue(){

}

template <typename T>
T MinPriorityQueue<T>::minimum(){
    return this->getRoot();
}

template <typename T>
void MinPriorityQueue<T>::queueInsert(T key){
    this->insert(key);
}

template <typename T>
T MinPriorityQueue<T>::extractMin(){

    if (this->getHeapSize() == 0)
        return false;
    
    T min = this->getRoot();
    this->swap(this->getTree()->at(0),this->getTree()->at(this->getHeapSize()-1));
    this->setHeapSize(this->getHeapSize()-1);
    this->minHeapify(0);

    return min;
}

template <typename T>
void MinPriorityQueue<T>::decreasePriority(int i, T key){

    if (key > this->getTree()->at(i))
        return;

    this->setTree(i,key);

    while ( i > 0 && this->getTree()->at(this->parent(i)) > this->getTree()->at(i) ){
        this->swap(this->getTree()->at(this->parent(i)),this->getTree()->at(i));
        i = this->parent(i);
    }    
}

template <typename T>
void MinPriorityQueue<T>::print(){
    cout << endl << "***Max Heap***" << endl;
    for (int i=0; i<this->getHeapSize(); i++)
        cout << this->getTree()->at(i) << " ";
}

template <typename T>
void MinPriorityQueue<T>::printAsciiTree(){
    cout << endl << "***Max Ascii Heap***" << endl;
    this->inOrderAscii(0,0);
}

#endif // MINPRIORITYQUEUE_H