#include "stabla.h"
#include <stdio.h>

_cvor* novi(int broj) {
    _cvor* a = malloc(sizeof (_cvor));
    if (a == NULL) {
        printf("Greska u alokaciji!\n");
        exit(0);
    }

    a->vrednost = broj;
    a->levo = NULL;
    a->desno = NULL;

    return a;
}

_cvor* ubaci_u_stablo(_cvor* stablo, int broj) {

    if (stablo == NULL)
        return novi(broj);
    else if (stablo->vrednost < broj)
        stablo->desno = ubaci_u_stablo(stablo->desno, broj);
    else if (stablo->vrednost > broj)
        stablo->levo = ubaci_u_stablo(stablo->levo, broj);
    else
        return stablo;

    return stablo;
}

_cvor* unos(FILE* f) {
    int n;
    _cvor* stablo = NULL;
    while ((fscanf(f, "%d", &n)) != EOF)
        stablo = ubaci_u_stablo(stablo, n);

    return stablo;
}

//infiksno

void ispis(_cvor* stablo, FILE* k) {
    if (stablo != NULL) {
        ispis(stablo->levo, k);
        fprintf(k, "%d ", stablo->vrednost);
        ispis(stablo->desno, k);
    }
}

//prefiksno

void ispis1(_cvor* stablo, FILE* k) {
    if (stablo != NULL) {
        fprintf(k, "%d ", stablo->vrednost);
        ispis1(stablo->levo, k);
        ispis1(stablo->desno, k);
    }
}

//postfiksno

void ispis2(_cvor* stablo, FILE* k) {
    if (stablo != NULL) {
        ispis2(stablo->levo, k);
        ispis2(stablo->desno, k);
        fprintf(k, "%d ", stablo->vrednost);
    }
}

void oslobodi(_cvor* stablo) {
    if (stablo != NULL) {

        oslobodi(stablo->levo);
        oslobodi(stablo->desno);
        free(stablo);
    }
}
