/*
    • Progettare un algoritmo ricorsivo che dato un ABR sommi le chiavi di tutte le foglie
*/

#include "../Esercizio01/BinarySearchTree.H"
#include "../Esercizio01/NodoAbr.h"
#include <iostream>

using namespace std;

int sommaKeyFoglia(NodoAbr<int>* node){

    if ( node == nullptr )
        return 0;

    if (node->getLeft() == nullptr && node->getRight() == nullptr) // sono una folgia
        return node->getKey();

    return sommaKeyFoglia(node->getLeft()) + sommaKeyFoglia(node->getRight());
}

int main(){

    BinarySearchTree<int> tree;

    tree.insert(10);tree.insert(24);tree.insert(12);tree.insert(102);tree.insert(66);tree.insert(2);tree.insert(2);tree.insert(20);
    tree.printAsciiTree();

    cout << "Somma: " << sommaKeyFoglia(tree.getRoot());

    return 0;
}