/*
	Implementare un programma che conti le occorrenze di una parola in un file testo
*/

#include <iostream>
#include <fstream>
using namespace std;

class TrovaOcc{
private:
	string find;
	int size,occ = 0,letter = 0;
	fstream file;
public:
	TrovaOcc(string findme){
		this->find = findme;
		this->size = findme.size()-1;
	}
	int Count_Occ(string nome_file){
		file.open(nome_file,ios::in);
		string line;
		while(file){
			file >> line;
			cout << "RIGA:\t" << line << endl;
			if(line == this->find){
				this->occ++;
			}
		}
		return this->occ;
	}
};

int main(){
	string trovami;
	cout << "Inserisci la parola da cercare:";
	cin >> trovami;
	TrovaOcc TO(trovami);
	cout << "Numero di occorrenze trovate: " << TO.Count_Occ("Occorrenze.txt") << endl;
}
