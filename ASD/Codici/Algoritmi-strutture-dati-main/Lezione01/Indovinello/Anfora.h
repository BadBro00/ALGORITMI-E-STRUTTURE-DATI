/*
    • Classe Anfora
        – È un Contenitore: ha un attributo capacita che definisce la
        capienza dell'anfora, un metodo getCapacita() che restituisce
        questo valore, un metodo riempi() per riempirla, un metodo
        svuota() per svuotarla, due metodi isVuota() e isPiena() che
        restituiscono lo stato dell'anfora ed un metodo
        spostaContenuto(Anfora) che sposta l'acqua nell'anfora
        passata come argomento.
*/
#ifndef ANFORA_H
#define ANFORA_H
#include <iostream>
#include "Contenitore.h"

using namespace std;

class Anfora:public Contenitore {
    
    private:
        int const capacita;

        // medoti privati siccome vengono utilizzati 
        // esclusivamente all'interno della classe
        bool isVuota();
        bool isPiena();

    public:
        Anfora(int capacita, int qt);
        virtual ~Anfora();

        int getCapacita(){return this->capacita;}

        // riempi, svuota e spostaContenuto sono due metodi che vengono richiamati
        // anche dal metodo risolvi presente nella classe Indovinello
        // di conseguenza devono essere public
        void riempi();
        void svuota();
        void spostaContenuto(Anfora &a);
};

Anfora::Anfora(int capacita, int qt):Contenitore(qt),capacita(capacita){
    
}

Anfora::~Anfora(){

}

void Anfora::riempi(){
    this->versa(this->getCapacita()-this->getQt());
}

void Anfora::svuota(){   
    this->togli(this->getQt());
}

bool Anfora::isVuota(){

    if (this->getQt() == 0)
        return true;
    else
        return false;   
}

bool Anfora::isPiena(){

    if (this->getQt() == this->getCapacita())
        return true;
    else
        return false;
}

/*
    Metodo public
    In input passiamo il riferimento dell'Anfora al quale vogliamo versare acqua
    Come output avremo la qt versata.
*/
void Anfora::spostaContenuto(Anfora &a){

    if (!this->isVuota()){ // se l'anfora dal quale prendiamo acqua non è vuota
        if (!a.isPiena()){ // e se l'anfora nel quale dobbiamo mettere acqua non è piena
            
            // prendo i litri che posso inserire nell'Anfora passata in input(nel caso sia vuota prendo la capacità)
            int lt = a.getCapacita() - a.getQt();

            // nel caso in cui questi litri siamo maggiori di quello che dobbiamo andare a versare allora versa 
            // la qt presente nell'Anfora che usiamo per versare
            if (lt > this->getQt())
                lt = this->getQt();

            a.versa(lt);
            this->togli(lt);
        }
    }
}

#endif // ANFORA_H

