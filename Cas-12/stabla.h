#ifndef STABLA_H
#define STABLA_H

#include <stdlib.h>
#include <stdio.h>

typedef struct _cvor {
    int vrednost;
    struct _cvor* levo;
    struct _cvor* desno;
} _cvor;

_cvor* novi(int broj);
_cvor* ubaci_u_stablo(_cvor* stablo, int broj);
_cvor* unos(FILE* f);
void ispis(_cvor* stablo, FILE* k);
void ispis1(_cvor* stablo, FILE* k);
void ispis2(_cvor* stablo, FILE* k);
void oslobodi(_cvor* stablo);

#endif
