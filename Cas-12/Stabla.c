//Zadaci sa sajta: http://www.prog2-i-smer.matf.bg.ac.rs/vezbe.html
//Cas 12

//ZADATAK 1

//stabla.c
/*
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
}*/

//stabla.h
/*
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

#endif*/

//zadatak sa ispisom
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/stabla.h"
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, k;
    _cvor* stablo = NULL;

    FILE* f = fopen(argv[1], "r");
    FILE* g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    stablo = unos(f);

    ispis2(stablo, g);

    oslobodi(stablo);
    fclose(f);
    fclose(g);

    return 0;
}*/

//ZADATAK 2
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/stabla.h"
#include <string.h>
#include <stdlib.h>

int suma(_cvor* stablo);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, k;
    _cvor* stablo = NULL;

    FILE* f = fopen(argv[1], "r");
    FILE* g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    stablo = unos(f);

    printf("%d\n", suma(stablo));
    //ispis2(stablo, g);

    oslobodi(stablo);
    fclose(f);
    fclose(g);

    return 0;
}

int suma(_cvor* stablo) {
    int l, d;
    if (stablo == NULL)
        return 0;
    l = suma(stablo->levo);
    d = suma(stablo->desno);

    return l + d + stablo->vrednost;
}*/

//ZADATAK 3
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/stabla.h"
#include <string.h>
#include <stdlib.h>

void ispis_listova(_cvor* stablo);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, k;
    _cvor* stablo = NULL;

    FILE* f = fopen(argv[1], "r");
    FILE* g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    stablo = unos(f);

    ispis_listova(stablo);
    printf("\n");
    //ispis2(stablo, g);

    oslobodi(stablo);
    fclose(f);
    fclose(g);

    return 0;
}

void ispis_listova(_cvor* stablo) {
    if (stablo == NULL)
        return;
    ispis_listova(stablo->levo);
    ispis_listova(stablo->desno);

    if (stablo->levo == NULL && stablo->desno == NULL)
        printf("%d ", stablo->vrednost);
}*/

//ZADATAK 4
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/stabla.h"
#include <string.h>
#include <stdlib.h>

int suma_listova(_cvor* stablo);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, k;
    _cvor* stablo = NULL;

    FILE* f = fopen(argv[1], "r");
    FILE* g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    stablo = unos(f);


    printf("%d\n", suma_listova(stablo));
    //ispis2(stablo, g);

    oslobodi(stablo);
    fclose(f);
    fclose(g);

    return 0;
}

int suma_listova(_cvor* stablo) {
    int l, d;
    if (stablo == NULL)
        return 0;
    l = suma_listova(stablo->levo);
    d = suma_listova(stablo->desno);

    if (stablo->levo == NULL && stablo->desno == NULL)
        return stablo->vrednost;

    return l + d;
}*/

//ZADATAK 5
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/stabla.h"
#include <string.h>
#include <stdlib.h>

int maks1(_cvor* stablo);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, k;
    _cvor* stablo = NULL;

    FILE* f = fopen(argv[1], "r");
    FILE* g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    stablo = unos(f);


    printf("%d\n", maks1(stablo));
    //ispis2(stablo, g);

    oslobodi(stablo);
    fclose(f);
    fclose(g);

    return 0;
}

int maks1(_cvor* stablo) {
    int l, d;
    if (stablo == NULL)
        return 0;
    l = maks1(stablo->levo);
    d = maks1(stablo->desno);

    if (l > d) {
        if (l > stablo->vrednost)
            return l;
        else
            return stablo->vrednost;
    } else {
        if (d > stablo->vrednost)
            return d;
        else
            return stablo->vrednost;
    }
}*/

//ZADATAK 6
//trebalo bi da radi ista funkcija kao iz proslog

//ZADATAK 7
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/stabla.h"
#include <string.h>
#include <stdlib.h>

int dubina(_cvor* stablo);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, k;
    _cvor* stablo = NULL;

    FILE* f = fopen(argv[1], "r");
    FILE* g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    stablo = unos(f);


    printf("%d\n", dubina(stablo));
    //ispis2(stablo, g);

    oslobodi(stablo);
    fclose(f);
    fclose(g);

    return 0;
}

int dubina(_cvor* stablo) {
    int l, d;
    if (stablo == NULL)
        return 0;
    l = dubina(stablo->levo);
    d = dubina(stablo->desno);

    if (l > d)
        return l + 1;
    else
        return d + 1;
}*/

