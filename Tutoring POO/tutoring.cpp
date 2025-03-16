//1.Definiti o clasa care sa permita gestiunea datelor aferente temei pentru acasa (cerinte, 
// termen limita, tip fisier de incarcat, puncte etc.) folosind membri de tip: public, private,
// protected, const, static. Clasa contine cel putin un camp alocat dinamic, constructor si doua metode 
// accesor (set va valida valoarea primita pentru un atribut la alegere).
//2. Supraincarcati  operator**valoare care sa permita cresterea puncatjului
//3. Exemplificati in main() mecanismul de tratare a exceptiilor try catch prin modificarea metodei set 
// implementata anterior si prin definirea unei exceptii proprii.
//4. Definiti o metoda care sa permita scrierea/serializarea subiectului intr-un fisier de tip binar. Metoda
//primeste numele fisierului ca parametru.
//5.Sa se exemplifice utilizarea unei relatii de tip "has a" de tip 1:M(unu la mai multi) prin definirea unei 
// clase suplimentare care sa gestioneze o mapa de teme ale unui seminar. Se pot folosi colectii STL.
//6. Supraincarcati un operator la alegere care sa permita adaugarea de teme in mapa definita anterior.
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;
class Tema {
private:
	const int idTema;
protected:
	char* materie;
	string tipTema; //doc, pdf, ppt
	float punctaj;
public:
	static int nrTemeTrimise;//ex. vector alocat static(ii dam de la inceput memorie si stim cat ocupa),
	//alocarea dinamica(pt pointeri)
	
	//constructorul fara parametri default/implicit
	//constructorul implicit cream obiecte fara nimic in ele
	Tema(): idTema(nrTemeTrimise++) {
		this->materie = new char[strlen("Anonim") + 1];// asa alocam memorie pentru vector;
		strcpy(this->materie, "Anonim");
		this->tipTema = "Nu stiu";
		this->punctaj = 0.0;
	}
	//constructorul cu toti parametrii
	Tema(const char*materie, string tipTema, float punctaj):idTema(nrTemeTrimise) {
		this->materie = new char[strlen("Anonim") + 1];// asa alocam memorie pentru vector;
		strcpy(this->materie, materie);
		this->tipTema = tipTema;
		this->punctaj = punctaj;
	}
	//  cand spune 2 metode accesor (si nu specifica exact daca vor getter sau setter, 
	// faceti o pereche de get si set)

	//getter - functie/metoda accesor care permite extragerea valorii unui atribut din clasa
	float getPunctaj(){
		return this->punctaj;
	}
	const int getIdTema() {
		return this->idTema;
	}
	char* getMaterie() {
		return this->materie;
	}
	string getTipTema() {
		return this->tipTema;
	}
	//setter - functie/metoda accesor care permite modificarea valorii unui atribut din clasa
	void setPunctaj(float punctaj) {
		if(punctaj>= 0.0 && punctaj<=10)
		this->punctaj = punctaj;
	}

	//operator += (valoare)
	Tema& operator +=(float valoare) {
		this->punctaj = punctaj + valoare;
		return *this;

	}

	friend ostream& operator<<(ostream& out, const Tema& t) {
		out << t.idTema << endl;
		out << t.materie << endl;
		out << t.tipTema << endl;
		out << t.punctaj << endl;
		return out;
	}
};

int Tema::nrTemeTrimise = 0;
//ostream& operator<<(ostream& out, Tema t) {
//	out << t.getIdTema() << endl;
//	out << t.getMaterie()<< endl;
//	out << t.getTipTema() << endl;
//	out << t.getPunctaj() << endl;
//	return out;
//}
int main() {
	//obiect construit pe baza constructorului fara parametri
	Tema t;
	cout << t.getPunctaj() << endl;
	t.setPunctaj(7.7);
	t.setPunctaj(15.7);
	cout << t.getPunctaj() << endl;
	cout << endl << endl;
	char aux[50] = "ATP";
	Tema t1(aux, "PPT", 8.6);
	cout << t1.getPunctaj() << endl;
	cout << endl << endl;

	cout << t1 << endl;
	t1 += 2.2;
	cout << t1 << endl;


}