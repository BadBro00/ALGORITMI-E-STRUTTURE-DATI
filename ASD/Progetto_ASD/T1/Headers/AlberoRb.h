//
// Created by milit on 06/06/2022.
//
#include "NodoRB.h"
// ||-----------Albero RB con Lista per collisioni---------||
class AlbRB{
private:
    NodoRB *root;
public:
    //Costruttore
    AlbRB(){root = nullptr;};
    //Inserimento Nodo
    void Insert(int k,string &v);
    //Fixup dei colori dei nodi
    void fixUp(NodoRB *x);
    //Ricerca Nodo
    NodoRB *SearchNodo(NodoRB *rad,int ID);
    //Metodi Rotate
    void LeftRotate(NodoRB *x);
    void RightRotate(NodoRB *x);
    NodoRB *getRoot(){return this->root;};
    //Visite dell'albero
    void inorder(NodoRB *x);
    void postorder(NodoRB *x);
    void preorder(NodoRB *x);
    //Rimozione Nodo
    void Delete(int ID);
    //Hashing della chiave del Nodo
    int HashFunction(int k);
    //Metodi per puntatori a minimo e massimo
    NodoRB *minim(NodoRB *rad);
    NodoRB *maxi(NodoRB *rad);
    void RBTransplant(NodoRB *u,NodoRB *v);
    //Metodo per la Print dell'albero
    void PrintTree(NodoRB*,int);
};
