#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

//adaugare vector
//citire din fisier
//??lista simplu inlnatuita

struct Client {
	int id;
	int varsta;
	char* nume;
	float buget;
	char initialaTata;
};
struct Client initializare(int id, int varsta, const char* nume, float buget, char initiala) {
	struct Client c;
	c.id = id;
	c.varsta = varsta;
	c.nume = (char*)malloc((strlen(nume) + 1) * sizeof(char));
	if (c.nume == NULL) {
		printf("Eroare alocare memorie pentru nume!\n");
		return c; // Evit? copierea în pointer NULL
	}
	strcpy_s(c.nume, strlen(nume) + 1, nume);
	c.buget = buget;
	c.initialaTata = initiala;
	return c;
}

void afisare(struct Client c) {
	printf("ID: %d, varsta: %d\n", c.id, c.varsta);
	printf("Nume: %s\n", c.nume);
	printf("Buget: %.2f\n", c.buget);
	printf("Initiala tata: %c\n", c.initialaTata);
}

void afisareVector(struct Client* vector, int nrElemente) {
	for (int i = 0; i < nrElemente; i++) {
		afisare(vector[i]);
		printf("\n");
	}
}

float calculVarstaMedie(struct Client* clienti, int nrElemente) {
	float suma = 0;
	for (int i = 0; i < nrElemente; i++) {
		suma += clienti[i].varsta;
	}
	return suma / nrElemente;
}

struct Client* copiazaPrimeleNElemente(struct Client* vector, int nrElemente, int nrElementeCopiate) {
	if (nrElementeCopiate > nrElemente || nrElementeCopiate <= 0) {
		return NULL;
	}

	struct Client* v = (struct Client*)malloc(sizeof(struct Client) * nrElementeCopiate);
	if (!v) {
		printf("Eroare alocare memorie!\n");
		return NULL;
	}

	for (int i = 0; i < nrElementeCopiate; i++) {
		v[i].id = vector[i].id;
		v[i].varsta = vector[i].varsta;
		v[i].buget = vector[i].buget;
		v[i].initialaTata = vector[i].initialaTata;

		if (vector[i].nume != NULL) {
			v[i].nume = (char*)malloc(strlen(vector[i].nume) + 1);
			if (!v[i].nume) {
				printf("Eroare alocare memorie pentru nume!\n");
				return NULL;
			}
			strcpy_s(v[i].nume, strlen(vector[i].nume) + 1, vector[i].nume);
		}
		else {
			v[i].nume = NULL;
		}
	}

	return v;
}


void dezalocare(struct Client** vector, int* nrElemente) {
	if (vector == NULL || *vector == NULL || nrElemente == NULL) {
		return;
	}

	for (int i = 0; i < *nrElemente; i++) {
		if ((*vector)[i].nume != NULL) {
			free((*vector)[i].nume);
			(*vector)[i].nume = NULL;
		}
	}

	free(*vector);
	*vector = NULL;
	*nrElemente = 0;
}


void copiazaClientiCuBugetMare(struct Client* vector, int nrElemente, float bugetMinim, struct Client** vectorNou, int* dimensiune) {
	*dimensiune = 0;

	// Calcul?m num?rul de clien?i eligibili
	for (int i = 0; i < nrElemente; i++) {
		if (vector[i].buget >= bugetMinim) {
			(*dimensiune)++;
		}
	}

	// Dac? nu exist? clien?i eligibili, ie?im
	if (*dimensiune == 0) {
		*vectorNou = NULL;
		return;
	}

	// Aloc?m memorie pentru vectorNou
	*vectorNou = (struct Client*)malloc(sizeof(struct Client) * (*dimensiune));
	if (*vectorNou == NULL) {
		printf("Eroare alocare memorie pentru vectorNou!\n");
		return;
	}

	int k = 0;
	for (int i = 0; i < nrElemente; i++) {
		if (vector[i].buget >= bugetMinim) {
			// Copiem datele clientului
			(*vectorNou)[k].id = vector[i].id;
			(*vectorNou)[k].varsta = vector[i].varsta;
			(*vectorNou)[k].buget = vector[i].buget;
			(*vectorNou)[k].initialaTata = vector[i].initialaTata;

			// Copiem numele doar dac? exist?
			if (vector[i].nume != NULL) {
				(*vectorNou)[k].nume = (char*)malloc(strlen(vector[i].nume) + 1);
				if (!(*vectorNou)[k].nume) {
					printf("Eroare alocare memorie pentru nume!\n");
					return;
				}
				strcpy_s((*vectorNou)[k].nume, strlen(vector[i].nume) + 1, vector[i].nume);
			}
			else {
				(*vectorNou)[k].nume = NULL;
			}
			k++;
		}
	}
}

