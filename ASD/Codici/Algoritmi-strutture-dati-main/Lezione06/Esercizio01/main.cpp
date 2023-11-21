/*
    •   Un'azienda è quotata in borsa. Si supponga di avere un array
        A[1...N] contenente la quotazione delle azioni in un periodo di
        N giorni e che A[1]<A[N]. È possibile dimostrare che esiste
        almeno una coppia di giorni consecutivi i, i+1 tali che A[i]<A[i+1].

                            20 15 13 12 21

    •   Progettare ed implementare un algoritmo divide-et-impera che
        trovi un indice i che verifichi la condizione data.
*/
#include <vector>
#include <iostream>

using namespace std;

/*
    dati in input un vettore, il suo inizio e la sua fine
    dati in output indice del risultato richiesto

    questo algoritmo utilizza un approccio divide et impera
    il questo caso abbiamo bisogno di due indici 
    quali inizio e fine, perchè ci serviranno quando
    andremo a lavorare su parti dell'array regolandoci tramite questi due indici

    inizialmente controllo il caso base cioè che nel vector ci siano solo due elementi,
    o anche se abbiamo gia trovato la soluzione, ricordandoci che in realà noi usciremo dal loop 
    della ricorsione soltanto quando uno dei due casi base si verificherà.

    da notare il fatto che questa soluzione funziona dato che ci è stata data una condizione iniziale
    quale che vec[1] < vec[n] di conseguenza abbiamo sicuramente una coppia risultato,
    quindi possiamo avere più risultati giusti per questo problema.

    dopo aver controllato il caso base proseguiamo con la divisione del vector ed andiamo a 
    lavorare ricorsivamente sulla porzione di sinistra se la condizione è verificata
    altrimenti sulla porzione di destra fino a trovare il caso base
*/
int searchCC(vector<int> vec, int inizio, int fine){

    // nel caso in cui il vettore sia composto da due elementi
    // ritorna il suo inizio, o nel caso un cui gia abbiamo la soluzione
    // esci dalla function
    if (inizio + 1 == fine || vec.at(inizio) < vec.at(inizio+1))
        return inizio;

    // a questo punto calcolo il mediano
    int mediano = (inizio+fine)/2;

    // vedo se la condizione è vera allora vado nella 
    // prima parte del vettore altrimenti nella parte di destra
    if (vec.at(inizio) < vec.at(mediano))
        return searchCC(vec,inizio,mediano);
    return searchCC(vec,mediano,fine);
}

int main(){

    vector<int> vec = {20,19,18,17,21};

    int ris = searchCC(vec,0,4);

    cout << ris << endl;
    cout << vec.at(ris) << endl;
    cout << vec.at(ris+1) << endl;

    return 0;
}