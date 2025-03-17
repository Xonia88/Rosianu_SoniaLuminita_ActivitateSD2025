//#include <stdio.h>
//#include <stdlib.h>  // Pentru malloc() si free()
//#include <string.h>  // Pentru strlen() si strcpy()
//#include <stdbool.h>
//
//
//struct fruct {
//    char* denumire;
//    float gramaj;
//    int nrZile;
//    bool areSambure;
//};
//
//int main() {  
//    struct fruct mar;  
//
//    mar.denumire = (char*)malloc((strlen("mar") + 1) * sizeof(char));
//    if (mar.denumire == NULL) {  // Verificare daca malloc() a reusit
//        printf("Eroare la alocarea memoriei!\n");
//        return 1;
//    }
//
//    strcpy(mar.denumire, "mar");
//    mar.gramaj = 120.4;
//    mar.nrZile = 1;
//    mar.areSambure = false;  
//
//    // Afisare date
//    printf("Fruct: %s\nGramaj: %.2f\nNr. Zile: %d\nAre sambure: %s\n",
//        mar.denumire, mar.gramaj, mar.nrZile, mar.areSambure ? "Da" : "Nu");
//
//    //Eliberare memorie care este alocata dinamic
//    free(mar.denumire);
//
//    return 0;  
//}
