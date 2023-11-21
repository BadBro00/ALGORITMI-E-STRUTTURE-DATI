#include <iostream>

using namespace std;

/*
    Il riferimento di una variabile può essere considerato come
    un secondo nome di una variabile (alias)
    Essa opera direttamente alla cella di memoria della variabile
    a cui fa riferimento.
    La differenza sostanziale col puntatore è che il riferimento
    una volta instanziato non può essere più modificato, e la sintassi

    NB: Gestito con Overloading
*/

void swap(int *A, int *B){
    int T;
    T = *A;
    *A = *B;
    *B = T;
}

void swap(int &A, int &B){
    int T;
    T = A;
    A = B;
    B = T;
}

int main(){

    int a = 0, b = 1;
    cout << "\nA: " << a << " B: " << b << endl; 

    swap(&a,&b);
    cout << "Swap con Puntatori A: " << a << " B: " << b << endl;

    swap(a,b);
    cout << "Swap con Riferimenti A: " << a << " B: " << b << endl;

    return 0;
}