#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//trebuie sa folositi fisierul masini.txt
//sau va creati un alt fisier cu alte date

struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina; //- un alias sa nu mai scriu struct StructuraMasina = Masina (doar masina))

void afisareMasina(Masina masina) {
	//afiseaza toate atributele unei masini
	printf("ID:%d\n", masina.id);
	printf("Numar usi:%d\n", masina.nrUsi);
	printf("Pret:%.2f\n", masina.pret);
	printf("Model:%s\n", masina.model);
	printf("Nume sofer:%s\n", masina.numeSofer);// %s pentru ca este un sir de caractere;
	printf("Serie:%c\n\n", masina.serie); //%c, este un char, un singur caracter;

}
// sa parcugem vectorul pe care-l primim si pentru fiecare vom apela acest afisare masina, 
// in vectorul nostru avem mai multe masini
void afisareVectorMasini(Masina* masini, int nrMasini) {
	//afiseaza toate elemente de tip masina din vector
	//prin apelarea functiei afisareMasina()
	for (int i = 0; i < nrMasini; i++) {
		afisareMasina(masini[i]);
	}

}
//adaugam la finalul vectorului, de ex. daca avem 3 masini si vrem sa adaugam una noua, vom aloca spatiu 
// pentru 4 masini si in noua pozitie goala adaugam o masina noua; luam un aux* si ii alocam spatiu de 
// cate elem aveam +1; 
void adaugaMasinaInVector(Masina** masini, int* nrMasini, Masina masinaNoua) {
	//adauga in vectorul primit o noua masina pe care o primim ca parametru
	//ATENTIE - se modifica numarul de masini din vector;
	Masina* aux = (Masina*)malloc(sizeof(Masina) * ((*nrMasini) + 1));
	for(int i =0; i < *nrMasini; i++){
		aux[i] = (*masini)[i]; //facem shallow copy
	}
	aux[(*nrMasini)] = masinaNoua;
	free(*masini);
	(*masini) = aux;
	(*nrMasini)++;
}

Masina citireMasinaFisier(FILE* file) {
	//functia citeste o masina dintr-un strceam deja deschis, (dintr-un fisier)
	//masina citita este returnata;
	Masina m;
	//avem nevoie de un buffer pe care-l alocam static
	char buffer[100];//il aloc in cadrul functiei, se va aloca pe stiva de memorie a acestei functii, 
	//cand functia se termina si el va fi sters ca va fi stearsa stiva;
	//in acest buffer vom citi intreaga linie din fisier
	//strtok primeste ca parametru
	char sep[4] = ",;\n"; //am alocat spatiu pentru 4 (desi noi avem 3)ca este este sir de caractere + 
	//pt sf de sir de caractere;
	// fgets - utilizata pentru a citi un sir de caractere (linie de text) dintr-un fisier 
	fgets(buffer, 100, file);
	//strtok() este utilizata pentru a imparti un sir de caractere in token-uri (subsiruri) 
	// pe baza unui set de delimitatori.
	m.id = atoi(strtok(buffer, sep));
	m.nrUsi = atoi(strtok(NULL, sep));
	m.pret = atof(strtok(NULL, sep));
	char* aux;//il folosim ca sa obtinem 'Astra' - modelul masinii; in aux avem sirul de caractere Astra;
	aux = strtok(NULL, sep);
	m.model = (char*)malloc(strlen(aux) + 1); //sizeof(char) = 1;
	strcpy(m.model, aux);

	aux = strtok(NULL, sep);
	m.numeSofer = (char*)malloc(strlen(aux) + 1);
	strcpy(m.numeSofer, aux);
	m.serie = strtok(NULL, sep)[0];
	return m;

}

Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrMasiniCitite) {
	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
	//prin apelul repetat al functiei citireMasinaFisier()
	//numarul de masini este determinat prin numarul de citiri din fisier
	//ATENTIE - la final inchidem fisierul/stream-ul

	FILE* file = fopen(numeFisier, "r");
	Masina* masini = NULL;
	(*nrMasiniCitite) = 0;
	while (!feof(file)) {
		adaugaMasinaInVector(&masini, nrMasiniCitite, citireMasinaFisier(file));
	}
	fclose(file);
	return masini;
}

void dezalocareVectorMasini(Masina** vector, int* nrMasini) {
	//este dezalocat intreg vectorul de masini
	for (int i = 0; i < *nrMasini; i++) {
		if (((*vector)[i].model) != NULL) {
			free((*vector)[i].model);
		}
		if (((*vector)[i].numeSofer) != NULL) {
			free((*vector)[i].numeSofer);
		}
		
	}
	free(*vector);
	*vector = NULL;
	(*nrMasini) = 0;
}

int main() {
	int nrMasini = 0;
	Masina* masini = citireVectorMasiniFisier("masini.txt", &nrMasini);
	afisareVectorMasini(masini, nrMasini);
	dezalocareVectorMasini(&masini, &nrMasini);

	return 0;
}