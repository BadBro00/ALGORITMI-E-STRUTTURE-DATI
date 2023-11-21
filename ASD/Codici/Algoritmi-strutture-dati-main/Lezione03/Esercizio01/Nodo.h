
#ifndef NODO_H
#define NODO_H
#include "Employee.h"

using namespace std;

class Nodo{
    private:
        Nodo *Next;
        Employee *Emp;

    public:
        Nodo(Nodo *Next,Employee *Emp);
        ~Nodo();

        void setNext(Nodo *Next){this->Next = Next;}

        Nodo *getNext(){return Next;}
        Employee *getEmployee(){return Emp;}
};

Nodo::Nodo(Nodo *Next,Employee *Emp){
    this->Next = Next;
    this->Emp = Emp;
}

Nodo::~Nodo(){
    delete Next;
    delete Emp;
}

#endif // NODO_H
