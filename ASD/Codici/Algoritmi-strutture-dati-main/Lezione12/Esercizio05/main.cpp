/*
    • Progettare un algoritmo ricorsivo che dato un ABR sommi le chiavi comprese tra il valore m ed il valore M, con m<M
*/

#include "../Esercizio01/BinarySearchTree.H"
#include "../Esercizio01/NodoAbr.h"
#include <iostream>

using namespace std;

// da vedere dove andare con albero di decisione solo nella void
void sommaKeyFoglia(NodoAbr<int>* node, int N, int M, int& somma){

    if ( node == nullptr )
        return;

    if (N <= node->getKey() && node->getKey() <= M) // sono una folgia
        somma += node->getKey();

    sommaKeyFoglia(node->getLeft(),N,M,somma);
    sommaKeyFoglia(node->getRight(),N,M,somma);
}

bool isRange(int n, int N, int M){
    return N <= n && n <= M;
}

int sommaKeyFoglia(NodoAbr<int>* node, int N, int M){

    if ( node == nullptr )
        return 0;

    if ( isRange(node->getKey(),N,M) )
        return sommaKeyFoglia(node->getLeft(),N,M) + sommaKeyFoglia(node->getRight(),N,M) + node->getKey();
    else if ( N > node->getKey() )
        return sommaKeyFoglia(node->getRight(),N,M);
    
    return sommaKeyFoglia(node->getLeft(),N,M);
}

int main(){

    BinarySearchTree<int> tree;

    tree.insert(10);tree.insert(24);tree.insert(12);tree.insert(102);tree.insert(66);tree.insert(2);tree.insert(2);tree.insert(20);
    tree.printAsciiTree();

    int somma = 0;
    sommaKeyFoglia(tree.getRoot(),10,99,somma);
    cout << "Somma void: " << somma << endl;
    cout << "Somma func: " << sommaKeyFoglia(tree.getRoot(),10,99);

    return 0;
}