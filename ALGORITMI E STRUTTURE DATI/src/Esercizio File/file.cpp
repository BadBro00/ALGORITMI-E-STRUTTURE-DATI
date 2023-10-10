#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


class RispettaIVersi {
public:
    RispettaIVersi(const string& problema_file, const string& soluzione_file, const string& esito_file);
    void verifica_soluzioni();

private:
    bool verifica_soluzione(const string& problema, const string& soluzione, const vector<int>& numeri);

    string problema_file_;
    string soluzione_file_;
    string esito_file_;
};

RispettaIVersi::RispettaIVersi(const string& problema_file, const string& soluzione_file, const string& esito_file)
    : problema_file_(problema_file), soluzione_file_(soluzione_file), esito_file_(esito_file) {}

void RispettaIVersi::verifica_soluzioni() {
    ifstream f_problema(problema_file_);
    ifstream f_soluzione(soluzione_file_);
    ofstream f_esito(esito_file_);
    string problema, soluzione;
    while (getline(f_problema, problema) && getline(f_soluzione, soluzione)) {
        vector<int> numeri;
        numeri.reserve(soluzione.size());
        for (int i = 0; i < numeri.capacity(); i++) {
            numeri.emplace_back(i + 1);
        }
        if (verifica_soluzione(problema, soluzione, numeri)) {
            f_esito << "Soluzione corretta" << endl;
        } else {
            f_esito << "Soluzione errata" << endl;
        }
    }
    f_problema.close();
    f_soluzione.close();
    f_esito.close();
}

bool RispettaIVersi::verifica_soluzione(const string& problema, const string& soluzione, const vector<int>& numeri) {
    for (int i = 0; i < problema.size(); i++) {
        if (problema[i] == '<' && soluzione[numeri[i]-1] >= soluzione[numeri[i+1]-1]) {
            return true;
        } else if (problema[i] == '>' && soluzione[numeri[i]-1] <= soluzione[numeri[i+1]-1]) {
            return true;
        }
    }
    return false;
}

int main(){
    RispettaIVersi rispetta_i_versi("problema.txt", "soluzione.txt", "esito.txt");
    rispetta_i_versi.verifica_soluzioni();
    return 0;
}

/*
Il codice sopra è scritto in C++ e definisce una classe RispettaIVersi che legge due 
file di testo (problema_file e soluzione_file) e verifica se le soluzioni rispettano 
i vincoli specificati nel file di problema. La classe ha un costruttore che prende 
i nomi dei file di input e di output come parametri e un metodo verifica_soluzioni 
che legge le soluzioni dal file di input, verifica se rispettano i vincoli e scrive 
l'esito nel file di output.

La funzione verifica_soluzione prende tre parametri: la stringa problema, 
la stringa soluzione e il vettore numeri. La funzione utilizza il vettore numeri 
per associare un numero a ciascun carattere della stringa soluzione e verifica se 
la soluzione rispetta i vincoli specificati nella stringa problema. In particolare, 
la funzione utilizza un ciclo for per scorrere i caratteri della stringa problema e 
confronta i caratteri della stringa soluzione utilizzando gli indici del vettore numeri.

La funzione main crea un oggetto RispettaIVersi con i nomi dei file di input e
di output e chiama il metodo verifica_soluzioni per verificare le soluzioni.
*/