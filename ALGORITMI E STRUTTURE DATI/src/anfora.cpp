#include <iostream>
#include <stdio.h>
using namespace std;

class Contenitore
{
private:
	int qt = 0;

public:
	// Contenitore(int quant){this->qt = quant;}
	void versa(int, Contenitore);
	void togli(int);
	int getQT() { return this->qt; }
	void setQT(int L) { this->qt = L; }
};

class Anfora : public Contenitore
{
private:
	int capacita;

public:
	Anfora(int cap) { this->capacita = cap; }
	int getCapacita() { return this->capacita; }
	void setCapacita();
	void riempi();
	void svuota();
	bool isEmpty();
	bool isFull();
	void SpostaContenuto(Anfora &);
};

class Indovinello
{
private:
	Anfora Tre, Cinque;

public:
	Indovinello(const Anfora &A, const Anfora &B) : Tre(A), Cinque(B) {}
	void Risolvi();
};

void Contenitore ::versa(int L, Contenitore C)
{
	this->togli(L);
	if (C.getQT() < L + C.getQT())
		C.setQT(C.getQT());
	else
		C.setQT(C.getQT() + L);
}

void Contenitore ::togli(int L)
{
	this->setQT(this->getQT() - L);
}

void Anfora ::svuota()
{
	if (this->isEmpty())
		cout << "Nulla da svuotare!\n";
	this->togli(this->getQT());
}

void Anfora ::riempi()
{
	if (this->isFull())
		cout << "Nulla da riempire!\n";
	this->setQT(this->getCapacita());
}

bool Anfora ::isEmpty()
{
	if (this->getQT() == 0)
		return true;
	return false;
}

bool Anfora ::isFull()
{
	if (this->getQT() == this->getCapacita())
		return true;
	return false;
}

void Anfora ::SpostaContenuto(Anfora &A)
{
	if (this->isEmpty() || A.isFull())
		cout << "Non posso travasare\n";
	int Ldiff = min(this->getQT(), A.getCapacita() - A.getQT());
	this->setQT(this->getQT() - Ldiff);
	A.setQT(A.getQT() + Ldiff);
}

void Indovinello ::Risolvi()
{
	cout << "Riempio anfora da 5L\n";
	Cinque.riempi();
	cout << "\nQuantità d'acqua nella tanica da 3L : " << Tre.getQT() << "\nQuantità d'acqua nell'anfora da 5L : " << Cinque.getQT() << endl
		 << endl;
	cout << "Travaso in quella da 3L\n";
	Cinque.SpostaContenuto(Tre);
	cout << "\nQuantità d'acqua nella tanica da 3L : " << Tre.getQT() << "\nQuantità d'acqua nell'anfora da 5L : " << Cinque.getQT() << endl
		 << endl;
	cout << "Svuoto quella da 3L\n";
	Tre.svuota();
	cout << "\nQuantità d'acqua nella tanica da 3L : " << Tre.getQT() << "\nQuantità d'acqua nell'anfora da 5L : " << Cinque.getQT() << endl
		 << endl;
	cout << "Travaso i 2L in quella da 3L\n";
	Cinque.SpostaContenuto(Tre);
	cout << "\nQuantità d'acqua nella tanica da 3L : " << Tre.getQT() << "\nQuantità d'acqua nell'anfora da 5L : " << Cinque.getQT() << endl
		 << endl;
	cout << "Riempio tanica da 5L\n";
	Cinque.riempi();
	cout << "\nQuantità d'acqua nella tanica da 3L : " << Tre.getQT() << "\nQuantità d'acqua nell'anfora da 5L : " << Cinque.getQT() << endl
		 << endl;
	cout << "Verso l'acqua dall'anfora da 5L in quella da 3L\n";
	Cinque.SpostaContenuto(Tre);
	cout << "\nQuantità d'acqua nella tanica da 3L : " << Tre.getQT() << "\nQuantità d'acqua nell'anfora da 5L : " << Cinque.getQT() << endl
		 << endl;
	cout << "Risolto!\n";
}

int main()
{
	Anfora Tre(3), Cinque(5);
	Indovinello I(Tre, Cinque);
	// I.Risolvi();
	// Menu
	int Gioco, Azione, Anf;
	while (true)
	{
		cout << "\n\tScegli un'opzione:\n1)Giocare\n2)Risoluzione\n0)Uscire\n";
		cin >> Gioco;
		switch (Gioco)
		{
		case 0:
			return 0;
			break;
		case 2:
			I.Risolvi();
			break;
		case 1:
			while (true)
			{
				if (Cinque.getQT() == 4)
				{
					cout << "\t\t|HAI VINTO!|\n";
					return 0;
				}
				cout << "Scegli che fare:\n1)Riempi\n2)Svuota\n3)Travasa\n4)Indietro\n";
				cin >> Azione;
				switch (Azione)
				{
				case 1:
					cout << "Scegli l'anfora da riempire:\n3L (1)\n5L (2)\n";
					cin >> Anf;
					if (Anf == 1)
						Tre.riempi();
					else
						Cinque.riempi();
					cout << "\t\t|STATO ANFORE|\n\t Tre : " << Tre.getQT() << "\n\t Cinque : " << Cinque.getQT() << endl
						 << endl;
					if (Cinque.getQT() == 4)
					{
						cout << "\t\t|HAI VINTO!|\n";
						return 0;
					}
					break;
				case 2:
					cout << "Scegli l'anfora da svuotare:\n3L (1)\n5L (2)\n";
					cin >> Anf;
					if (Anf == 1)
						Tre.svuota();
					else
						Cinque.svuota();
					cout << "\t\t|STATO ANFORE|\n\t Tre : " << Tre.getQT() << "\n\t Cinque : " << Cinque.getQT() << endl
						 << endl;
					if (Cinque.getQT() == 4)
					{
						cout << "\t\t|HAI VINTO!|\n";
						return 0;
					}
					break;
				case 3:
					cout << "Scegli l'anfora da cui spostare:\n3L (1)\n5L (2)\n";
					cin >> Anf;
					if (Anf == 1)
						Tre.SpostaContenuto(Cinque);
					else
						Cinque.SpostaContenuto(Tre);
					cout << "\t\t|STATO ANFORE|\n\t Tre : " << Tre.getQT() << "\n\t Cinque : " << Cinque.getQT() << endl
						 << endl;
					if (Cinque.getQT() == 4)
					{
						cout << "\t\t|HAI VINTO!|\n";
						return 0;
					}
					break;
				case 0:
					return 0;
					break;
				case 4:
					break;
				default:
					cout << "\t|Scelta non valida!|\nImmetterne un'altra\n";
					cin >> Azione;
					break;
				}
			}
		}
	}
}