#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Restaurant {
	int id;
	char* nume;
	int nrMese;
	float pretMeniu;
};

struct Restaurant citireDeLaTastatura() {
	struct Restaurant r;
	char buffer[100]; //Buffer temporar pt citirea numelui

	printf("Introduceti ID: ");
	scanf("%d", &r.id);
	getchar();
	 
	printf("Introduceti numele restaurantului: ");
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strcspn(buffer, "\n")] = '\0'; //Eliminam new-line;

	//Alocam memorie pentru nume si copiem continutul bufferului
	r.nume = (char*)malloc(strlen(buffer) + 1);
	if (r.nume == NULL) {
		printf("Eroare la alocarea memoriei!\n");
		exit(1);
	}
	strcpy(r.nume, buffer);
	printf("Introduceti nr de mese: ");
	scanf("%d", &r.nrMese);
	printf("Introduceti pretul meniului: ");
	scanf("%f", &r.pretMeniu);
	return r;
}
//Functia pentru afisarea unui restaurant
void afisare(struct Restaurant r) {
	printf("\n==Detalii restaurant==\n");
	printf("ID:%d\n", r.id);
	printf("Numele restaurantului:%s\n", r.nume);
	printf("Numarul de mese rezervate:%d\n", r.nrMese);
	printf("Pret aproximativ al meniului:%.2f\n", r.pretMeniu);
	
}

int main() {
	struct Restaurant r = citireDeLaTastatura();
	afisare(r);
	//eliberare memorie alocata pt nume
	free(r.nume);
	return 0;

}
