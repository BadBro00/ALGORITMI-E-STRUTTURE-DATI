#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class RispettaIVersi {
public:
    RispettaIVersi(const string& problema_file, const string& soluzione_file, const string& esito_file);
    void verifica_soluzioni();

private:
    bool verifica_soluzione(const string& problema, const string& soluzione);

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
        if (verifica_soluzione(problema, soluzione)) {
            f_esito << "Soluzione errata" << endl;
        } else {
            f_esito << "Soluzione corretta" << endl;
        }
    }
    f_problema.close();
    f_soluzione.close();
    f_esito.close();
}

bool RispettaIVersi::verifica_soluzione(const string& problema, const string& soluzione) {
    vector<int> numeri(soluzione.size());
    for (int i = 0; i < numeri.size(); i++) {
        numeri[i] = i + 1;
    }
    for (int i = 0; i < problema.size(); i++) {
        if (problema[i] == '<' && soluzione[i] >= soluzione[i+1]) {
            return false;
        } else if (problema[i] == '>' && soluzione[i] <= soluzione[i+1]) {
            return false;
        }
    }
    return true;
}

int main(){
    RispettaIVersi rispetta_i_versi("problema.txt", "soluzione.txt", "esito.txt");
    rispetta_i_versi.verifica_soluzioni();
    return 0;
}

/*
Il codice sopra è un'implementazione in C++ di una classe chiamata RispettaIVersi che legge due file di input, 
problema.txt e soluzione.txt, e scrive i risultati della verifica delle soluzioni su un file di output, esito.txt. 
Il problema che viene risolto consiste nel verificare se ogni soluzione in soluzione.txt è corretta rispetto al problema corrispondente in problema.txt. 
Il problema consiste in una sequenza di segni < e >, e la soluzione corretta è una sequenza di interi che soddisfa i segni.

La classe RispettaIVersi ha tre variabili membro private: problema_file_, soluzione_file_ e esito_file_, 
che sono i nomi dei file di input e output. Il costruttore prende questi tre nomi di file come argomenti e inizializza le variabili membro. 
La classe ha anche due funzioni membro private: verifica_soluzione e verifica_soluzioni. La prima prende un problema e 
una soluzione come stringhe e restituisce un booleano che indica se la soluzione è corretta rispetto al problema. La seconda legge i problemi e le soluzioni dai file di input, 
verifica ogni soluzione e scrive i risultati sul file di output.

La funzione verifica_soluzione crea prima un vettore di interi da 1 alla lunghezza della stringa soluzione. Poi itera sulla stringa problema e 
controlla ogni segno rispetto alla coppia corrispondente di interi nella stringa soluzione. Se il segno è < e l'intero a sinistra è maggiore o uguale all'intero a destra,
 o se il segno è > e l'intero a sinistra è minore o uguale all'intero a destra, la funzione restituisce false. Altrimenti, restituisce true.

La funzione verifica_soluzioni apre prima i file di input e output utilizzando ifstream e ofstream, rispettivamente. Poi legge ogni riga dai file di input utilizzando getline, 
verifica la soluzione corrispondente utilizzando verifica_soluzione e scrive il risultato sul file di output utilizzando <<. Infine, chiude tutti i file utilizzando close.

La funzione main crea un'istanza della classe RispettaIVersi con i nomi dei file di input e output, chiama il metodo verifica_soluzioni e restituisce 0 per indicare l'esecuzione corretta.
*/