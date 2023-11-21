/*
    Esercizio: wordcount

    Progettare ed implementare un programma che utilizzando una Map, conti il
    numero di occorrenze di ogni parola contenuta in un file.
*/

#include "Occorrenze.h"

int main(){

    Occorrenze primo("fileOne.txt");
    primo.readFile();
    primo.printMap();

    return 0;
}