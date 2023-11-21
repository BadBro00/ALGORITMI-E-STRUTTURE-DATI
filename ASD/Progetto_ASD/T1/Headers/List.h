//
// Created by milit on 06/06/2022.
//

#include <iostream>
using namespace std;
class NodoRB;
class Hash;
// ||--------Lista per gestire le collisioni--------||
class Lista{
private:
    NodoRB *head,*tail,*curr;
public:
    Lista(){head = tail = curr = nullptr;};
    //Metodi get per ottenere i puntatori a head e tail
    NodoRB *getHead(){return this->head;};
    NodoRB *getCurr(){return this->curr;};
    NodoRB *getTail(){return this->tail;};
    NodoRB *trovaNodo(string v);//Ricerca di un nodo nella lista tramite valore
    void addNodo(int k,string v);//Inserimento di un nodo nella lista tramite chiave e valore
    void delNodo(string v);//Eliminazione Nodo dalla lista tramite valore
    void PrintList(NodoRB *h);
};
