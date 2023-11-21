//
// Created by milit on 06/06/2022.
//
#include "Arco.h"

class Adiacent{
    int cost;
public:
    Adiacent(int i, int i1) {};
    int val;
    Adiacent *next;
};

Adiacent* getAdjListNode(int dest, Adiacent* head){
    Adiacent* newNode = new Adiacent(0,0);
    newNode->val = dest;

    // point new node to the current head
    newNode->next = head;

    return newNode;
}