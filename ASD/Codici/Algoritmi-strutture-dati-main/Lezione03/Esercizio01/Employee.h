
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <iostream>

using namespace std;

class Employee{
    private:
        string nome;
        double salario;
    public:
        Employee(string nome,double salario);

        // il distruttore della classe base è reso virtual
        // per assicurare il giusto funzionamento di esso
        // nel momento in cui si va a distruggere un oggetto
        // della classe derivata, quindi
        // vengono chiamati sia il distrutto della classe base
        // che il distruttore della classe derivata
        virtual ~Employee();

        void setSalario(double salario){this->salario = salario;}

        string getNome(){return nome;}
        double getSalario(){return salario;}

        // il metodo getInfo() è reso virtual
        // simmone eseguiamo override
        // nella classe derivata
        // così da utilizzare la tecnica del polimorfismo
        virtual void getInfo();

        // il metodo operator+ è un overloading
        // dell' operatore +
        // essa deve ritornare un oggetto della classe in questione
        // e ricevere un parametro in input della classe in questione
        // per poi andare a modificare il semplice utilizzo dell'operatore
        // implementato nella getSumSalario() nella classe List
        Employee operator+(Employee due);
};

Employee::Employee(string nome,double salario){
    this->nome = nome;
    this->salario = salario;
}

Employee::~Employee(){

}

void Employee::getInfo(){
    cout << endl << endl << "Employee" << endl;
    cout << "Nome: " << getNome();
    cout << endl << "Salario: " << getSalario();
}

Employee Employee::operator+(Employee due){
    Employee tmp("",0);
    tmp.setSalario(this->getSalario() + due.getSalario());
    return tmp;
}

#endif // EMPLOYEE_H