struct Client getPrimulClientDupaNume(struct Client* vector, int nrElemente, const char* numeCautat) {
	struct Client c;
	c.id = -1;  // Indic? c? nu s-a g?sit clientul
	c.nume = NULL;
	c.varsta = 0;
	c.buget = 0;
	c.initialaTata = '\0';

	for (int i = 0; i < nrElemente; i++) {
		if (vector[i].nume != NULL && strcmp(vector[i].nume, numeCautat) == 0) {
			c = vector[i];

			if (vector[i].nume != NULL) {
				c.nume = (char*)malloc(strlen(vector[i].nume) + 1);
				if (!c.nume) {
					printf("Eroare alocare memorie pentru nume!\n");
					return c;
				}
				strcpy_s(c.nume, strlen(vector[i].nume) + 1, vector[i].nume);
			}
			else {
				c.nume = NULL;
			}
			return c;
		}
	}

	return c;
}



void inserareInVector(struct Client** vector, int* dim, struct Client client) {
	struct Client* aux = (struct Client*)malloc(sizeof(struct Client) * ((*dim) + 1));
	if (!aux) {
		printf("Eroare alocare memorie!\n");
		return;
	}

	// Copiem elementele existente
	for (int i = 0; i < *dim; i++) {
		aux[i].id = (*vector)[i].id;
		aux[i].varsta = (*vector)[i].varsta;
		aux[i].buget = (*vector)[i].buget;
		aux[i].initialaTata = (*vector)[i].initialaTata;

		if ((*vector)[i].nume != NULL) {
			aux[i].nume = (char*)malloc(strlen((*vector)[i].nume) + 1);
			if (!aux[i].nume) {
				printf("Eroare alocare memorie pentru nume!\n");
				return;
			}
			strcpy_s(aux[i].nume, strlen((*vector)[i].nume) + 1, (*vector)[i].nume);
		}
		else {
			aux[i].nume = NULL;
		}
	}

	// Ad?ug?m noul client
	aux[*dim].id = client.id;
	aux[*dim].varsta = client.varsta;
	aux[*dim].buget = client.buget;
	aux[*dim].initialaTata = client.initialaTata;

	if (client.nume != NULL) {
		aux[*dim].nume = (char*)malloc(strlen(client.nume) + 1);
		if (!aux[*dim].nume) {
			printf("Eroare alocare memorie pentru nume!\n");
			return;
		}
		strcpy_s(aux[*dim].nume, strlen(client.nume) + 1, client.nume);
	}
	else {
		aux[*dim].nume = NULL;
	}

	// Eliber?m memoria vechiului vector doar dac? exist?
	if (*vector != NULL) {
		free(*vector);
	}

	*vector = aux;
	(*dim)++;
}


struct Client citireClientFisier(FILE* f) {
	struct Client c;
	char buffer[100];
	char sep[3] = ",\n";
	char* token;

	// Ini?ializ?m structura cu valori implicite
	c.id = -1;
	c.varsta = 0;
	c.nume = NULL;
	c.buget = 0.0;
	c.initialaTata = '\0';

	// Citim o linie din fi?ier
	if (fgets(buffer, 100, f) == NULL) {
		return c;
	}

	// Proces?m fiecare câmp ?i verific?m `NULL`
	token = strtok(buffer, sep);
	if (!token) return c;
	c.id = atoi(token);

	token = strtok(NULL, sep);
	if (!token) return c;
	c.varsta = atoi(token);

	token = strtok(NULL, sep);
	if (token) {
		c.nume = (char*)malloc(strlen(token) + 1);
		if (!c.nume) {
			printf("Eroare alocare memorie pentru nume!\n");
			return c;
		}
		strcpy_s(c.nume, strlen(token) + 1, token);
	}

	token = strtok(NULL, sep);
	if (!token) return c;
	c.buget = atof(token);

	token = strtok(NULL, sep);
	c.initialaTata = (token != NULL) ? token[0] : '\0';

	return c;
}


struct Client* citireVectorDinFisier(const char* numeFisier, int* dim) {
	FILE* f = fopen(numeFisier, "r");
	struct Client* vector = NULL;
	(*dim) = 0;
	while (!feof(f)) {
		struct Client c = citireClientFisier(f);
		inserareInVector(&vector, dim, c);
	}
	fclose(f);
	return vector;
}

struct Nod {
	struct Client client;
	struct Nod* next;
};

