#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/liste.h"
#include <string.h>

_cvor* dodaj_element(_cvor* lista, int br);

int main(int argc, char** argv) {

    int i, n;
    _cvor* lista = NULL;
    FILE* k;
    FILE* g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    if (strcmp(argv[1], "stdin") == 0)
        lista = napravi_listu(stdin);

    else {
        k = fopen(argv[1], "r");

        if (k == NULL) {
            printf("Greska u otvaranju datoteke.");
            exit(0);
        }

        lista = napravi_listu(k);

    }

    if (g == NULL || k == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    printf("Uneti element:\n");
    scanf("%d", &n);

    lista = dodaj_element(lista, n);
    //ispisuje u datoteku
    ispis_liste(lista, g);

    oslobodi(lista);

    return 0;
}

_cvor* dodaj_element(_cvor* lista, int br) {
    _cvor* n = novi_cvor(br), *prvi = lista;
    if (lista == NULL)
        return n;
    else if (br <= lista->vrednost) {
        n->sledeci = lista;
        return n;
    } else {
        while (lista->sledeci != NULL && (br > (lista->sledeci->vrednost)))
            lista = lista->sledeci;

        n->sledeci = lista->sledeci;
        lista->sledeci = n;
    }
    //vraca glavu liste
    return prvi;
}
