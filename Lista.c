//Zadaci sa sajta: http://www.prog2-i-smer.matf.bg.ac.rs/vezbe.html
//Cas 10

//ZADATAK 1

    //liste.h
    /*
    #ifndef LISTE_H
    #define LISTE_H

    #include <stdlib.h>
    #include <stdio.h>

    typedef struct _cvor {
        int vrednost;
        struct _cvor* sledeci;
    } _cvor;

    _cvor* novi_cvor(int broj);
    _cvor* dodaj_na_pocetak(_cvor* glava, int br);
    void dodaj_na_pocetak2(_cvor** adresa_glave, int br);
    void ispis_liste2(_cvor* glava, FILE* f);
    void ispis_liste(_cvor* glava, FILE* f);
    void oslobodi2(_cvor* lista);
    void oslobodi(_cvor* lista);
    _cvor* dodaj_na_kraj2(_cvor* lista, int br);
    _cvor* dodaj_na_kraj(_cvor* lista, int br);
    void dodaj_na_kraj3(_cvor** lista, int br);
    _cvor* napravi_listu2(FILE* f);
    _cvor* napravi_listu(FILE* f);
    _cvor* napravi_obrnutu_listu2(FILE* f);
    _cvor* napravi_obrnutu_listu(FILE* f);

    #endif*/

    //liste.c
    /*
    #include "liste.h"
    #include <stdio.h>

    _cvor* novi_cvor(int broj) {
        _cvor* a = (_cvor*) malloc(sizeof (_cvor));

        if (a == NULL) {
            printf("Greska!");
            exit(0);
        }

        a->vrednost = broj;
        a->sledeci = NULL;

        return a;
    }

    _cvor* dodaj_na_pocetak(_cvor* glava, int br) {
        _cvor* a = novi_cvor(br);
        a->sledeci = glava;

        return a;
    }

    void dodaj_na_pocetak2(_cvor** adresa_glave, int br) {
        _cvor* a = novi_cvor(br);

        a->sledeci = *adresa_glave;
        *adresa_glave = a;
    }

    void ispis_liste2(_cvor* glava, FILE* f) {
        while (glava != NULL) {
            fprintf(f, "%d ", glava->vrednost);
            glava = glava->sledeci;
        }
    }

    void ispis_liste(_cvor* glava, FILE* f) {
        if (glava == NULL)
            return;
        else {
            fprintf(f, "%d ", glava->vrednost);
            ispis_liste(glava->sledeci, f);
        }
    }

    void oslobodi2(_cvor* lista) {
        _cvor* pom;
        while (lista != NULL) {
            pom = lista;
            free(lista);
            lista = pom->sledeci;
        }
    }

    void oslobodi(_cvor* lista) {
        if (lista == NULL)
            return;
        oslobodi2(lista->sledeci);
        free(lista);
    }

    _cvor* dodaj_na_kraj2(_cvor* lista, int br) {
        _cvor* prvi = lista, *n;
        n = novi_cvor(br);

        if (lista == NULL)
            return n;

        while (lista->sledeci != NULL) {
            lista = lista->sledeci;
        }
        lista->sledeci = n;

        return prvi;
    }

    _cvor* dodaj_na_kraj(_cvor* lista, int br) {

        if (lista == NULL) {
            _cvor *n = novi_cvor(br);
            return n;
        } else {
            lista->sledeci = dodaj_na_kraj(lista->sledeci, br);
            return lista;
        }

    }

    void dodaj_na_kraj3(_cvor** lista, int br) {
        _cvor* prvi = *lista, *n;
        n = novi_cvor(br);

        if (*lista == NULL)
            *lista = n;
        else {
            while ((*lista)->sledeci != NULL) {
                *lista = (*lista)->sledeci;
            }
            (*lista)->sledeci = n;
            (*lista) = prvi;
        }
    }

    _cvor* napravi_listu2(FILE* f) {
        int br;
        _cvor* n = NULL;

        while (fscanf(f, "%d", &br) != EOF)
            n = dodaj_na_kraj(n, br);

        return n;
    }

    //proveriti da li moze ovako(radi dobro)

    _cvor* napravi_listu(FILE* f) {
        int br;
        _cvor * a = NULL;

        if (fscanf(f, "%d", &br) == EOF)
            return a;
        else
            return dodaj_na_pocetak(napravi_listu(f), br);
    }

    _cvor* napravi_obrnutu_listu2(FILE* f) {
        int br;
        _cvor* n = NULL;

        while (fscanf(f, "%d", &br) != EOF)
            n = dodaj_na_pocetak(n, br);

        return n;
    }

    _cvor* napravi_obrnutu_listu(FILE* f) {
        int br;
        _cvor* a = NULL;
        if (fscanf(f, "%d", &br) == EOF)
            return a;
        else
            return dodaj_na_kraj(napravi_obrnutu_listu(f), br);
    }*/

    //program sa stdin i fajlom kao argument
    /*
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
    }*/

//ZADATAK 2
/*
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
}*/

//ZADATAK 3
//ZADATAK 4
//ZADATAK 5
//ZADATAK 6
