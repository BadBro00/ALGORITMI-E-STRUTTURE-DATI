/*
    • Progettare un algoritmo che dato un ABR ed una chiave k restitusca il successore dispari di k
*/

#include "../Esercizio01/BinarySearchTree.H"
#include "../Esercizio01/NodoAbr.h"
#include <iostream>

using namespace std;

int successorDispari(BinarySearchTree<int>* tree, NodoAbr<int>* node){

    // if ( node == nullptr )
    //     return -1;

    NodoAbr<int>* succ = tree->successor(node);

    if ( succ == nullptr )
        return -10;

    if ( succ->getKey() % 2 == 0 )
        return successorDispari(tree,succ);
    else
        return succ->getKey();
}

int main(){

    BinarySearchTree<int> tree;

    tree.insert(10);tree.insert(24);tree.insert(12);tree.insert(102);tree.insert(66);tree.insert(2);tree.insert(2);tree.insert(20);tree.insert(15);
    tree.printAsciiTree();

    int k = 10;

    cout << "SommaKKey: " << successorDispari(&tree,tree.getRoot());

    return 0;
}