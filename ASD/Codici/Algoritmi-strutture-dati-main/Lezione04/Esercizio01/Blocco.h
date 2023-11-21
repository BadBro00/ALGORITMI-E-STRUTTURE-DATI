
#ifndef BLOCCO_H
#define BLOCCO_H

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Transazione.h"

using namespace std;

class Blocco{
    private:

        // currId è necessario per assegnare un id ad ogni oggetto blocco che si alloca
        // quindi ci conserviamo l'id corrente in un attributo statico
        // e in un attributo non mutabile l'id di quel oggetto blocco
        static int currId;
        const int id;
        LinkedList<Transazione> *listaTx;

    public:
        Blocco():id(currId++),listaTx(new LinkedList<Transazione>){
            cout << "Aggiunto Blocco ID: " << id << endl;
        }
        ~Blocco();

        //setter
        void setListaTx(LinkedList<Transazione> *bloccoObj){this->listaTx = bloccoObj;}

        //getter
        int getId(){return id;}
        LinkedList<Transazione>* getListaTx(){return listaTx;}

        // aggiungi tx al blocco
        void addTx();

        // stampa Tx del blocco
        void getInfoBlocco();

        // ricerca indirizzo
        int searchAddress(string address, int balance);
};

// I blocchi iniziano da 1, ma viene utilizzato
// blocco fittizzio per evitare errori
int Blocco::currId = 0;

Blocco::~Blocco(){
    delete listaTx;
}

// Scorre tutta la lista inerente al quel blocco
// e richiama un metodo per stampare le info nella classe Tx
void Blocco::getInfoBlocco(){
    cout << endl << "ID: " << getId() << endl;
    Nodo<Transazione>* tmp = listaTx->getHead();
    while (tmp != nullptr){
        tmp->getObj()->getInfoTx();
        tmp = tmp->getNext();
    }
}

// Aggiunge Tx nel blocco corrente
void Blocco::addTx(){
    string from;
    string to;
    int qt;

    cout << endl;
    cout << "Inserisci i dati della Transazione nel Blocco ID: " << getId() << endl;
    cout << "- From: "; cin >> from;
    cout << "- To: "; cin >> to;
    cout << "- Qt: "; cin >> qt;
    listaTx->insNodo(listaTx->getLast(), new Transazione(from,to,qt));
}

// Controlla se nelle Tx è presente l'indirizzo preso in input
// Quindi stampa la Tx e esegue la somma algebrica del bilancio
// output Stampo a video le Tx e bilancio di un indirizzo
int Blocco::searchAddress(string address, int balance){

    Nodo<Transazione>* tmp = listaTx->getHead();

    cout << endl << "Le Tx effettuate da " << address << " Nel Blocco ID: " << getId() << " sono:" << endl;
    while (tmp != nullptr){
        if (tmp->getObj()->getFrom() == address){
            tmp->getObj()->getInfoTx();
            balance -= tmp->getObj()->getQt();
        } else if (tmp->getObj()->getTo() == address) {
            tmp->getObj()->getInfoTx();
            balance += tmp->getObj()->getQt();
        }
        tmp = tmp->getNext();
    }
    return balance;
}

#endif // BLOCCO_H