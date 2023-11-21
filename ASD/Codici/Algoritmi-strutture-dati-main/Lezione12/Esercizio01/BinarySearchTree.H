#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "NodoAbr.h"
#include <iostream>
#define vuoto 5

using namespace std;

template <typename T>
class BinarySearchTree{
    private:
        NodoAbr<T>* root;

        void insNode(T,NodoAbr<T>*,NodoAbr<T>*);
        void inOrderAscii(NodoAbr<T>*,int);
        void transplant(NodoAbr<T>*,NodoAbr<T>*);

        void preOrderView(NodoAbr<T>*);
        void inOrderView(NodoAbr<T>*);
        void postOrderView(NodoAbr<T>*);
    public:
        BinarySearchTree();
        BinarySearchTree(NodoAbr<T>*);
        ~BinarySearchTree();

        NodoAbr<T> *getRoot() const {return root;}

        void search(T);
        NodoAbr<T> *search(T,NodoAbr<T>*) const;
        
        NodoAbr<T> *minimum() const;
        NodoAbr<T> *maximum() const;

        NodoAbr<T> *minimum(NodoAbr<T>*) const;
        NodoAbr<T> *maximum(NodoAbr<T>*) const;
        
        NodoAbr<T> *predecessor(T) const;
        NodoAbr<T> *successor(T) const;

        NodoAbr<T> *predecessor(NodoAbr<T>*) const;
        NodoAbr<T> *successor(NodoAbr<T>*) const;
        
        void insert(T);
        void insert(T,NodoAbr<T>*,NodoAbr<T>*);
        void deleteNode(T);

