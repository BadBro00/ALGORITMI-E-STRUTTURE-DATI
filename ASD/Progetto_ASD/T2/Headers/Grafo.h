//
// Created by milit on 06/06/2022.
//
#include "Adiacenza.h"
#include <queue>
#include <list>
#include <iostream>
using namespace std;

extern Arco Archi[0];

class Grafo{
private:
    Adiacent* getADJList(int val,int weight,Adiacent* head){
        auto *Nodo = new Adiacent(val,weight);
        Nodo->next = head;
        return Nodo;
    }
    int V;
public:
    Adiacent **h;
    Grafo(Arco Archi[],int NArchi,int NNodi){
        h = new Adiacent*[NNodi]();
        this->V = NNodi+1;
        for(int i=0;i<NNodi;++i){
            h[i] = nullptr;
        }
        for(unsigned i=0;i<NArchi;i++){
            int s_V = Archi[i].S;
            int t_V = Archi[i].E;
            int c_V = Archi[i].cost;
            Adiacent* NuovoNodo = getADJList(t_V,c_V,h[s_V]);
            h[s_V] = NuovoNodo;
        }
    }
    void InsertArco(int idx,int Start,int End,int Cost);
    void display_adjList(int NArcs);
    void BestPath(int s,int e,int NArcs);
};
