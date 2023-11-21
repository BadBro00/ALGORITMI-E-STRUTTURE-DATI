
#ifndef VERIFICATORE_H
#define VERIFICATORE_H

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Verificatore{
    private:
        ifstream file;
        string nomeF;
        bool soluzione;

        // Contenitore presente nella STL
        vector<int> numbers;

        void openFile();
        void readNum();
        bool checkSeq();
    public:
        Verificatore(string nomeF);
        ~Verificatore();

        void check();
        void checkThread();

        void getSoluzione();
        void getInfoFileIte();
        void getInfoFileRange();
};

Verificatore::Verificatore(string nomeF){
    this->nomeF = nomeF;
    openFile();
}

Verificatore::~Verificatore(){
    file.close();
}

void Verificatore::openFile(){
    file.open(nomeF, ios::in);
    if (!file.is_open()) cout << "Errone in apertura file" << nomeF << endl;
}

void Verificatore::check(){
    readNum();
    soluzione = checkSeq();
}

void Verificatore::readNum(){
    int word;
    while ( file >> word ){ // legg doc
        numbers.push_back(word);
    }
}

bool Verificatore::checkSeq(){

    // nel caso in cui i numeri sono più di 15 
    // la soluzione gia è sbagliata
    if (numbers.size() != 15)
        return false;

    for (int i=0; i<numbers.size(); i++)
        if (numbers.at(i) != i+1)
            return false;
    return true;
}

void Verificatore::getInfoFileIte(){
    cout << "Stampo le info tramite iteratori:" << endl;

    // dichiaro un iteratore constante esso si caratterizza 
    // sul fatto che è constante, ed ha bisogno dello scop
    // al momento della sua dichiarazione
    vector<int>::const_iterator cii;

    // Stampo tutto il vector andando ad utilizzare gli iteratori
    // quali begin che punta alla prima cella del vector
    // e end che punta alla prima cella nulla del vector
    // da fare molta attenzione all'uso del != con l'iteratore
    // e il ritorno della funzione end() se usiamo il < funziona lo stesso, ma non è corretto
    for (cii = numbers.begin(); cii != numbers.end(); cii++){
        cout << *cii << " ";
        if ( ((numbers.end()-cii)%4) == 0 )
            cout << endl;
    }
    cout << endl;
}

void Verificatore::getInfoFileRange(){
    cout << endl << "Stampo le info tramite range-for:" << endl;

    // In questo caso utilizzo il range-for, il quale memorizza
    // il valore del vecotr puntato nella variabile temporanea
    // in questo caso 'x', il range-for oscura l'utilizzo
    // degli iteratori, ma anche lui utilizza gli iteratori,
    // infatti può essere utilizzato sono con contenitori
    // che possono utilizzare gli iteratori
    for (auto x: numbers)
        cout << x << " ";
    cout << endl;
}

void Verificatore::getSoluzione(){
    if (soluzione)
        cout << endl << "Bene, Questo file: " << nomeF << " è corretto" << endl;
    else
        cout << endl << "Il file: " << nomeF << " non è corretto" << endl;
}

#endif // VERIFICATORE_H