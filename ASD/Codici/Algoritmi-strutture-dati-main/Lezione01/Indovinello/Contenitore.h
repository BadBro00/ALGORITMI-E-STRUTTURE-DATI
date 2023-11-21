/*
    • Classe Contenitore
        – Generico contenitore d'acqua: ha un attributo qt che memorizza
        la quantità d'acqua, un metodo versa(lt) per versare acqua, un
        metodo togli(lt) per togliere acqua ed un metodo getQt() che
        restituisce il valore di qt.
*/
#ifndef CONTENITORE_H
#define CONTENITORE_H
#include <iostream>

class Contenitore{

    private:
        int qt;

    public:
        Contenitore(int qt);
        virtual ~Contenitore();

        int getQt(){return qt;}

    protected:
        // versa e togli sono due metodi che vengono utilizzati
        // dal metodo spostaContenuto presente nella classe Anfora
        // la classe Anfora eredita Contenitore, di conseguenza sono protected
        void versa(int lt);
        void togli(int lt);
};

Contenitore::Contenitore(int qt){
    this->qt = qt;
}

Contenitore::~Contenitore(){

}

void Contenitore::versa(int lt){
    this->qt = qt+lt;
}

void Contenitore::togli(int lt){
    this->qt = qt-lt;
}

#endif // CONTENITORE_H
