//Zadaci sa sajta: http://www.prog2-i-smer.matf.bg.ac.rs/vezbe.html
//Cas 11

//ucitavanje je normalno iz fajla tj. ucitava sve brojeve ne onako kako pise "do 0"

//ZADATAK 1
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/liste.h"
#include <string.h>

_cvor* ubaci(_cvor* glava, int x, int y, int z);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int x, y, z;
    _cvor* lista = NULL;
    FILE* f = fopen(argv[1], "r");
    FILE* k = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (k == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    lista = napravi_listu(f);

    printf("Unesi elemente:\n");
    scanf("%d%d%d", &x, &y, &z);

    lista = ubaci(lista, x, y, z);

    ispis_liste(lista, k);

    oslobodi(lista);
    fclose(f);
    fclose(k);

    return 0;
}

_cvor* ubaci(_cvor* glava, int x, int y, int z) {
    _cvor* pom;
    if (glava == NULL)
        return glava;
    else if (glava->sledeci == NULL)
        return glava;
    else {
        if (glava->vrednost == x && glava->sledeci->vrednost == y) {
            pom = glava->sledeci;
            glava->sledeci = novi_cvor(z);
            glava->sledeci->sledeci = pom;

            glava->sledeci->sledeci = ubaci(glava->sledeci->sledeci, x, y, z);
            return glava;
        } else {
            glava->sledeci = ubaci(glava->sledeci, x, y, z);
            return glava;
        }
    }
}*/

//ZADATAK 2
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/liste.h"
#include <string.h>

int zbir(_cvor* lista1, _cvor* lista2);
int ima(_cvor* lista, int br);

int main(int argc, char** argv) {

    if (argc != 3) {
        printf("Greska!");
        exit(0);
    }

    int i, n;
    _cvor* lista1 = NULL, *lista2 = NULL;
    FILE* f = fopen(argv[1], "r"), *g = fopen(argv[2], "r");
    FILE* k = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL || k == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    lista1 = napravi_listu(f);
    lista2 = napravi_listu(g);

    printf("%d\n", zbir(lista1, lista2));

    fclose(g);
    fclose(f);
    fclose(k);

    return 0;
}

int zbir(_cvor* lista1, _cvor* lista2) {
    if (lista1 == NULL)
        return 0;
    else {
        if (ima(lista2, lista1->vrednost))
            return lista1->vrednost + zbir(lista1->sledeci, lista2);
        else
            return zbir(lista1->sledeci, lista2);
    }

}

int ima(_cvor* lista, int br) {
    if (lista == NULL)
        return 1;
    else {
        if (lista->vrednost == br)
            return 0;
        else
            return ima(lista->sledeci, br);
    }

}*/

//ZADATAK 3
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/liste.h"
#include <string.h>

_cvor* izbaci(_cvor *lista1, _cvor *lista2);
int ima(_cvor* lista, int br);

int main(int argc, char** argv) {

    if (argc != 3) {
        printf("Greska!");
        exit(0);
    }

    int i, n;
    _cvor* lista1 = NULL, *lista2 = NULL;
    FILE* f = fopen(argv[1], "r"), *g = fopen(argv[2], "r");
    FILE* k = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL || k == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    lista1 = napravi_listu(f);
    lista2 = napravi_listu(g);

    lista1 = izbaci(lista1, lista2);
    ispis_liste2(lista1, k);

    fclose(g);
    fclose(f);
    fclose(k);

    return 0;
}

_cvor* izbaci(_cvor *lista1, _cvor *lista2) {
    _cvor* pom;
    if (lista1 == NULL)
        lista1;
    else {
        if (ima(lista2, lista1->vrednost)) {
            pom = lista1->sledeci;
            free(lista1);
            lista1 = pom;

            lista1->sledeci = izbaci(lista1->sledeci, lista2);
            return lista1;
        } else {
            lista1->sledeci = izbaci(lista1->sledeci, lista2);
            return lista1;
        }
    }

}

int ima(_cvor* lista, int br) {
    if (lista == NULL)
        return 0;
    else {
        if (lista->vrednost == br)
            return 1;
        else
            return ima(lista->sledeci, br);
    }

}*/

//ZADATAK 4
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/liste.h"
#include <string.h>

