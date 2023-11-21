/*
    Esercizio

    • Progettare ed implementare una classe che implementi un
      heap k-nario (ogni nodo ha k figli)
*/

#include "MaxKappaHeap.h"
#include <vector>
#include <ctime>

using namespace std;

int main(){

    srand(1);
    srand((unsigned)time(0));

    MaxKappaHeap<int> maxTree(new vector<int>,4);

    for (int i=0; i<20; i++)
        maxTree.insert(rand()%900);
    maxTree.print();



    return 0;
}