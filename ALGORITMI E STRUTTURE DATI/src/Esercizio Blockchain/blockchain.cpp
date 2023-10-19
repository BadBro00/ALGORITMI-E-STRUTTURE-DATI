/*La blockchain è una struttura dati composta da una lista di
blocchi all'interno dei quali è memorizzato un insieme di
transazioni. Una transazione è costituita da un indirizzo
FROM, un indirizzo TO ed un valore intero QT.
	1. Progettare ed implementare una struttura dati LinkedList mediante template
		 ed utilizzarla per realizzare una blockchain
	2. Dato un indirizzo A, stampare a video/salvare su file tutte le transazioni
		 in cui compare A ed il suo bilancio finale
*/
#include <iostream>
#include <cstring>
using namespace std;

int glob_id = 0;

class Blocco{
private:
	int ID;
	Blocco *next;
public:
	Blocco(){ID = glob_id++;}
	int getID(){return ID;}
	Blocco *getNext(){return next;}
};

class Transazione{
private:
	string TO,FROM;
	int QT;
	Transazione *next;
public:
	Transazione(string t,string f,int qt) : TO{t},FROM{f},QT{qt} {}
	int getQT(){return QT;}
	string getTO(){return TO;}
	string getFROM(){return FROM;}
	Transazione *getNext(){return next;}
};

template <class T>
class Nodo{
private:
	T *obj;
    Nodo<T> *next;
public:
	Nodo(T data){this->obj = new T(data); next = nullptr;}
	T *getObj(){return obj;}
    Nodo<T> *getNext(){return next;}
    void SetNext(Nodo<T> *n){next = n;}
};

template <class T>
class LList{
private:
	Nodo<T> *h,*t;
public:
	LList(){h=t=nullptr;}
	Nodo<T> *getHead(){return h;}
	Nodo<T> *getTail(){return t;}
	void SetTail(Nodo<T> *nodo){t = nodo;}
	void SetHead(Nodo<T> *nodo){h = nodo;}
	void AddNodo(T data);
	
};

template <class T>
void LList<T>::AddNodo(T data) {
    auto nodo = new Nodo<T>(data);
    if (getHead() == nullptr) {
        h = t = nodo;
        nodo->SetNext(nullptr);
    } else {
        auto n = getTail();
        n->SetNext(nodo);
        t = nodo;
        nodo->SetNext(nullptr);
    }
}

int main(){

}