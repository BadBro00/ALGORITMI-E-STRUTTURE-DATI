/*
    Progettare ed implementare una lista (linked list) di
    impiegati di un'azienda. Un impiegato ha un nome ed un
    salario. Un manager è un impiegato cui viene corrisposto
    un bonus oltre al salario.

    1. Creare una lista di impiegati e stamparla a video
        sfruttando il principio del polimorfismo
    2. Implementare l'overload dell'operatore + in modo da
        sommare i salari di tutti gli impiegati.
*/

#include <iostream>
#include "Employee.h"
#include "Manager.h"
#include "List.h"
#include <vector>

using namespace std;

int main(){

    // istanzio un nuovo oggetto della classe List
    List *lista = new List(nullptr);

    // inserisco gli elementi nella lista
    lista->insNodo(lista->getLast(),new Manager("Attilio",1800.00,100.00));
    lista->insNodo(lista->getLast(),new Employee("Jeppy",1100.00));
    lista->insNodo(lista->getLast(),new Employee("Luca",1600.00));
    lista->insNodo(lista->getLast(),new Manager("Jimmy",2200.00,200.00));
    lista->insNodo(lista->getLast(),new Manager("Alessia",2200.00,200.00));
    lista->insNodo(lista->getLast(),new Employee("Angela",2200.00));

    // stampo le info usando la tecnica del polimorfismo
    lista->getList();

    // stampo la somma dei salari senza bonus 
    // NB: la somma è 11.100
    lista->getSumSalario();

    return 0;
}