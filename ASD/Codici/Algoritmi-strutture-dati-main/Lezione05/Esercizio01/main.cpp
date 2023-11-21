/*
    Esercizio: gioco del 15

    Il gioco del 15 consiste nel disporre le celle da 1 a 15 per riga in una matrice
    4x4. Avendo a disposizione una sola cella vuota, è possibile spostare solo le
    celle adiacianti alla cella vuota, in orizzontale ed in verticale.

    *** REPLACE EX FERONE *** VERIFICA LA SEQUENZA SE È CORRETTA

                        13  10  11  6
                        5   7   4   8
                        1   12  14  9
                        3   15  2

    Progettare ed implementare un programma che legga da file una
    configurazione del gioco e verifichi se rappresenta la soluzione, usando un
    contenitore della STL.

    Implementare una versione parallella che, usando i thread, consenta di
    verificare più file contemporaneamente.
*/
#include "Verificatore.h"
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

// dichiarazione del mutex 
// che verrà utilizzato per le sizioni critiche
mutex mut;

void funz(string);
int main(){

    // SOLUZIONE SEQUENZIALE
    cout << endl << "File Verificati con programmazione sequenziale!!!" << endl;
    Verificatore verifyOne("fileOne.txt");
    Verificatore verifyTwo("fileTwo.txt");

    verifyOne.check();
    verifyOne.getSoluzione();
    verifyOne.getInfoFileRange();

    verifyTwo.check();
    verifyTwo.getSoluzione();
    verifyTwo.getInfoFileRange();

    // SOLUZIONE CONCORRENTE
    cout << endl << "File Verificati con programmazione conccorrente!!!" << endl;

    vector<thread> th;

    // un thread è un'unità di elaborazione, i thread sono concorrenti fra di loro
    // eccetto per le sezioni critiche, che avvengono in mutua esclusione
    // quindi eseguono una funzione presa in input, in questo caso 'funz'
    th.push_back(thread(funz,"fileOne.txt"));
    th.push_back(thread(funz,"fileTwo.txt"));

    // una volta dichiarati e dopo avergli assegnato una funzione
    // allora abbiamo bisgno di effettura il join fra i thread
    // che devono lavorare allo stesso tempo
    // in questo caso effettuo il join utilizzando il range-for
    // il quale utilizza gli iteratori per scorrere tutto il vector dei thread
    // dato che sto effettuando un operazione su di essi ho bisogno di utilizzare
    // un riferimento ai thread quindi utilizzo '&'
    for (auto& j: th)
        j.join();

    return 0;
}

/*
    funz è una funzione assegnata ai thread per andare a fare il check dei file
    prende in input il nome del file e esegue i vari metodi per ottenere
    la verifica utilizzando la classe Verificatore
*/
void funz(string nomeF){

    Verificatore ver(nomeF);
    ver.check();

    // con .lock() entriamo in sezione critica
    // in questo caso abbiamo una risorsa condivisa,
    // quale lo schermo, quindi di conseguenza abbiamo 
    // bisogno di fare operazioni di stampa in sezione critica
    // quindi un thread alla volta, per evitare stampe sbagliate
    mut.lock();

    ver.getSoluzione();
    ver.getInfoFileIte();

    // con .unlock() usciamo dalla sezione critica
    mut.unlock();
}