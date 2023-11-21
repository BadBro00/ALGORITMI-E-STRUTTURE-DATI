// ||===Progetto Algoritmi e Strutture Dati -- Militerno Eugenio, mat: 012400/2454===||
// || Inclusione degli Header ||
#include "Headers/AlberoRb.h"
#include "Functions/Functions.cpp"
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    AlbRB A;
    ifstream File;
    File.open("input0_1_1.txt");
    int count=0;
    int j=0;
    string line;
    string txt_val;
    int num;
    char char1,char2;
    int chiave;
    string valore;
    char scelta;
    while (getline(File, line))
        count++;//Aumento count fino all'ultima riga, cosi' da sapere preventivamente la dimensione degli array
    File.close();
    vector<int> allKey(count);
    vector<string> allValue(count);
    File.open("input0_1_1.txt");
    File >> char1 >> num >> char2 >> txt_val;
    //allValue[j] = txt_val;
    //allKey[j] = num;
    j++;
    while (getline(File, line) && File >>char1 >> num >> char2 >> txt_val){
        //Inserimento dei valori negli array per chiave e val
        allValue[j] = txt_val;
        allKey[j] = num;
        //cout << "Chiave Letta: " << num << ", Valore Letto: " << txt_val << endl;
        j++;
    }
    File.close();
    for(int i=0;i<count;i++){
        //Rimozione char finale '>'
        allValue[i].erase(remove(allValue[i].begin(), allValue[i].end(), '>'), allValue[i].end());
    }
    cout << "Chiave: " << " Valore: " << endl;
    for(int k=0;k<10;k++){
        cout << "K = " << k << endl;
        cout << allKey[k] << " \t" << allValue[k] << endl;
        A.Insert(allKey[k],allValue[k]); //Inserimento nell'Albero
    }
    cout << "\n\tInserire un carattere MAIUSCOLO :\n";
    while(true) {
        cout << "\t\t1:(I)| Insert\n\t\t2:(S)| Search\n\t\t3:(D)| Delete\n\t\t4:(P)| Print \n\t\t5:(E)| EXIT\n";
        cin >> scelta;
        switch (scelta) {
            case ('I'):
                cout << "\n\tInserisci Chiave:\n";
                cin >> chiave;
                cout << "\n\tInserisci Valore:\n";
                cin >> valore;
                cout << "\tInserimento nodo con chiave (hashed): " << chiave << " e valore: " << valore << endl;
                A.Insert(chiave, valore);
                break;
            case ('S'):
                cout << "\n\tInserisci ID da Cercare:\n";
                cin >> chiave;
                cout << A.SearchNodo(A.getRoot(),chiave)->GetVal() << "->" << A.SearchNodo(A.getRoot(),chiave)->GetColor() << endl;
                break;
            case ('D'):
                cout << "\n\tInserisci ID da Eliminare:\n";
                cin >> valore;
                A.Delete(chiave);
                break;
            case ('E'):
                exit(0);
            case ('P'):
                cout << "\nAlbero\n";
                A.PrintTree(A.getRoot(),0);
                break;
            default:
                cout << "\n\t\t||CARATTERE NON VALIDO! Inserirne un altro! || \n";
                cin >> scelta;
        }
    }
}