void umetni(_cvor* lista);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, n;
    _cvor* lista = NULL;
    FILE* f = fopen(argv[1], "r");
    FILE* k = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (k == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    lista = napravi_listu(f);

    umetni(lista);

    ispis_liste2(lista, k);

    oslobodi(lista);
    fclose(f);
    fclose(k);

    return 0;
}

void umetni(_cvor* lista) {
    _cvor* pom;
    if (lista == NULL)
        return;
    else if (lista->sledeci == NULL)
        return;
    else {
        pom = lista->sledeci;
        lista->sledeci = novi_cvor(lista->vrednost - lista->sledeci->vrednost);
        lista->sledeci->sledeci = pom;

        umetni(lista->sledeci->sledeci);
    }
}*/

//ZADATAK 5
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/liste.h"
#include <string.h>

void f4(_cvor* lista);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, n;
    _cvor* lista = NULL;
    FILE* f = fopen(argv[1], "r");
    FILE* k = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (k == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    lista = napravi_listu(f);

    f4(lista);

    ispis_liste2(lista, k);

    oslobodi(lista);
    fclose(f);
    fclose(k);

    return 0;
}

void f4(_cvor* lista) {
    _cvor* pom;
    if (lista == NULL)
        return;
    else if (lista->sledeci == NULL)
        return;
    else {
        pom = lista->sledeci->sledeci;
        free(lista->sledeci);
        lista->sledeci = pom;

        f4(lista->sledeci);
    }
}*/

//ZADATAK 6
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/liste.h"
#include <string.h>

_cvor* f2(_cvor* lista);
_cvor* dodaj_na_kraj_f2(_cvor* glava, _cvor* lista);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, n;
    _cvor* lista = NULL;
    FILE* f = fopen(argv[1], "r");
    FILE* k = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (k == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    lista = napravi_listu(f);

    lista = f2(lista);

    ispis_liste2(lista, k);

    oslobodi(lista);
    fclose(f);
    fclose(k);

    return 0;
}

_cvor* f2(_cvor* lista) {
    _cvor* pom;
    if (lista == NULL)
        return NULL;

    pom = f2(lista->sledeci);
    lista->sledeci = NULL;
    pom = dodaj_na_kraj_f2(pom, lista);

    return pom;
}

_cvor* dodaj_na_kraj_f2(_cvor* glava, _cvor* lista) {
    if (glava == NULL)
        return lista;
    else {
        glava->sledeci = dodaj_na_kraj_f2(glava->sledeci, lista);
        return glava;
    }
}*/

//ZADATAK 7
/*
//slicno uradjen samo sto nije void
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/liste.h"
#include <string.h>

_cvor* f5(_cvor* l1, _cvor* l2);

int main(int argc, char** argv) {

    if (argc != 3) {
        printf("Greska!");
        exit(0);
    }

    _cvor* lista1 = NULL, *lista2 = NULL;
    FILE* f = fopen(argv[1], "r"), *g = fopen(argv[2], "r");
    FILE* k = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL || k == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    lista1 = napravi_listu(f);
    lista2 = napravi_listu(g);

    lista1 = f5(lista1, lista2);
    ispis_liste2(lista1, k);

    fclose(g);
    fclose(f);
    fclose(k);
    oslobodi(lista1);
    oslobodi(lista2);


    return 0;
}

_cvor* f5(_cvor* l1, _cvor* l2) {

    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    if (l1->vrednost < l2->vrednost) {
        l1->sledeci = f5(l1->sledeci, l2);
        return l1;
    } else {
        l2->sledeci = f5(l1, l2->sledeci);
        return l2;
    }
}*/

//ZADATAK 8
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/liste.h"
#include <string.h>

int f7(_cvor* lista);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, n;
    _cvor* lista = NULL;
    FILE* f = fopen(argv[1], "r");
    FILE* k = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (k == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    lista = napravi_listu(f);

    printf("%d\n", f7(lista));

    oslobodi(lista);
    fclose(f);
    fclose(k);

    return 0;
}

