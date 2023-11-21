/*
    Esercizio svolto in classe non presente sulle slide

    Progettare ed implementare un algoritmo ricorsivo che dato un albero binario
    calcoli l'alteza di un nodo x (numero degli archi del più lungo cammino da un nodo ad una foglia)

    Progettare ed implementare un algoritmo ricorsivo che dato un albero binario
    calcoli la profodità di un nodo x (lunghezza del cammino semplice dalla radice ad un nodo)   
*/
#include "MinKappaHeap.h"
#include <vector>
#include <ctime>

using namespace std;

int main(){

    srand(1);
    srand((unsigned)time(0));

    MinKappaHeap<int> minTree(new vector<int>, 4);

    for (int i=0; i<200; i++)
        minTree.insert(rand()%900);
    minTree.print();

    return 0;
}