//ZADATAK 8
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/stabla.h"
#include <string.h>
#include <stdlib.h>

int f8(_cvor* drvo, int nivo);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, k;
    _cvor* stablo = NULL;

    FILE* f = fopen(argv[1], "r");
    FILE* g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    stablo = unos(f);

    printf("Uneti nivo:\n");
    scanf("%d", &k);

    printf("%d\n", f8(stablo, k));
    //ispis2(stablo, g);

    oslobodi(stablo);
    fclose(f);
    fclose(g);

    return 0;
}

int f8(_cvor* drvo, int nivo) {
    int l, d;
    if (drvo == NULL)
        return 0;
    l = f8(drvo->levo, nivo - 1);
    d = f8(drvo->desno, nivo - 1);
    if (nivo == 1)
        return 1;

    return l + d;

}*/

//ZADATAK 9
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/stabla.h"
#include <string.h>
#include <stdlib.h>

int f5(_cvor* drvo);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, k;
    _cvor* stablo = NULL;

    FILE* f = fopen(argv[1], "r");
    FILE* g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    stablo = unos(f);

    printf("%d\n", f5(stablo));
    //ispis2(stablo, g);

    oslobodi(stablo);
    fclose(f);
    fclose(g);

    return 0;
}

int f5(_cvor* drvo) {
    int l, d;

    if (drvo == NULL)
        return 0;
    if (drvo->levo == NULL || drvo->desno == NULL)
        return 0;
    l = f5(drvo->levo);
    d = f5(drvo->desno);
    if (drvo->vrednost == drvo->desno->vrednost - drvo->levo->vrednost)
        return l + d + 1;
    else
        return l + d;

}*/

//ZADATAK 10
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/stabla.h"
#include <string.h>
#include <stdlib.h>

void ogledalo(_cvor* drvo);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, k;
    _cvor* stablo = NULL;

    FILE* f = fopen(argv[1], "r");
    FILE* g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    stablo = unos(f);

    ogledalo(stablo);
    ispis(stablo, g);

    oslobodi(stablo);
    fclose(f);
    fclose(g);

    return 0;
}

void ogledalo(_cvor* drvo) {
    _cvor* pom;
    if (drvo == NULL)
        return;

    ogledalo(drvo->levo);
    ogledalo(drvo->desno);

    pom = drvo->levo;
    drvo->levo = drvo->desno;
    drvo->desno = pom;
}*/

//ZADATAK 11
//nemam f-ju za unos stabla koje nije sortirano

//ZADATAK 12
//mozda izbaci segmentation fault za neke primere
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/stabla.h"
#include <string.h>
#include <stdlib.h>

int identicna(_cvor* stablo1, _cvor* stablo2);

int main(int argc, char** argv) {

    if (argc != 3) {
        printf("Greska!");
        exit(0);
    }

    int i;
    _cvor* stablo1 = NULL, *stablo2 = NULL;

    FILE* f = fopen(argv[1], "r");
    FILE* k = fopen(argv[2], "r");
    FILE* g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL || f == NULL || k == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    stablo1 = unos(f);
    stablo2 = unos(k);

    if (identicna(stablo1, stablo2))
        printf("Jesu identicna stabla!\n");
    else
        printf("Nisu identicna stabla!\n");
    //ispis(stablo1, g);

    oslobodi(stablo1);
    oslobodi(stablo2);
    fclose(f);
    fclose(g);
    fclose(k);

    return 0;
}

int identicna(_cvor* stablo1, _cvor* stablo2) {
    int l, d;
    if (stablo1 == NULL && stablo2 == NULL)
        return 1;
    else if (stablo1 != NULL && stablo2 == NULL)
        return 0;
    else if (stablo1 == NULL && stablo2 != NULL)
        return 0;
    l = identicna(stablo1->levo, stablo2->levo);
    d = identicna(stablo1->desno, stablo2->desno);
    if (stablo1->vrednost == stablo2->vrednost && l == 1 && d == 1) {
        return 1;
    } else
        return 0;
}*/

//ZADATAK 13
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/stabla.h"
#include <string.h>
#include <stdlib.h>

