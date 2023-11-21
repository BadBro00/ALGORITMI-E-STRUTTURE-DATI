//---------------------------------------FUNCTIONS-------------------------
//
// Created by Eugenio on 06/06/2022.
//

#include <iostream>
#include <list>
#include <algorithm>
typedef pair<int,int>  Nodes;
const int INF = 1e7;
using namespace std;

void Grafo::InsertArco(int idx,int Start, int End, int Cost) {
    Archi[idx].S = Start;
    Archi[idx].E = End;
    Archi[idx].cost = Cost;
}
void Grafo::display_adjList(int NArcs) {
    for(int k=0;k<NArcs;k++){
        cout << "("<<Archi[k].S<<", "<<Archi[k].E<<", "<<Archi[k].cost<<" )"<<endl;
    }
}
void Grafo::BestPath(int s,int e,int NArcs) {
    int massimo=0;
    vector<int> dist(this->V,INF);
    vector<int> sconto(this->V,0);
    vector<int> path(this->V);
    vector<int> pred(this->V);
    vector<int> costiArchi(this->V,INF);
    list<Nodes> adj[this->V];
    list<Nodes>::iterator it;
    priority_queue<Nodes,vector<Nodes>,greater<> > pq;
    dist[s] = 0;
    for(int k=0;k<NArcs;k++){
        for(int N=0;N<this->V;N++){
            if(Archi[k].S == N){
                adj[N].push_front({Archi[k].E,Archi[k].cost});
            }
        }
    }
    int u,v,w,v1;
    pq.push({0,s});
    while(!pq.empty()){
        u = pq.top().second;
        pq.pop();
        for(it = adj[u].begin();it!=adj[u].end();++it){
            v = it->first;
            w = it->second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                massimo=dist[v];
                pred[v]=u;
                if(w>sconto[u]){
                    sconto[u]=w;
                }
                if(v==e){
                    v1=v;
                    for(int i=0;i<V;i++){
                        costiArchi[i]=sconto[v1];
                        v1=pred[v1];
                    }
                    massimo=costiArchi[0];
                    for(int i=0;i<costiArchi.size();i++){
                        if(costiArchi[i]>massimo)
                            massimo=costiArchi[i];
                    }
                    dist[v] = dist[u] + w;
                    cout<<"Il costo totale per arrivare al vertice "<<e<<" e' uguale a "<<dist[u]+w<<endl;
                    cout<<"Applicando lo sconto di "<< massimo <<" la distanza sara' pari a "<<dist[e]-massimo<<endl;
                }
                pq.push({dist[v],v});
            }
        }
    }
    for(int i=0;i<path.size();i++){
        path[i]=pred[v];
        v=pred[v];
    }
    reverse(path.begin(),path.end());//Reverse del vector Path per averlo in ordine crescente di vertici
    cout<<"PERCORSO MINIMO:\n";
    for(int i=0;i<=path.size();i++){
        if(path[i]!=0)
            cout<< pred[path[i]] << "=>" << path[i]<<", Costo:"<<dist[path[i]] <<endl;
    }
    cout << V-1  << "  , Costo: " <<dist[V-1];
}
