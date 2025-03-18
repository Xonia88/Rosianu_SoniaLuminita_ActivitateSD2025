////Task - uri suplimentare 
//// 1. Structura si functii Se consider? prima liter? din numele vostru, 
//// ?i prima liter? din prenumele vostru.Sa se construiasc? un articol 
//// care s? con?in? cele dou? litere.
//// Exemplu: Alin Zamfiroiu->A si Z.Articolul 
//// Magazin : struct Magazin { int cod; char* denumire; int nrProduse; float* preturi; } 
//// Articolul trebuie s? aib? logica.Articolul trebuie sa fie un substantiv.
//// Articolul trebuie sa aib? cel pu?in trei atribute, 
//// si cel pu?in unul s? fie alocat dinamic.
//// Realizati o functie cu ajutorul careia sa cititi de la tastatura un articol de tipul construit de voi.
//// Func?ia returneaz? obiectul citit.
//// Realizati o functie care calculeaza ceva pentru un obiect de tipul implementat de voi. (o medie sau o suma,
//// un maxim, un minim...sau orice altceva) 
//// Realizati o functie care modifica pentru un obiect primit ca parametru, un anumit camp.
//// noua valoare este primita ca parametru.
//// Realiza?i o func?ie care afi?eaz? un obiect de tipul creat.
//// Afi?area se face la console, ?i sunt afi?ate toate informa?iile.
////
////2. Vectori
//// Considerati codul de la task - ul precedent.
//// Creati in functia main un vector alocat dinamic cu cel putin 5 obiecte de tipul structurii voastre.
//// - a. Realizati o functie care va creea un nou vector �n care va copia dintr - un vector primit ca 
//// parametru obiectele care indeplinesc o anumita conditie.Stabiliti voi conditia in functie de un atribut 
//// sau doua atribute.
//// - b. Realizati o functie care muta intr - un nou vector obiectele care indeplinesc o alta conditie fata 
//// de cerinta precedenta.
//// - c. Realizati o functie care concateneaza doi vectori.
//// - d. Realizati o functie care afiseaza un vector cu obiecte.
//// Apelati toate aceste functii in main().
//// 
////3. Fi?iere
//// Considerati codul de la task - ul precedent.
//// Creati un fisier in care sa aveti minim 10 obiecte de tipul structurii create.
//// Asezarea in fisier a elementelor o faceti la libera alegere.
//// Scrieti intr - un program C functia care sa citeasca obiectele din fisier si sa le salveze intr - un vector.
//// Scrieti o functie care va salva un obiect intr - un fisier text.Scrieti o functie care va salva un vector de
//// obiecte intr - un fisier text.
//// 
////4. Matrice 
//// Considerati codul de la task - ul precedent.Creati un fisier in care sa aveti minim 10 obiecte de tipul 
//// structurii create.Asezarea in fisier a elementelor o faceti la libera alegere.
//// Scrieti intr - un program C functia care sa citeasca obiectele din fisier si sa le salveze intr - un vector.
//// Creati o functie care sa copieze(deep copy) elementele din vector intr - o matricealocat? dinamic.
//// Asezarea in matrice pe linii a obiectelor o faceti dupa un criteriu aplicat unui atribut.
//// Astfel veti ob?ine mai multe clustere reprezentate de liniile matricei.
//// Scrieti o functie care muta liniile din matrice, astfel incat acestea sa fie sortate dupa numarul de elemente
//// de pe linie.
//// Scrieti o functie care sa afiseze elementele dintr - o matrice.
//// 
//// 5. Liste simple
//// Se considera lista simplu inlantuita realizata la seminar. 
//// 1. Implementati o functie care sterge un nod de pe o pozitie data ca parametru.
//// Daca lista are mai putine noduri decat index - ul dat, nu se realizeaza stergerea. 
//// 2. Implementati o functie care sa insereze elementele in cadrul listei simplu inlantuite astfel incat 
//// acestea a fie sortate crescator dupa un camp la alegerea voastra. 
//// 3. Implementati o functie care salveaza intr - un vector toate obiectele care indeplinesc o conditie 
//// stabilita de voi.
//// Realizati deep copy, astfel incat elementele din vector sa fie diferentiate de cele din lista.
//// Aveti grija la alocarea de spatiu, deoarece trebuie sa stabiliti pentru cate elemente veti aloca spatiu. 
//// 4. Implementati o functie care primeste lista si doua pozitii.
//// In cadrul functiei trebuie sa interschimbati elementele de pe cele doua pozitii din lista primita.
//// 6. Liste duble Se considera lista dublu inlantuita realizata la seminar. 
//// 1. Implementati o functie care sterge un nod de pe o pozitie data ca parametru.
//// Daca lista are mai putine noduri decat index - ul dat, nu se realizeaza stergerea; 
//// 2. Implementati o functie care sa insereze elementele in cadrul listei dublu inlantuite astfel incat 
//// acestea a fie sortate crescator dupa un camp la alegerea voastra; 
//// 3. Realizati parcurgerile pentru lista dublu inlantuita, astfel incat sa afiseze elementele sortate 
//// crescator dar si sortate descrescator; 4. Implementati o functie care salveaza intr - o lista simplu 
//// inlantuita toate obiectele care indeplinesc o conditie stabilita de voi.
//// Realizati deep copy, astfel incat elementele din listasimplu inlantuita sa fie diferite de cele din lista 
//// dublu inlantuita.Observati diferenta dintre utilizarea de lista inlantuita si vector(task - ul precedent); 
//// 5. Implementati o functie care primeste lista dublu inlantuita si doua pozitii.In cadrul functiei trebuie 
//// sa interschimbati elementele de pe cele doua pozitii din lista primita.
//// Interschimbati informatiile utile din cele doua noduri. 
//// 8. HashTable Se doreste gestiunea cladirilor din Bucuresti in funtie de anul construirii.
//// Acest lucru va ajuta la stabilire riscului seismic al acestora. 
//// 1. Sa se creeze o tabela de dispersie pentru stocarea cladirilor din Bucuresti(structura Cladire contine ce
//// atribute vreti voi dar va contine obligatoriu anul construirii si un id unic).campul folosit pentru 
//// clusterizare este anul construirii cladirii. 
//// 2. Implementati o functie care afiseaza cladirile dintr - un cluster(construite intr - un an primit 
//// ca parametru). 
//// 3. Implementati o functie care sterge o cladire pentru care se primeste id - ul si anul construirii. 
//// 4. Implementati o functie care sterge o cladire pentru care se primeste doar id - ul cladirii. 
//// 5. Observatii diferenta dintre functia implementata la 4 si functia de la 5. 
//// 6. Implementati o functie care salveaza intr - un vector toate cladirile dintr - un an primit ca parametru.
//// Realizati deep copy, astfel incat elementele din vector sa fie diferentiate de cele
////din tabela de dispersie.Aveti grija la alocarea de spatiu, deoarece trebuie sa stabiliti pentru cate 
//// elemente veti aloca spatiu. 
//// 7. Implementati o functie care modifica anul construirii unei cladiri 
//// identificate prin ID.Functia primeste ca parametri : id - ul cladirii, vechiul an de constructie si noul an
//// de constructie.Aveti grija se modifica valoarea atributului folosit pentru clusterizare. 
//// 9. Heap Sa se realizeze o aplicatie in limbajul C, care sa ajute personalul de la Unitatea de Primiri 
//// Urgente(UPU) in gestiunea pacientilor.Fiecare pacient care este adus la UPU are un grad prin care se 
//// specifica, cat de urgent si grav este.Pacientii care sunt adusi cu ambulanta au gradul de urgenta mult mai
//// mare.deoarece sunt intr - o situatie foarte grava.Sa se realizeze structura Pacient, si pe langa 
//// informatiile specifice unui pacient sa adaugati si acest grad de urgenta.Sa se implementeze modulul care s?
//// permit? preluarea pacientilor cu grad de urgenta foarte mare chiar daca acestia au venit printre ultimele 
//// persoane.In acest mod personalul de la UPU poate sa se ocupe de situatiile foarte grave, iar pacientii care
//// nu sunt in stare grava pot astepta pana cand sunt preluate situatiile urgente.Se foloseste un Max - Heap. 
//// 10 Arbori binari Se considera un arbore binar de cautare.Puteti sa folositi codul de la seminar.Sa se 
//// stearga un nod pentru care se primeste id - ul de cautare.Dupa stergere arborele trebuie sa isi pastreze 
//// proprietatea de Arbore Binar de Cautare.Sa se implementeze o functie care pentru o radacina primita ca 
//// parametru, returneaza radacina subarborelui stang sau drept care are inaltimea mai mare.Sa se realizeze o 
//// functie care pentru un nod radacina primit, determina numarul de noduri aflate in subordine.
////Sa se realizeze o functie care pentru un nod radacina primit ca parametru, returneaza radacina subarborelui 
//// stang sau drept care are mai multe noduri in subordine. 
//// 11. Arbori AVL Sa se implementeze un arbore binar 
//// de cautare echilibrat.La inserare se verifica gradul de echilibru, iar in cazul in care exista un 
//// dezechilibru sa se relaizeze rotirile necesare, astfel incat arborele sa fie echilibrat.Sa se realizeze
//// functia de cautare a unui nod in arborele AVL, pe baza unui id, sau a cheii de cautare din arbore.Sa se 
//// realizeze o functie care salveaza nodurile din arborele AVL intr - un vector, prin parcurgerea preordine, 
//// inordine, postordine.Sa se realizeze o functie care salveaza nodurile din arborele AVL intr - o lista simplu
//// inlantuita, prin parcurgerea preordine, inordine, postordine.Sa se realizeze o functie care salveaza 
//// nodurile din arborele AVL intr - o lista dublu inlantuita, prin parcurgerea preordine, inordine, postordine.
//// 
//// 12. Stive si cozi 
//// 
//// 1. Implementati modul de lucru cu stiva(LIFO) pe un vector; 
//// 2. Implementati modul de lucru cu stiva(LIFO) pe o stiva simplu inlantuita; 
//// 3. Implementati modul de lucru cu stiva(LIFO) pe o lista dublu inlantuita;
//// 4. Implementati modul de lucru cu coada(FIFO) pe un vector;
//// 5. Implementati modul de lucru cu coada(FIFO) pe o lista simplu inlantuita; 
//// 6. Implementati modul de lucru cu coada(FIFO) pe o lista dublu inlantuita.
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//struct Restaurant {
//	int id;
//	char* nume;
//	int nrMese;
//	float pretMeniu;
//}
//
//struct Restaurant citireDeLaTastatura(int id, const char* nume, int nrMese, float preturi) {
//
//	struct Restaurant r;
//	r.id = id;
//	r.nume = (char*)malloc(sizeof(char) * strlen(nume) + 1);
//	strcpy_s(r.nume, strlen(nume) + 1, nume);
//	r.nrMese = nrMese;
//	r.pretMeniu = pretMeniu;
//
//	return r;
//}
//
//void afisare(struct Restaurant r) {
//	if (r.nume != NULL) {
//		printf("Restaurnatul%s cu ID %d are %d 100 mese si un meniu %5.2f RON.\n ",
//			r.nume, r.id, r.nrMese, r.pretMeniu);
//	}
//	else {
//		printf("Restaurantul s-a inchis");
//	}
//}
//int main() {
//	struct Restaurant r;
//	r = citireDeLaTastatura
//}