int ravnomerno_izbalansirano(_cvor *stablo);
int dubina_stabla(_cvor* stablo);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, k;
    _cvor* stablo = NULL;

    FILE* f = fopen(argv[1], "r");
    FILE* g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    stablo = unos(f);

    if (ravnomerno_izbalansirano(stablo))
        printf("Stablo jeste ravnomerno izbalansirano!\n");
    else
        printf("Stablo nije ravnomerno izbalansirano!\n");

    //ispis(stablo, g);

    oslobodi(stablo);
    fclose(f);
    fclose(g);

    return 0;
}

int ravnomerno_izbalansirano(_cvor *stablo) {
    int l, d;
    if (stablo == NULL)
        return 1;
    l = dubina_stabla(stablo->levo);
    d = dubina_stabla(stablo->desno);

    if (abs(l - d) == 1 || abs(l - d) == 0)
        return 1;
    else
        return 0;

}

int dubina_stabla(_cvor* stablo) {
    int l, d;
    if (stablo == NULL)
        return 0;
    l = dubina_stabla(stablo->levo);
    d = dubina_stabla(stablo->desno);

    if (l > d)
        return l + 1;
    else
        return d + 1;

}*/

//ZADATAK 14
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/stabla.h"
#include <string.h>
#include <stdlib.h>

int prebroj(_cvor* stablo);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, k;
    _cvor* stablo = NULL;

    FILE* f = fopen(argv[1], "r");
    FILE* g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    stablo = unos(f);

    printf("%d\n", prebroj(stablo));

    //ispis(stablo, g);

    oslobodi(stablo);
    fclose(f);
    fclose(g);

    return 0;
}

int prebroj(_cvor* stablo) {
    int l, d;
    if (stablo == NULL)
        return 0;
    if (stablo->levo == NULL || stablo->desno == NULL)
        return 0;
    l = prebroj(stablo->levo);
    d = prebroj(stablo->desno);

    if ((stablo->vrednost % 2 != 0 && stablo->levo->vrednost % 2 != 0 && stablo->desno->vrednost % 2 != 0) ||
            (stablo->vrednost % 2 == 0 && stablo->levo->vrednost % 2 == 0 && stablo->desno->vrednost % 2 == 0))
        return l + d + 1;
    else
        return l + d;
}*/

//ZADATAK 15
//ne znam kako dobijaju vrednosti u test primerima ali kako je objasnjen zadatka mislim da je dobro

/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/stabla.h"
#include <string.h>
#include <stdlib.h>

int f5(_cvor* stablo);
int zbir(_cvor* stablo);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, k;
    _cvor* stablo = NULL;

    FILE* f = fopen(argv[1], "r");
    FILE* g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    stablo = unos(f);

    printf("%d\n", f5(stablo));

    //ispis(stablo, g);

    oslobodi(stablo);
    fclose(f);
    fclose(g);

    return 0;
}

int f5(_cvor* stablo) {
    int l, d;
    if (stablo == NULL)
        return 0;

    l = f5(stablo->levo);
    d = f5(stablo->desno);

    if (zbir(stablo->levo) > zbir(stablo->desno))
        return l + d + 1;
    else
        return l + d;
}

int zbir(_cvor* stablo) {
    int l, d;
    if (stablo == NULL)
        return 0;

    l = zbir(stablo->levo);
    d = zbir(stablo->desno);

    return l + d + stablo->vrednost;
}*/

//ZADATAK 16
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/stabla.h"
#include <string.h>
#include <stdlib.h>

int f5(_cvor* s, int k);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, k;
    _cvor* stablo = NULL;

    FILE* f = fopen(argv[1], "r");
    FILE* g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    stablo = unos(f);

    printf("Uneti nivo:\n");
    scanf("%d", &k);

    printf("%d\n", f5(stablo, k));

    //ispis(stablo, g);

    oslobodi(stablo);
    fclose(f);
    fclose(g);

    return 0;
}

int f5(_cvor* s, int k) {
    int l, d;
    if (s == NULL)
        return 0;

    l = f5(s->levo, k - 1);
    d = f5(s->desno, k - 1);

    if (k == 1)
        return s->vrednost;
    else if (k == 2) {
        if (l % 2 == 0 && d % 2 == 0)
            return l + d;
        else if (l % 2 != 0 && d % 2 != 0)
            return -l - d;
        else if (l % 2 != 0 && d % 2 == 0)
            return d - l;
        else if (l % 2 == 0 && d % 2 != 0)
            return l - d;
    } else return l + d;
}*/

//ZADATAK 17
// ne znam sta hoce