int f7(_cvor* lista) {
    if (lista == NULL)
        return 0;
    else if (lista->sledeci == NULL) {
        if (lista->vrednost % 2 != 0)
            return lista->vrednost--;
        else
            return lista->vrednost++;
    } else {
        if (lista->vrednost % 2 != 0) {
            lista->sledeci->vrednost--;
            return f7(lista->sledeci);
        } else {
            lista->sledeci->vrednost++;
            return f7(lista->sledeci);
        }
    }
}*/

//ZADATAK 9
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/liste.h"
#include <string.h>

int pojavljivanje_broja(_cvor* lista, int br);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, n;
    _cvor* lista = NULL;
    FILE* f = fopen(argv[1], "r");
    FILE* k = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (k == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    lista = napravi_listu(f);

    printf("Uneti broj:\n");
    scanf("%d", &n);

    printf("%d\n", pojavljivanje_broja(lista, n));

    oslobodi(lista);
    fclose(f);
    fclose(k);

    return 0;
}

int pojavljivanje_broja(_cvor* lista, int br) {
    if (lista == NULL)
        return 0;
    else {
        if (lista->vrednost == br)
            return pojavljivanje_broja(lista->sledeci, br) + 1;
        else
            return pojavljivanje_broja(lista->sledeci, br);
    }
}*/

//ZADATAK 10
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/liste.h"
#include <string.h>

int indeks_broja(_cvor* lista, int br);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, n;
    _cvor* lista = NULL;
    FILE* f = fopen(argv[1], "r");
    FILE* k = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (k == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    lista = napravi_listu(f);

    printf("Uneti broj:\n");
    scanf("%d", &n);

    i = indeks_broja(lista, n);

    if (i)
        printf("Indeks broja je: %d\n", i);
    else
        printf("Nema takvog broja!\n");


    oslobodi(lista);
    fclose(f);
    fclose(k);

    return 0;
}

int indeks_broja(_cvor* lista, int br) {
    int i;
    if (lista == NULL)
        return 0;
    else if (lista->vrednost == br)
        return 1;
    else {
        i = indeks_broja(lista->sledeci, br);
        if (i == 0)
            return 0;
        else
            return i + 1;
    }
}*/

//ZADATAK 11
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/liste.h"
#include <string.h>

void sazima(_cvor* lista, _cvor* glava);
int ima(_cvor* lista, int br);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, n;
    _cvor* lista = NULL, *pom = NULL;

    FILE* f = fopen(argv[1], "r");
    FILE* k = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (k == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    lista = napravi_listu(f);

    if (lista != NULL && ima(lista, lista->vrednost) > 1)
        i = 1;

    sazima(lista, lista);

    if (i == 1) {
        pom = lista;
        lista = lista->sledeci;
        free(pom);
    }

    ispis_liste2(lista, k);

    oslobodi(lista);
    fclose(f);
    fclose(k);

    return 0;
}

void sazima(_cvor* lista, _cvor* glava) {
    _cvor* pom;
    if (lista == NULL)
        return;
    else if (lista->sledeci == NULL) {
        if (ima(glava, lista->vrednost) > 1)
            lista = NULL;
    } else {
        if (ima(glava, lista->sledeci->vrednost) > 1) {
            sazima(lista->sledeci, glava);
            pom = lista->sledeci->sledeci;
            free(lista->sledeci);
            lista->sledeci = pom;
        } else
            sazima(lista->sledeci, glava);
    }

}

int ima(_cvor* lista, int br) {
    if (lista == NULL)
        return 0;
    else {
        if (lista->vrednost == br)
            return ima(lista->sledeci, br) + 1;
        else
            return ima(lista->sledeci, br);
    }
}*/

//ZADATAK 13
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/liste.h"
#include <string.h>

_cvor* dodaj_u_listu(_cvor *glava, _cvor *novi, int n);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, n, vr;
    _cvor* lista = NULL, *pom = NULL, *novi;

    FILE* f = fopen(argv[1], "r");
    FILE* k = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (k == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    lista = napravi_listu(f);
    printf("Uneti n i vrednost za novi cvor:\n");
    scanf("%d%d", &n, &vr);

    novi = novi_cvor(vr);

    lista = dodaj_u_listu(lista, novi, n);

    ispis_liste2(lista, k);

    oslobodi(lista);
    fclose(f);
    fclose(k);

    return 0;
}

