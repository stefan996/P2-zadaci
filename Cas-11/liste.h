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

#endif