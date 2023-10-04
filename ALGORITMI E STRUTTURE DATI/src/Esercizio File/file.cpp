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