//elementi liste krecu od 1.

_cvor* dodaj_u_listu(_cvor *glava, _cvor *novi, int n) {
    int i;
    _cvor* pom, *prvi = glava;

    if (glava == NULL)
        return glava;
    else if (n != 1) {
        for (i = 1; glava->sledeci != NULL && i < n - 1; i++)
            glava = glava->sledeci;
        pom = glava->sledeci;
        glava->sledeci = novi;
        novi->sledeci = pom;

        return prvi;
    } else {
        novi->sledeci = glava;

        return novi;
    }
}*/

//ZADATAK 14
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/liste.h"
#include <string.h>

void zbir_susednih(_cvor *glava);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, n;
    _cvor* lista = NULL, *pom = NULL;

    FILE* f = fopen(argv[1], "r");
    FILE* k = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (k == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    lista = napravi_listu(f);

    zbir_susednih(lista);

    ispis_liste2(lista, k);

    oslobodi(lista);
    fclose(f);
    fclose(k);

    return 0;
}

void zbir_susednih(_cvor *glava) {
    int i;
    _cvor* pom;
    if (glava == NULL)
        return;
    else if (glava->sledeci == NULL)
        return;
    else if (glava->sledeci->sledeci == NULL)
        return;
    else {
        if (glava->vrednost + glava->sledeci->sledeci->vrednost == glava->sledeci->vrednost)
            i = 1;
        else
            i = 0;
        zbir_susednih(glava->sledeci);
        if (i == 1) {
            pom = glava->sledeci;
            glava->sledeci = pom->sledeci;
            free(pom);

            return;
        } else
            return;
    }
}*/

//ZADATAK 16
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/liste.h"
#include <string.h>

_cvor* izbaci_nep(_cvor *glava);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, n;
    _cvor* lista = NULL, *pom = NULL;

    FILE* f = fopen(argv[1], "r");
    FILE* k = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (k == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    lista = napravi_listu(f);

    lista = izbaci_nep(lista);

    if (lista != NULL && lista->vrednost % 2 != 0) {
        pom = lista;
        lista = lista->sledeci;
        free(pom);
    }

    ispis_liste2(lista, k);

    oslobodi(lista);
    fclose(f);
    fclose(k);

    return 0;
}

_cvor* izbaci_nep(_cvor *glava) {
    int i;
    _cvor* pom;
    if (glava == NULL)
        return glava;
    else if (glava->sledeci == NULL)
        return glava;
    else {
        if (glava->sledeci->vrednost % 2 != 0)
            i = 1;
        else
            i = 0;
        glava->sledeci = izbaci_nep(glava->sledeci);
        if (i == 1) {
            pom = glava->sledeci;
            glava->sledeci = pom->sledeci;
            free(pom);

            return glava;
        } else
            return glava;
    }
}*/

//ZADATAK 17
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/liste.h"
#include <string.h>
#include <stdlib.h>

_cvor* izbaci_deljiv(_cvor *glava, int k);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, k;
    _cvor* lista = NULL, *pom = NULL;

    FILE* f = fopen(argv[1], "r");
    FILE* g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    lista = napravi_listu(f);

    printf("Uneti k:\n");
    scanf("%d", &k);

    if (k == 0) {
        printf("Deljenje nulom!\n");
        exit(0);
    }

    lista = izbaci_deljiv(lista, k);

    if (lista != NULL && lista->vrednost % k == 0) {
        pom = lista;
        lista = lista->sledeci;
        free(pom);
    }

    ispis_liste2(lista, g);

    oslobodi(lista);
    fclose(f);
    fclose(g);

    return 0;
}

_cvor* izbaci_deljiv(_cvor *glava, int k) {
    int i;
    _cvor* pom;
    if (glava == NULL)
        return glava;
    else if (glava->sledeci == NULL)
        return glava;
    else {
        if (glava->sledeci->vrednost % k == 0)
            i = 1;
        else
            i = 0;
        glava->sledeci = izbaci_deljiv(glava->sledeci, k);
        if (i == 1) {
            pom = glava->sledeci;
            glava->sledeci = pom->sledeci;
            free(pom);

            return glava;
        } else
            return glava;
    }
}*/