        void printAsciiTree();
        void preOrder();
        void inOrder();
        void postOrder();
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(NodoAbr<T>* root){
    this->root = root;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(){
    this->root = nullptr;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree(){
    delete root;
}

template <typename T>
void BinarySearchTree<T>::search(T key){

    NodoAbr<int>* tmp = this->search(key,this->getRoot());

    if (tmp == nullptr)
        cout << "NodoAbr " << key << " non trovato!" << endl;
    else 
        cout << "NodoAbr " << key << " trovato = " << tmp->getKey() << endl;
}

template <typename T>
NodoAbr<T> *BinarySearchTree<T>::search(T key, NodoAbr<T>* node) const {

    if (node == nullptr || key == node->getKey())
        return node;
    
    if (key < node->getKey())
        return search(key,node->getLeft());
    else
        return search(key,node->getRight());

    return nullptr;
}

template <typename T>
NodoAbr<T> *BinarySearchTree<T>::minimum() const {
    return this->minimum(root);
}

template <typename T>
NodoAbr<T> *BinarySearchTree<T>::maximum() const {
    return this->maximum(root);
}

template <typename T>
NodoAbr<T> *BinarySearchTree<T>::minimum(NodoAbr<T>* node) const {
    while (node->getLeft() != nullptr){
        node = node->getLeft();
    }
    return node;
}

template <typename T>
NodoAbr<T> *BinarySearchTree<T>::maximum(NodoAbr<T>* node) const {
    while (node->getRight() != nullptr){
        node = node->getRight();
    }
    return node;
}

template <typename T>
NodoAbr<T> *BinarySearchTree<T>::predecessor(T key) const {

    NodoAbr<T>* node = this->search(key,this->getRoot());

    if (node->getLeft() != nullptr)
        return maximum(node->getLeft());

    NodoAbr<T>* y = node->getParent();
    while (y != nullptr && node == y->getLeft()){
        node = y;
        y = y->getParent();
    }

    return y;
}

template <typename T>
NodoAbr<T> *BinarySearchTree<T>::predecessor(NodoAbr<T>* node) const {

    if (node->getLeft() != nullptr)
        return maximum(node->getLeft());

    NodoAbr<T>* y = node->getParent();
    while (y != nullptr && node == y->getLeft()){
        node = y;
        y = y->getParent();
    }

    return y;
}

template <typename T>
NodoAbr<T> *BinarySearchTree<T>::successor(T key) const {

    NodoAbr<T>* node = this->search(key,this->getRoot());

    if (node->getRight() != nullptr)
        return minimum(node->getRight());

    NodoAbr<T>* y = node->getParent();
    while (y != nullptr && node == y->getRight()){
        node = y;
        y = y->getParent();
    }

    return y;
}

template <typename T>
NodoAbr<T> *BinarySearchTree<T>::successor(NodoAbr<T>* node) const {

    if (node->getRight() != nullptr)
        return minimum(node->getRight());

    NodoAbr<T>* y = node->getParent();
    while (y != nullptr && node == y->getRight()){
        node = y;
        y = y->getParent();
    }

    return y;
}

template <typename T>
void BinarySearchTree<T>::insert(T key){
    this->insert(key,nullptr,this->root);
}

template <typename T>
void BinarySearchTree<T>::insert(T key, NodoAbr<T>* prev, NodoAbr<T>* curr){

    if (this->root == nullptr)
        this->root = new NodoAbr<T>(key);

    if ( curr == nullptr )
        insNode(key,prev,curr);
    else if (key > curr->getKey())
        insert(key,curr,curr->getRight());
    else
        insert(key,curr,curr->getLeft());
}

template <typename T>
void BinarySearchTree<T>::insNode(T key, NodoAbr<T>* prev, NodoAbr<T>* curr){

    if (prev != nullptr){

        curr = new NodoAbr<T>(key);
        curr->setParent(prev);

        if (key > prev->getKey())
            prev->setRight(curr);
        else
            prev->setLeft(curr);

    } else {
        curr = new NodoAbr<T>(key);
    }
}

template <typename T>
void BinarySearchTree<T>::deleteNode(T key){

    NodoAbr<T>* node = this->search(key,root);
    if (node != nullptr){

        if (node->getLeft() == nullptr) // se non ha figlio sinistro e può avere o non avere figio destro
            this->transplant(node,node->getRight());
        else if ( node->getRight() == nullptr ) // se non ha filgio destro
            this->transplant(node,node->getLeft());
        else { // se ha due figli
            NodoAbr<T>* y = this->minimum(node->getRight()); // prendi il successore

            if ( y->getParent() != node ){
                this->transplant(y,y->getRight());
                y->setRight(node->getRight());
                y->getRight()->setParent(y);
            }

            this->transplant(node,y);
            y->setLeft(node->getLeft());
            y->getLeft()->setParent(y);
        }
    }
}

template <typename T>
void BinarySearchTree<T>::transplant(NodoAbr<T>* u, NodoAbr<T>* v){

    if (u->getParent() == nullptr) // se c'è un solo NodoAbr nell'albero
        this->root = v;
    else if ( u == u->getParent()->getLeft() ) // se u è il figlio sinistro
        u->getParent()->setLeft(v);
    else
        u->getParent()->setRight(v);
    
    if ( v != nullptr )
        v->setParent(u->getParent());
}

template <typename T>
void BinarySearchTree<T>::printAsciiTree(){
    cout << endl << "***Min Ascii Heap***" << endl;
    inOrderAscii(root,0);
}

template <typename T>
void BinarySearchTree<T>::inOrderAscii(NodoAbr<T>* root, int spazio){

    if (root == nullptr)
        return;

    spazio += vuoto;

    inOrderAscii(root->getRight(),spazio);

    cout << endl;
    for (int i = vuoto; i < spazio; i++)
        cout << " ";
    cout << root->getKey() << endl;

    inOrderAscii(root->getLeft(),spazio);
}

template <typename T>
void BinarySearchTree<T>::inOrder(){
    cout << endl << "***inOrder***" << endl;
    this->inOrderView(root);
}

template <typename T>
void BinarySearchTree<T>::preOrder(){
    cout << endl << "***preOrder***" << endl;
    this->preOrderView(root);
}

template <typename T>
void BinarySearchTree<T>::postOrder(){
    cout << endl << "***postOrder***" << endl;
    this->postOrderView(root);
}

template <typename T>
void BinarySearchTree<T>::inOrderView(NodoAbr<T>* node){

    if ( node == nullptr )
        return;

    cout << node->getKey() << " ";
    inOrderView(node->getLeft());
    inOrderView(node->getRight());
}

template <typename T>
void BinarySearchTree<T>::preOrderView(NodoAbr<T>* node){

    if ( node == nullptr )
        return;

    inOrderView(node->getLeft());
    cout << node->getKey() << " ";
    inOrderView(node->getRight());
}

template <typename T>
void BinarySearchTree<T>::postOrderView(NodoAbr<T>* node){

    if ( node == nullptr )
        return;

    inOrderView(node->getLeft());
    inOrderView(node->getRight());
    cout << node->getKey() << " ";
}

#endif // BINARYSEARCHTREE_H