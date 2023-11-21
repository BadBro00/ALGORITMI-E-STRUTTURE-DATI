/*
Obiettivo: riempire le celle con numeri da 1 ad N (ogni numero compare 1x), in modo da rispettare le disequazioni.
Progettare una classe che, dati un file prob.txt contenente diverse istanze del problema (una per riga), e un file soluz.txt, verifichi se
ognuna delle soluzioni è corretta, e ne restituisca l'esito in un file esito.txt
*/

#include <iostream>
#include <string.h>
#include <omp.h>
#include <vector>
#include <fstream>
using namespace std;

class Solutore{
private:
	fstream prob,sol,verif;
	string fileProb,fileSol,fileVerif;
public:
	Solutore(string NP,string NS,string NV){
		this->fileProb = NP;
		this->fileSol = NS;
		this->fileVerif;
	}
	~Solutore();
	vector<int> Numeri;
	vector<char> Segni;
	void Open_Files(fstream prob,fstream sol,fstream verif);
	bool Check_Solution();
	bool Check_Versi(fstream NP);
	bool Check_Numeri(fstream NP);
};

void Solutore::Open_Files(fstream prob,fstream sol,fstream verif){
	prob.open(prob);
	if(!prob.is_open(){
		cout << "\t|ERRORE APERTURA FILE PROBLEMA|\n";
		exit(-3);
	}
	if(!sol.is_open{
		cout << "\t|ERRORE APERTURA FILE SOLUZIONE|\n";
		exit(-4);
	}
}

bool Solutore::Check_Versi(fstream NP){
	while(getline(file, line)){
		int line_idx = 0;
		while(getline(NP,'>'){	
			line_idx++;
			Segni.push_back(line[line_idx]);
			cout << "Pushato " << line[line_idx] << endl;	
			std::stringstream ss(line);
			while(getline(ss, line, '<')){
		        	line_idx++;
		        	Segni.push_back(line[line_idx]);
		        	cout << "Pushato " << line[line_idx] << endl;
       			}
		}
	}
}

bool Solutore::Check_Numeri(fstream NP){
	int num;
	while(NP>>num){
		Numeri.push_back(num);
		cout << "Pushato " << num << endl;
	}
}

int main(int argc,char *argv[]){
	string NomeP,NomeS,NomeV;
	if(argc != 4){
		cout << "Uso: ./a.out <np> <file_prob> <file_sol>\n";
		exit(-1);
	}
	int np = atoi(argv[1]);
	if(np < 1){
		cout << "Uso: <np> > 1!\n";
		exit(-2);
	}
	NomeP = argv[2];
	fstream prob(NomeP,ios::in);
	NomeS = argv[3];
	fstream sol(NomeS,ios::in);
	string NomeV = "Verifica.txt";
	omp_set_num_threads(np);
	#pragma omp parallel
	{
		cout << "ciao\n";
		Solutore S;
		S.Open_Files(NomeP,NomeS,NomeV);
		S.Check_Versi(NomeP);
		S.Check_Numeri(NomeP);
	}
}
/*
class Verificatore {
    private:
        fstream problema;
        fstream soluzione;
        fstream esito;
        string nomeP,nomeS,nomeE;
        string lineP,lineS;
        void openAllFile();
        void separaStringa(int numeri[], string &simbol,int siz);
        bool checkSimbol(string lineP,string simbol);
        bool checkConfronti(int numeri[],int siz);
        bool checkNumeri(int numeri[], int siz);
    public:
        Verificatore(string nomeP,string nomeS,string nomeE);
        ~Verificatore();
        void check();
};
Verificatore::Verificatore(string nomeP,string nomeS,string nomeE){
    this->nomeP = nomeP;
    this->nomeS = nomeS;
    this->nomeE = nomeE;
    openAllFile();
}
Verificatore::~Verificatore(){
    problema.close();
    soluzione.close();
    esito.close();
}
void Verificatore::openAllFile(){
    problema.open(nomeP, ios::in);
    soluzione.open(nomeS, ios::in);
    esito.open(nomeE, ios::out);
    if (problema.fail()) cout << "Errone in apertura file" << nomeP << endl;
    if (soluzione.fail()) cout << "Errone in apertura file" << nomeS << endl;
    if (esito.fail()) cout << "Errone in apertura file" << nomeE << endl;
}
void Verificatore::check(){
    int i=0;
    while (!problema.eof()){
        getline(problema,lineP);
        getline(soluzione,lineS);
        int siz = lineP.size();
        int *numeri = new int[siz+1];
        string simbol;
        separaStringa(numeri,simbol,siz);
        if (checkSimbol(lineP,simbol) && checkConfronti(numeri,siz) && checkNumeri(numeri,siz))
            esito << "Corretta" << endl;
        else    
            esito << "Sbagliata" << endl;
        delete(numeri);
        simbol.clear();
    }
}
void Verificatore::separaStringa(int numeri[],string &simbol,int siz){
    size_t pos = 0;
    char *temp = new char[siz+1];
    strcpy(temp, lineS.c_str());
    auto y = 0;
    auto i = 0;
    for (i=0; i<siz; i++){
        numeri[i] = stoi(temp,&pos);
        simbol += temp[pos];
        y = 1;
        temp += pos+y;
    }
    numeri[i] = stoi(temp);
}
bool Verificatore::checkSimbol(string lineP,string simbol){
    return lineP == simbol;
}
bool Verificatore::checkConfronti(int numeri[], int siz){
    int i = 0;
    while (i < siz){ // da verificare condizione
        if (lineP.at(i) == '<' && numeri[i] > numeri[i+1]){
                return false;
        } else if (lineP.at(i) == '>' && numeri[i] < numeri[i+1]){
                return false;
        }
        i+=1;
    }
    return true;
}
bool Verificatore::checkNumeri(int numeri[], int siz){
    sort(numeri, numeri + siz + 1);
    for (int i=0; i<siz; i++){
        if (numeri[i] != (i+1))
            return false;
    }
    return true;
}
*/
