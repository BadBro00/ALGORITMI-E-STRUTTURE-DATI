#include <iostream>
#include <cmath>

using namespace std;

/*
    L'Overloading è il sovraccarico di una funzione, la quale 
    avrà delle differenze nella sua firma, che possono essere
    o il numero dei parametri di input o anche il tipo dei dati
*/

int Radice(int X) {return int(sqrt(double(X))); }
double Radice(double Y) { return sqrt(Y); }

int main() {

    int A = 1234;
    double B = 56.789;

    cout << "Radice intera di " << A << " = " << Radice(A) << endl;

    cout << "Radice reale di " << B << " = " << Radice(B) << endl;

    return 0;
}