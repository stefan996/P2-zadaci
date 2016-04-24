//Zadaci sa sajta: http://www.prog2-i-smer.matf.bg.ac.rs/vezbe.html
//Cas 6

//ZADATAK 1
/*
#include<stdio.h>

#define MAX 100

int lin_pretraga(int n, int x, int niz[MAX]);

int main() {
    int x, n, niz[MAX], i;

    printf("Uneti n i x:\n");
    scanf("%d%d", &n, &x);

    printf("Uneti n brojeva:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    printf("%d\n", lin_pretraga(n, x, niz));

    return 0;
}

int lin_pretraga(int n, int x, int niz[MAX]) {
    int i;
    for (i = 0; i < n; i++)
        if (niz[i] == x)
            return i;
    return -1;
}*/

//ZADATAK 2
/*
#include<stdio.h>

#define MAX 100

int bin_pretraga(int x, int niz[MAX], int leva, int desna);

int main() {
    int x, n, niz[MAX], i;

    printf("Uneti n i x:\n");
    scanf("%d%d", &n, &x);

    printf("Uneti n brojeva:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    printf("%d\n", bin_pretraga(x, niz, 0, n));

    return 0;
}

int bin_pretraga(int x, int niz[MAX], int leva, int desna) {
    int i, k;
    if (leva > desna)
        return -1;
    k = (leva + desna) / 2;
    if (niz[k] > x)
        return bin_pretraga(x, niz, leva, k - 1);
    else if (niz[k] < x)
        return bin_pretraga(x, niz, k + 1, desna);
    else if (niz[k] == x)
        return k;
}*/

//ZADATAK 3
/*
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int poredi(const void * a, const void * b);

int main() {
    int x, n, niz[MAX], i;
    int* br;

    printf("Uneti n i x:\n");
    scanf("%d%d", &n, &x);

    printf("Uneti n brojeva:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    br = (int*) bsearch(&x, niz, n, sizeof (int), poredi);

    if (br != NULL)
        printf("%ld", br - niz);
    else
        printf("Nije pronadjen!");

    return 0;
}

int poredi(const void * a, const void * b) {
    return (*(int*) a - *(int*) b);
}*/

//ZADATAK 4
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MAX_KAR 21

int bin_pretraga(char s[MAX_KAR], char niz[][MAX_KAR], int leva, int desna);

int main() {
    int n, i;
    char s[MAX_KAR], niz[MAX][MAX_KAR];

    printf("Uneti n i nisku:\n");
    scanf("%d%s", &n, s);

    printf("Uneti n niski:\n");
    for (i = 0; i < n; i++)
        scanf("%s", niz[i]);
    //niz opadajuci da bi radilo
    printf("%d", bin_pretraga(s, niz, 0, i - 1));
    return 0;
}

int bin_pretraga(char s[MAX_KAR], char niz[][MAX_KAR], int leva, int desna) {
    int i, k;
    if (leva > desna)
        return -1;
    k = (leva + desna) / 2;
    if (strcmp(niz[k], s) > 0)
        return bin_pretraga(s, niz, k + 1, desna);
    else if (strcmp(niz[k], s) < 0)
        return bin_pretraga(s, niz, leva, k - 1);
    else if (strcmp(niz[k], s) == 0)
        return k;
}*/

//ZADATAK 5
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MAX_KAR 21

int poredi(const void* a, const void* b);

int main() {
    int n, i;
    char* k;
    char s[MAX_KAR], niz[MAX][MAX_KAR];

    printf("Uneti n i nisku:\n");
    scanf("%d%s", &n, s);

    printf("Uneti n niski:\n");
    for (i = 0; i < n; i++)
        scanf("%s", niz[i]);

    k = (char*) bsearch(s, niz, n, MAX_KAR * sizeof (char), poredi);

    if (k != NULL)
        printf("%ld\n", ((long int) k - (long int) niz) / MAX_KAR);
    else
        printf("Nema!");
    //niz opadajuci da bi radilo
    return 0;
}

int poredi(const void* a, const void* b) {

    return strcmp(((char *) b), ((char *) a));
}*/

//ZADATAK 6
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MAX_KAR 21

typedef struct {
    float po;
    char prez[MAX_KAR];
} STUDENT;

int poredi(const void* a, const void* b);

int main() {

    int i = 0, j;
    char pre[MAX_KAR];
    STUDENT niz[MAX];
    STUDENT *k;
    FILE *f = fopen("/home/luka/Desktop/Vezbanje/studenti.txt", "r");

    if (f == NULL) {
        printf("Greska!");
        exit(0);
    }

    while (fscanf(f, "%s%f", niz[i].prez, &niz[i].po) != EOF)
        i++;

    printf("Uneti prezime studenta:\n");
    scanf("%s", pre);

    k = (STUDENT*) bsearch(pre, niz, i, sizeof (STUDENT), poredi);

    if (k != NULL)
        printf("%.2f", k->po);
    else
        printf("Nema!");

    fclose(f);

    return 0;
}

//niz mora da bude rastuci
//strcmp(n->prez, m) - promeniti ako je niz opadajuci

int poredi(const void* a, const void* b) {

    STUDENT* n = (STUDENT*) b;
    char* m = (char*) a;

    return strcmp(m, n->prez);
}*/

//ZADATAK 7
/*
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int bin_pretraga(int niz[MAX], int l, int d);

int main() {

    int n, i, niz[MAX], k;

    printf("Uneti broj elemenata:\n");
    scanf("%d", &n);

    printf("Uneti %d elemenata:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    k = bin_pretraga(niz, 0, n);
    if (k == -1)
        printf("Nema takvog broja!");
    else
        printf("%d\n", niz[k]);


    return 0;
}

int bin_pretraga(int niz[MAX], int l, int d) {
    int k = (l + d) / 2;
    if (l > d)
        return -1;

    if (niz[k] > 100) {
        if (niz[k - 1] < 100)
            return k;
        else
            return bin_pretraga(niz, l, k);
    } else if (niz[k] < 100)
        return bin_pretraga(niz, k + 1, d);
    else
        return k;
}*/

//ZADATAK 8
/*
#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define MAX_KAR 6

int bin_pretraga(char niz[][MAX_KAR], int l, int d);

int main() {

    int n, i, k;
    char niz[MAX][MAX_KAR];

    printf("Uneti n:\n");
    scanf("%d", &n);

    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%s", &niz[i]);

    printf("%d", bin_pretraga(niz, 0, n));

    return 0;
}

int bin_pretraga(char niz[][MAX_KAR], int l, int d) {
    int k = (l + d) / 2;
    if (l > d)
        return -1;
    if (niz[k][0] == 'b') {
        if (niz[k - 1][0] == 'f')
            return k;
        else
            return bin_pretraga(niz, l, k - 1);
    } else if (niz[k][0] == 'f')
        return bin_pretraga(niz, k + 1, d);
}*/