//
#ifndef VERIFICATORE_H
#define VERIFICATORE_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

class Verificatore {
    
    private:

        // la fstream permette di aprire file sia in scrittura 
        // che in letture, caratteristica che verrà specificata
        // quando saranno aperti in file, possono essere aperti
        // anche sia in scrittura e in lettura
        fstream problema;
        fstream soluzione;
        fstream esito;

        string nomeP,nomeS,nomeE;
        string lineP,lineS;

        void openAllFile();
        void separaStringa(int numeri[], string &simbol,int siz);

        bool checkSimbol(string lineP,string simbol);
        bool checkConfronti(int numeri[],int siz);
        bool checkNumeri(int numeri[], int siz);

    public:
        Verificatore(string nomeP,string nomeS,string nomeE);
        ~Verificatore();

        void check();
};

Verificatore::Verificatore(string nomeP,string nomeS,string nomeE){
    this->nomeP = nomeP;
    this->nomeS = nomeS;
    this->nomeE = nomeE;

    openAllFile();
}

Verificatore::~Verificatore(){

    // Chiudo tutto i file
    problema.close();
    soluzione.close();
    esito.close();
}

void Verificatore::openAllFile(){

    // Apri file in letture
    problema.open(nomeP, ios::in);
    soluzione.open(nomeS, ios::in);

    // Apri file in scrittura
    esito.open(nomeE, ios::out);

    if (problema.fail()) cout << "Errone in apertura file" << nomeP << endl;
    if (soluzione.fail()) cout << "Errone in apertura file" << nomeS << endl;
    if (esito.fail()) cout << "Errone in apertura file" << nomeE << endl;
}

void Verificatore::check(){

    int i=0;

    // letti tutto il file finchè non è finito
    while (!problema.eof()){

        // la getline prende la prima riga del file
        // e la salva nella stringa
        getline(problema,lineP);
        getline(soluzione,lineS);

        int siz = lineP.size();
        int *numeri = new int[siz+1];
        string simbol;

        separaStringa(numeri,simbol,siz);

        if (checkSimbol(lineP,simbol) && checkConfronti(numeri,siz) && checkNumeri(numeri,siz))
            esito << "Corretta" << endl;
        else    
            esito << "Sbagliata" << endl;
        delete(numeri);
        simbol.clear();
    }
}

void Verificatore::separaStringa(int numeri[],string &simbol,int siz){

    // la stoi(string to int) prende in input come secondo parametro
    // un puntatore di tipo size_t che sarebbe la posizione tornata
    size_t pos = 0;

    char *temp = new char[siz+1];

    // la c_str è un metodo eseguito su una stringa che ritorna la stessa
    // ma come array di char, che successivamente andiamo a copiare attraverso la strcpy
    strcpy(temp, lineS.c_str());

    auto y = 0;
    auto i = 0;

    // la stoi(string to int) converte una stringa in un intero
    // la stringa deve iniziare con un numero
    // ed al primo carattere il metodo si ferma e ritorna la posizione 
    // attraverso il secondo parametre che riceve in input di tipo size_t
    // inoltre prende in input un terzo parametro che di default è 10(base)
    for (i=0; i<siz; i++){
        numeri[i] = stoi(temp,&pos);
        simbol += temp[pos];
        y = 1;
        temp += pos+y;
    }

    numeri[i] = stoi(temp);
}

bool Verificatore::checkSimbol(string lineP,string simbol){
    return lineP == simbol;
}

bool Verificatore::checkConfronti(int numeri[], int siz){

    int i = 0;

    while (i < siz){ // da verificare condizione
        if (lineP.at(i) == '<' && numeri[i] > numeri[i+1]){
                return false;
        } else if (lineP.at(i) == '>' && numeri[i] < numeri[i+1]){
                return false;
        }
        i+=1;
    }
    return true;
}

bool Verificatore::checkNumeri(int numeri[], int siz){
    sort(numeri, numeri + siz + 1);

    for (int i=0; i<siz; i++){
        if (numeri[i] != (i+1))
            return false;
    }
    return true;
}

#endif // VERIFICATORE_H