void inserareListaSfarsit(struct Nod** cap, struct Client c) {
	struct Nod* nou = (struct Nod*)malloc(sizeof(struct Nod));
	if (!nou) {
		printf("Eroare alocare memorie pentru nod nou!\n");
		return;
	}

	nou->client = c;

	if (c.nume != NULL) {
		nou->client.nume = (char*)malloc(strlen(c.nume) + 1);
		if (!nou->client.nume) {
			printf("Eroare alocare memorie pentru nume!\n");
			free(nou);
			return;
		}
		strcpy_s(nou->client.nume, strlen(c.nume) + 1, c.nume);
	}
	else {
		nou->client.nume = NULL;
	}

	nou->next = NULL;

	if (*cap) {
		struct Nod* p = *cap;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = nou;
	}
	else {
		*cap = nou;
	}
}

struct Nod* citireListaDinFisier(const char* numeFisier) {
	struct Nod* cap = NULL;
	FILE* f = fopen(numeFisier, "r");

	if (!f) {
		printf("Eroare la deschiderea fi?ierului!\n");
		return NULL;
	}

	while (1) {
		struct Client c = citireClientFisier(f);
		if (c.nume == NULL) {  // Dac? citirea a e?uat, oprim bucla
			break;
		}
		inserareListaSfarsit(&cap, c);
	}

	fclose(f);
	return cap;
}

void afisareLista(struct Nod* cap) {
	while (cap) {
		afisare(cap->client);
		cap = cap->next;
	}
}

void stergereLista(struct Nod** cap) {
	// Verific?m dac? pointerul listei este NULL
	if (cap == NULL || *cap == NULL) {
		return;
	}

	struct Nod* aux;
	while (*cap != NULL) {
		aux = *cap; // Salv?m nodul curent
		*cap = (*cap)->next; // Mut?m capul listei la urm?torul nod

		// Verific?m dac? numele a fost alocat înainte de a-l elibera
		if (aux->client.nume != NULL) {
			free(aux->client.nume);
			aux->client.nume = NULL; // Evit?m dangling pointers
		}

		free(aux); // Eliber?m nodul curent
	}

	*cap = NULL; // Reset?m pointerul listei pentru siguran??
}



int main() {

	//struct Client client = initializare(2, 23, "Popescu", 2000, 'B');
	//afisare(client);
	////struct Client multiClienti[30]; //ALOCARE STATICA
	//int nrClienti = 3;
	//struct Client* clienti;
	//clienti = (struct Client*)malloc(nrClienti * sizeof(struct Client)); //ALOCARE DINAMICA
	//clienti[0] = initializare(1, 22, "Ionescu", 100, 'J');
	//clienti[1] = initializare(2, 23, "Vasilescu", 200, 'D');
	//clienti[2] = initializare(3, 23, "Gigel", 400, 'T');
	//printf("Clientul cautat:\n");
	//struct Client c = getPrimulClientDupaNume(clienti, nrClienti, "Gigel");
	//afisare(c);
	//inserareInVector(&clienti, &nrClienti, c);
	//printf("\n\nAfisare vector actualizat:\n");
	//afisareVector(clienti, nrClienti);
	//free(c.nume);
	//printf("\n\nVector:\n");
	//afisareVector(clienti, nrClienti);
	//printf("%.2f\n", calculVarstaMedie(clienti, nrClienti));
	//int nrClientiFideli = 2;
	//struct Client* vectorScurt = copiazaPrimeleNElemente(clienti, nrClienti, nrClientiFideli);
	//printf("\n\nClientiFideli:\n");
	//afisareVector(vectorScurt, nrClientiFideli);
	//struct Client* clientiCuBugetMare = NULL;
	//int nrClientiCuBugetMare = 0;
	//copiazaClientiCuBugetMare(clienti, nrClienti, 300, &clientiCuBugetMare, &nrClientiCuBugetMare);
	//printf("\nClienti cu buget mare:\n");
	//afisareVector(clientiCuBugetMare, nrClientiCuBugetMare);
	//dezalocare(&clienti, &nrClienti);
	//printf("Vectorul dupa stergere:\n");
	//afisareVector(clienti, nrClienti);

	//FILE* f = fopen("clienti.txt", "r");
	//struct Client c = citireClientFisier(f);
	//afisare(c);

	//struct Client* clienti = NULL;
	//int nrClienti = 0;
	//clienti = citireVectorDinFisier("clienti.txt", &nrClienti);
	//afisareVector(clienti, nrClienti);

	struct Nod* cap = NULL;
	cap = citireListaDinFisier("clienti.txt");

	afisareLista(cap);
	stergereLista(&cap);
	printf("Dupa stergere:\n");
	afisareLista(cap);
	return 0;
}