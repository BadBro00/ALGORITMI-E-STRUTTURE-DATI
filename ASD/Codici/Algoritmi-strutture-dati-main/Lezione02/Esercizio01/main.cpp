/*
    “Rispetta i versi” è un solitario giocato su una griglia
    formata da N caselle separate da un simbolo di
    disuguaglianza; in figura è mostrato un esempio con N = 6.

    L’obiettivo del gioco è quello di riempire le celle vuote con
    tutti i numeri da 1 a N (ogni numero deve comparire
    esattamente una volta), in modo da rispettare le
    disuguaglianze tra caselle adiacenti. Per la griglia della
    figura, una delle possibili soluzioni al rompicapo è la
    seguente:

            2 < 5 > 1 < 3 < 6 > 4

    • Progettare ed implementare una classe che, dati
        – un file Problema.txt contenente diverse istanze del
        problema (una per ogni riga)

        – un file Soluzione.txt contenente una soluzione per ogni
        istanza di problema (una per ogni riga)

        • verifichi se ognuna delle soluzione è corretta rispetto al
        problema e scriva l'esito su un file Esito.txt
*/

#include "Verificatore.h"

using namespace std;

int main(){

    Verificatore gioco("problema.txt","soluzione.txt","esito.txt");
    gioco.check();
    
    return 0;
}