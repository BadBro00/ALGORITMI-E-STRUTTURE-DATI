
#ifndef MANAGER_H
#define MANAGER_H
#include "Employee.h"
#include <iostream>

using namespace std;

class Manager:public Employee{
    private:
        double bonus;
    public:
        Manager(string nome,double salario, double mBonus);

        // il distruttore di manager è dichiarato virtual
        // per assicurare il giusto funzionamento
        // quindi nel momento in cui si va a distrugere
        // un oggeto di classe manager si va ad invocare 
        // sia il suo distruttore suo che il distruttore 
        // della classe base in questo caso Employee
        virtual ~Manager();

        double getBonus(){return bonus;}

        // getInfo() è un override del metodo 
        // presente nella classe base
        void getInfo();
};

Manager::Manager(string nome,double salario, double mBonus):Employee(nome,salario),bonus(mBonus){

}

Manager::~Manager(){

}

void Manager::getInfo(){
    cout << endl << endl << "Manager" << endl;
    cout << "Nome: " << this->getNome();
    cout << endl << "Salario: " << this->getSalario();
    cout << endl << "Bonus: " << this->getBonus();
}

#endif // MANAGER_H
