/*
    • Progettare un algoritmo ricorsivo che dato un ABR sommi le k chiavi più piccole
*/

#include "../Esercizio01/BinarySearchTree.H"
#include "../Esercizio01/NodoAbr.h"
#include <iostream>

using namespace std;

int sommaKKey(BinarySearchTree<int>* tree, NodoAbr<int>* node, int k){

    if ( node == nullptr )
        return 0;
    else if ( k == 0 )
        return node->getKey();
    else
        return node->getKey() + sommaKKey(tree,tree->successor(node),k-1);
}

int main(){

    BinarySearchTree<int> tree;

    tree.insert(10);tree.insert(24);tree.insert(12);tree.insert(102);tree.insert(66);tree.insert(2);tree.insert(2);tree.insert(20);
    tree.printAsciiTree();

    int k = 90;
    
    NodoAbr<int>* min = tree.minimum();

    cout << "SommaKKey: " << sommaKKey(&tree,min,k-1);

    return 0;
}