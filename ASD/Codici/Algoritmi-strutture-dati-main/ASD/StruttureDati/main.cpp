/*
    Test Strutture Dati:
        • Stack
        • Nodo
        • LinkedList
        • MaxHeap
        • MinHeap
        • MaxKappaHeap
        • MinKappaHeap
        • MaxPriorityQueue
        • MinPriorityQueue
*/

#include "Stack.h"
#include "Nodo.h"
#include "LinkedList.h"
#include "MaxHeap.h"
#include "MinHeap.h"
#include "MaxKappaHeap.h"
#include "MinKappaHeap.h"
#include "MaxPriorityQueue.h"
#include "MinPriorityQueue.h"
#include <string>

int main(){

    Stack<int> memStack;
    int primo = 10;
    memStack.Push(primo);
    memStack.Pop(primo);

    Nodo<int> nodo(nullptr,new int(1));
    nodo.setNext(new Nodo<int>(nullptr,new int(2)));

    LinkedList<string>* lista = new LinkedList<string>;
    lista->insNodo(lista->getLast(),new string("Ciao"));
    lista->insNodo(lista->getLast(),new string("Attilio"));

    MaxHeap<int> maxTree;
    maxTree.insert(100);

    MinHeap<int> minTree;
    minTree.insert(10);

    MaxKappaHeap<int> maxKappaTree(4);
    maxKappaTree.insert(10);

    MaxKappaHeap<int> minKappaTree(6);
    minKappaTree.insert(10);

    MaxPriorityQueue<int> maxPriorityQueue;
    maxPriorityQueue.queueInsert(120);

    MinPriorityQueue<double> minPriorityQueue;
    minPriorityQueue.queueInsert(120);
    
    return 0;
}