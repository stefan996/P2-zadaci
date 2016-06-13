//Ispitni zadaci

//Oktobar 2015

//ZADATAK 1
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv) {
    float *niz, s, max;
    int i = 1, k = 0;

    if ((argc - 1) % 3 != 0) {
        printf("-1\n");
        exit(0);
    }

    argc /= 3;
    niz = malloc(argc * sizeof (float));

    while (argc--) {
        s = (atof(argv[i]) + atof(argv[i + 1]) + atof(argv[i + 2])) / 2;
        niz[k] = sqrt(s * (s - atof(argv[i]))*(s - atof(argv[i + 1]))*(s - atof(argv[i + 2])));
        k++;
        i += 3;
    }

    max = niz[0];
    for (i = 1; i < k; i++)
        if (niz[i] > max)
            max = niz[i];


    printf("%.2f\n", max);

    return 0;
}
*/

//ZADATAK 2
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_KAR 21

typedef struct {
    int br_koef;
    char ime[MAX_KAR];
    float niz_koef[MAX_KAR];
} polinom;

void sort(polinom* p, int br_pol);

int main(int argc, char** argv) {
    int br_pol, i = 0, k;
    polinom *p;
    FILE* f = fopen("polinomi.txt", "r");

    if (f == NULL) {
        printf("Greska u otvaranju datoteke!\n");
        exit(0);
    }

    fscanf(f, "%d", &br_pol);

    p = malloc(br_pol * sizeof (polinom));
    if (p == NULL) {
        printf("Greska pri alokaciji memorije!\n");
        exit(0);
    }

    while (fscanf(f, "%s%d", p[i].ime, &p[i].br_koef) != EOF) {
        for (k = 0; k < p[i].br_koef; k++)
            fscanf(f, "%f", &p[i].niz_koef[k]);
        i++;
    }

    sort(p, br_pol);

    for (i = 0; i < br_pol; i++)
        printf("%s\n", p[i].ime);
    return 0;
}

void sort(polinom* p, int br_pol) {
    int i, j;
    float pom;
    char s[MAX_KAR];
    for (i = 1; i < br_pol; i++)
        for (j = 0; j < br_pol - 1; j++) {
            if (p[j].br_koef < p[j + 1].br_koef) {
                pom = p[j].br_koef;
                p[j].br_koef = p[j + 1].br_koef;
                p[j + 1].br_koef = pom;
            } else if (p[j].br_koef == p[j + 1].br_koef) {
                if (strlen(p[j].ime) < strlen(p[j + 1].ime)) {
                    strcpy(s, p[j].ime);
                    strcpy(p[j].ime, p[j + 1].ime);
                    strcpy(p[j + 1].ime, s);
                }
            }
        }
}*/

//ZADATAK 3
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_BR 32

unsigned inv(int niz[MAX_BR], int n);

int main(int argc, char** argv) {
    int i, n, niz[MAX_BR];
    unsigned x;

    printf("Uneti n:\n");
    scanf("%d", &n);

    if (n > 32) {
        printf("-1\n");
        exit(0);
    }

    printf("Uneti n brojeva:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    printf("%u\n", inv(niz, n));
    return 0;
}

unsigned inv(int niz[MAX_BR], int n) {
    unsigned x = 0, mask = 1;
    int i;

    for (i = n - 1; i >= 0; i--) {
        x |= (mask & (~(niz[i] >> i)));
        x <<= 1;
    }
    return x >> 1;
}*/

//ZADATAK 4
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/liste.h"
#include <string.h>

void f4(_cvor* lista, int k);
int zbir_cifara(int n);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int n;
    _cvor* lista = NULL;
    FILE* f = fopen(argv[1], "r");
    FILE* k = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (k == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    lista = napravi_listu(f);

    printf("Unesi k:\n");
    scanf("%d", &n);
    //k mi se koristi za datoteku pa sam uzeo n

    f4(lista, n);

    ispis_liste(lista, k);

    oslobodi(lista);
    fclose(f);
    fclose(k);

    return 0;
}

void f4(_cvor* lista, int k) {
    int i, z1, z2;
    _cvor* pom = NULL, *novi = NULL;
    if (lista == NULL)
        return;
    else if (lista->sledeci == NULL)
        return;

    if (abs(lista->vrednost - lista->sledeci->vrednost) == k || abs(lista->vrednost + lista->sledeci->vrednost) == k)
        i = 1;
    else
        i = 0;
    f4(lista->sledeci, k);
    if (i == 1) {
        z1 = zbir_cifara(lista->vrednost);
        z2 = zbir_cifara(lista->sledeci->vrednost);
        pom = lista->sledeci;
        novi = novi_cvor(z1 + z2);
        lista->sledeci = novi;
        novi->sledeci = pom;
    }
}

int zbir_cifara(int n) {
    int cj, rez = 0;
    while (n) {
        cj = n % 10;
        n /= 10;
        rez += cj;
    }

    return rez;
}*/

//ZADATAK 5
/*
#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/stabla.h"
#include <string.h>
#include <stdlib.h>

int f5(_cvor* s);

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

int f5(_cvor* s) {
    static int nivo = 1;
    int l, d;
    if (s == NULL)
        return 0;
    nivo++;
    l = f5(s->levo);
    d = f5(s->desno);
    nivo--;
    if (nivo == 1) {
        return l + d - s->vrednost;
    }
    if (nivo % 2 == 0) {
        return s->vrednost - l - d;
    } else {
        return s->vrednost - l - d;
    }
}*/
