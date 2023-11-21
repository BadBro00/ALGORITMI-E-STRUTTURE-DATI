#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Nodo.h"

template <class T>
class LinkedList{
    private:
        Nodo<T>* head;
        Nodo<T>* last;

        //inserimento in testa
        void insHead(T* new_nodo);

        //inserimento in coda
        void insLast(T* new_nodo);
    public:
        LinkedList();
        ~LinkedList();

        //setter
        void setHead(Nodo<T>* head){this->head = head;}
        void setLast(Nodo<T>* last){this->last = last;}

        //getter
        Nodo<T> *getHead(){return head;}
        Nodo<T> *getLast(){return last;}

        //inserimento
        void insNodo(Nodo<T>* last, T* new_nodo);
};

template <class T>
LinkedList<T>::LinkedList(){
    this->head = nullptr;
    this->last = head;
}

template <class T>
LinkedList<T>::~LinkedList(){
    while (this->head != nullptr){
        auto* tmp = head;
        head = head->getNext();
        delete tmp;
    }
}

template <class T>
void LinkedList<T>::insNodo(Nodo<T>* last, T* new_nodo){
    if (last == nullptr)
        insHead(new_nodo);
    else
        insLast(new_nodo);
}

template <class T>
void LinkedList<T>::insHead(T* new_nodo){
    Nodo<T>* nodo = new Nodo<T>(nullptr,new_nodo);
    head = nodo;
    last = head;
}

template <class T>
void LinkedList<T>::insLast(T* new_nodo){
    Nodo<T>* nodo = new Nodo<T>(nullptr,new_nodo);
    last->setNext(nodo);
    last = nodo;
}

#endif // LINKEDLIST_H
