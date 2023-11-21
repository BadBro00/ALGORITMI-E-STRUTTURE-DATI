
#ifndef OCCORRENZE_H
#define OCCORRENZE_H

#include <map>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Occorrenze{
    
    private:
        ifstream file;
        string nomeF;

        // una map è una tupla avente una chiave e un valore
        // in questo caso abbiamo come chiave una stringa e come valore un intero
        map<string,int> amap;

        void openFile();
    public:
        Occorrenze(string nomeF);
        ~Occorrenze();

        void readFile();
        void printMap();
};

Occorrenze::Occorrenze(string nomeF){
    this->nomeF = nomeF;
    openFile();
}

Occorrenze::~Occorrenze(){
    file.close();
}

void Occorrenze::openFile(){
    file.open(nomeF, ios::in);
    if (!file.is_open()) cout << "Errone in apertura file" << nomeF << endl;
}

void Occorrenze::readFile(){

    string word;

    // la map ci da la possibilità di utilizzare gli iteratori
    map<string,int>::iterator cii;

    while ( file >> word){

        // la find di map prende in input una chiave e restutisce
        // un iteratore, se trova la chiave all'interno della map
        // allora torna l'interatore che punta ad esso, altrimenti
        // ritorna l'iteratore end()
        cii = amap.find(word);

        // quindi se è uguale ad end significa che non si sta questa
        // chiave e vado ad inserirla tramite insert tramite make_pair
        // altrimenti incremento il valore con chiave trovata
        if ( cii == amap.end())
            amap.insert(make_pair(word,1));
        else   
            amap.at(word)++;
    }

    // while (file >> word){
    //     amap.insert(make_pair(word,amap.at(word)));
    // }
    // da capire
}

void Occorrenze::printMap(){
    map<string,int>::iterator it;

    // stampo la mappa utilizzando gli iteratori
    // ed accedero al loro contenuto attraverso
    // i due puntatori first e second
    // i quali stamperanno rispettivamente la chiave e il valore
    for ( it = amap.begin(); it != amap.end(); it++)
        cout << "map [" << it->first << "] = " << it->second << endl;
}

#endif // OCCORRENZE_H