// ||-----------------------------TRACCIA 2---------------||
// ||==========INCLUDO GLI HEADER CHE MI SERVONO=============||
#include <iostream>
#include "Headers/Grafo.h"
#include <queue>
#include "Functions/Functions.cpp"
#include <fstream>
using namespace std;

int main() {
    int NNodi,NArchi,num;
    fstream FileEs("FileEsempio.txt");
    int numeri[200],idx=0,count=0;
    if(FileEs.is_open()){
        while (FileEs >> num){
            numeri[idx] = num;
            idx++;
        }
        count = idx;
    }else{
        cout << "\tERRORE APERTURA";
    }
    FileEs.close();
    NNodi = numeri[0];
    NArchi = numeri[1];
    Grafo G(Archi,NArchi,NNodi);
    int k=0;
    for(int ind=2;ind<count;ind=ind+3){
        G.InsertArco(k,numeri[ind],numeri[ind+1],numeri[ind+2]);
        k++;
    }
    cout << "\nGrafo:\n";
    G.display_adjList(NArchi);
    cout << "\n\t||VISITA||\n";
    int startnode;
    cout << "\nSeleziona il nodo da cui vuoi partire: (0 a "<< NNodi <<")\n";
    cin >> startnode;
    G.BestPath(startnode,NNodi,NArchi);
    return 0;
}


