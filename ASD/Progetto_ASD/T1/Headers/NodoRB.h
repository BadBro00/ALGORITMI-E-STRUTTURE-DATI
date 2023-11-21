//
// Created by milit on 06/06/2022.
//
#include "List.h"
#include <iostream>
using namespace std;
// ||--------------Nodo dell'Albero RB----------||
class NodoRB{
private:
    int key;
    string val;
    char color;
    NodoRB *l,*r,*p;
public:
    Lista L;//Lista per gestire le collisioni nel nodo (Se non ci sono, rimane null)
    //Puntatore a prossimo nodo nella lista
    NodoRB *next = nullptr;
    NodoRB *prev = nullptr;
    //Costruttore
    NodoRB(int chiave,string &val){
        this->key = chiave;
        this->val = val;
        this->color = 'r';
        this->l = this->r = this->p = nullptr;
    };
    //Metodi Get per i campi
    int GetKey(){return this->key;};
    string GetVal(){return this->val;};
    char GetColor(){return this->color;};
    //Metodi Get per i puntatori
    NodoRB *GetP(){return this->p;};
    NodoRB *GetL(){return this->l;};
    NodoRB *GetR(){return this->r;};
    //Metodi Set per i campi
    void SetVal(string v){this->val = v;};
    void SetColor(char col){this->color = col;}
    //Metodi Set per i puntatori
    void SetP(NodoRB *x){this->p = x;};
    void SetR(NodoRB *x){this->r = x;};
    void SetL(NodoRB *x){this->l = x;};
};
