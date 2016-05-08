#include <stdio.h>
#include "liste.h"
#include <string.h>

int main(int argc, char** argv) {

    int i;
    _cvor* lista = NULL;
    FILE* k;
    FILE* g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    if (strcmp(argv[1], "stdin") == 0) {
        //dodavanje na kraj liste:
        lista=napravi_listu(stdin);

        //dodavanje na pocetak liste:
        //lista = napravi_obrnutu_listu(stdin);

    } else {
        k = fopen(argv[1], "r");

        if (k == NULL) {
            printf("Greska u otvaranju datoteke.");
            exit(0);
        }

        //dodavanje na kraj liste:
        //lista=napravi_listu(k);

        //dodavanje na pocetak liste:
        lista = napravi_obrnutu_listu(k);

    }

    if (g == NULL || k == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    //ispisuje u datoteku
    ispis_liste(lista, g);
    
    oslobodi(lista);

    return 0;
}
