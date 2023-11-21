
#ifndef LIST_H
#define LIST_H
#include "Nodo.h"
#include "Employee.h"

class List {
    private:
        Nodo *head;
        Nodo *last;

        void insHead(Employee *pt);
        void insLast(Employee *pt);

    public:
        List(Nodo *head);
        ~List();

        Nodo *getHead(){return head;}
        Nodo *getLast(){return last;}

        void insNodo(Nodo *nodo,Employee *pt);
        void getList();

        void getSumSalario();
};

List::List(Nodo *head){
    this->head = head;
    this->last = this->head;
}

List::~List(){

    while (this->head != nullptr){
        auto* tmp = head;
        head = head->getNext();
        delete tmp;
    }
}

void List::insNodo(Nodo *nodo,Employee *pt){
    if (nodo == nullptr)
        insHead(pt);
    else
        insLast(pt);
}

void List::insHead(Employee *pt){
    Nodo *new_nodo = new Nodo(nullptr,pt);
    head = new_nodo;
    this->last = head;
}

void List::insLast(Employee *pt){
    Nodo *new_nodo = new Nodo(nullptr,pt);
    last->setNext(new_nodo);
    last = new_nodo;
}

void List::getList(){
    Nodo *tmp = head;

    while (tmp != nullptr){
        tmp->getEmployee()->getInfo();
        tmp = tmp->getNext();
    }
}

void List::getSumSalario(){

    Employee tmp("",0);
    Nodo *scor = head;

    while (scor != nullptr) {
        Employee emp("",scor->getEmployee()->getSalario());

        // in questo caso utilizzo l'overload dell operatore+ 
        tmp = tmp + emp;
        
        scor = scor->getNext();
    }
    cout << endl << endl << "Somma totale dei salari: " << tmp.getSalario() << endl;   
}

#endif // LIST_H