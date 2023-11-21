#ifndef MAXPRIORITYQUEUE_H
#define MAXPRIORITYQUEUE_H

#include "MaxHeap.h"
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MaxPriorityQueue:private MaxHeap<T>{
    public:
        MaxPriorityQueue(vector<T>*);
        MaxPriorityQueue();
        virtual ~MaxPriorityQueue();

        T maximum(); // Il tempo di esecuzione di Heap-Maximum è Θ(1)
        T extractMax(); // Il tempo di esecuzione di Heap-Extract-Max è O(log n)

        void queueInsert(T); // Il tempo di esecuzione è O(log n)

        // • Per ripristinare la proprietà del max-heap, la procedura
        //   confronta un elemento con suo padre e scambia le chiavi se
        //   l'elemento è più grande. L'operazione termina quando la
        //   chiave dell'elemento è più piccola
        // • Il tempo di esecuzione di Heap-Increase-Key è O(log n)
        void increasePriority(int,T);

        void print();
        void printAsciiTree();
};

template <typename T>
MaxPriorityQueue<T>::MaxPriorityQueue(vector<T>* tree):MaxHeap<T>(tree){

}

template <typename T>
MaxPriorityQueue<T>::MaxPriorityQueue(){

}

template <typename T>
MaxPriorityQueue<T>::~MaxPriorityQueue(){

}

template <typename T>
T MaxPriorityQueue<T>::maximum(){
    return this->getRoot();
}

template <typename T>
void MaxPriorityQueue<T>::queueInsert(T key){
    this->insert(key);
}

template <typename T>
T MaxPriorityQueue<T>::extractMax(){

    if (this->getHeapSize() == 0)
        return false;
    
    T max = this->getRoot();
    this->swap(this->getTree()->at(0),this->getTree()->at(this->getHeapSize()-1));
    this->setHeapSize(this->getHeapSize()-1);
    this->maxHeapify(0);

    return max;
}

template <typename T>
void MaxPriorityQueue<T>::increasePriority(int i, T key){

    if (key < this->getTree()->at(i))
        return;

    this->setTree(i,key);

    while ( i > 0 && this->getTree()->at(this->parent(i)) < this->getTree()->at(i) ){
        this->swap(this->getTree()->at(this->parent(i)),this->getTree()->at(i));
        i = this->parent(i);
    }    
}

template <typename T>
void MaxPriorityQueue<T>::print(){
    cout << endl << "***Max Heap***" << endl;
    for (int i=0; i<this->getHeapSize(); i++)
        cout << this->getTree()->at(i) << " ";
}

template <typename T>
void MaxPriorityQueue<T>::printAsciiTree(){
    cout << endl << "***Max Ascii Heap***" << endl;
    this->inOrderAscii(0,0);
}

#endif // MAXPRIORITYQUEUE_H