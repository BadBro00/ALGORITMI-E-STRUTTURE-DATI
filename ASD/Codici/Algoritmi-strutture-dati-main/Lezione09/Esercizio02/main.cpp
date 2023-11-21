/*
    • Progettare ed implementare una algoritmo che, dato un
      Min-Heap ed un valore X, stampi la somma dei valori dei
      nodi minori di X.
    
    • Es.: X=8 -> S=13
*/

#include "MinHeap.h"
#include <vector>

using namespace std;

int main(){

    MinHeap<int> minTree(new vector<int>);

    minTree.insert(10);
    minTree.insert(190);
    minTree.insert(2);
    minTree.insert(20);
    minTree.insert(100);
    minTree.insert(200);
    minTree.insert(300);
    minTree.print();
    minTree.printAsciiTree();

    // Function
    cout << endl << "La somma di 500 é: " << minTree.sumValue(0,500);

    // procedura
    double sum = 0;
    minTree.sumValue(0,20,sum);
    cout << endl << "La somma di 20 é: " << sum;

    // procedura
    sum = 0;
    minTree.sumValue(0,190,sum);
    cout << endl << "La somma di 190 é: " << sum;

    return 0;
}