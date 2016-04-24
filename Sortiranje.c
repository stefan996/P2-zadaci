//Zadaci sa sajta: http://www.prog2-i-smer.matf.bg.ac.rs/vezbe.html
//Cas 7

//ZADATAK 1

//ZADATAK 2
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MAX_KAR 21

void sortiranje(char niz[][MAX_KAR], int n);

int main() {

    int n, i, k;
    char niz[MAX][MAX_KAR];

    printf("Uneti n:\n");
    scanf("%d", &n);

    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%s", niz[i]);

    sortiranje(niz, n);

    for (i = 0; i < n; i++)
        printf("%s ", niz[i]);

    return 0;
}

void sortiranje(char niz[][MAX_KAR], int n) {
    int i, d1, d, j;
    char pom[MAX_KAR];
    for (j = 0; j < n; j++)
        for (i = 0; i < n - 1; i++) {
            d = strlen(niz[i]);
            d1 = strlen(niz[i + 1]);
            if (d1 < d) {
                strcpy(pom, niz[i]);
                strcpy(niz[i], niz[i + 1]);
                strcpy(niz[i + 1], pom);
            }
        }
}*/

//ZADATAK 3
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MAX_KAR 21

int poredi(const void* a, const void* b);

int main() {

    int n, i, k;
    char niz[MAX][MAX_KAR];

    printf("Uneti n:\n");
    scanf("%d", &n);

    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%s", niz[i]);

    qsort(niz, n, sizeof (char)*MAX_KAR, poredi);

    for (i = 0; i < n; i++)
        printf("%s ", niz[i]);

    return 0;
}

int poredi(const void* a, const void* b) {
    return strlen((char*) a) - strlen((char*) b);
}*/

//ZADATAK 4
/*  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MAX_KAR 21

void sortiranje(char niz[][MAX_KAR], int n);

int main() {

    int n, i, k;
    char niz[MAX][MAX_KAR];

    printf("Uneti n:\n");
    scanf("%d", &n);

    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%s", niz[i]);

    sortiranje(niz, n);

    for (i = 0; i < n; i++)
        printf("%s ", niz[i]);

    return 0;
}

void sortiranje(char niz[][MAX_KAR], int n) {
    int i, d1, d, j;
    char pom[MAX_KAR];
    for (j = 0; j < n; j++)
        for (i = 0; i < n - 1; i++) {
            if (strcmp(niz[i], niz[i + 1]) > 0) {
                strcpy(pom, niz[i]);
                strcpy(niz[i], niz[i + 1]);
                strcpy(niz[i + 1], pom);
            }
        }
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

    int n, i, k;
    char niz[MAX][MAX_KAR];

    printf("Uneti n:\n");
    scanf("%d", &n);

    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%s", niz[i]);

    qsort(niz, n, sizeof (char)*MAX_KAR, poredi);

    for (i = 0; i < n; i++)
        printf("%s ", niz[i]);

    return 0;
}

int poredi(const void* a, const void* b) {
    return strcmp((char*) a, (char*) b);
}*/

//ZADATAK 6
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

void insertion_sort(int niz[MAX], int n);
void umetni(int niz[MAX], int k);
int bin_pretraga(int niz[MAX], int p, int l, int d);

int main() {

    int n, i, k, niz[MAX], x;

    printf("Uneti n i x:\n");
    scanf("%d%d", &n, &x);

    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    insertion_sort(niz, n);

    printf("Sortiran niz:");
    for (i = 0; i < n; i++)
        printf("%d ", niz[i]);

    for (i = 0; i < n; i++) {
        k = bin_pretraga(niz, x - niz[i], 0, n);
        if (k >= 0) {
            printf("\nTo su clanovi %d i %d!", niz[k], niz[i]);
            return 0;
        } else {
            printf("\nNe postoji takav clan!");
            return 0;
        }
    }
    return 0;
}

void insertion_sort(int niz[MAX], int n) {
    int i;
    for (i = 1; i < n; i++)
        umetni(niz, i);
}

void umetni(int niz[MAX], int k) {
    int i, x, j;
    x = niz[k];
    for (i = 0; i < k; i++)
        if (x < niz[i]) {
            for (j = k; j > i; j--)
                niz[j] = niz[j - 1];
            niz[i] = x;
            break;
        }
}

int bin_pretraga(int niz[MAX], int p, int l, int d) {
    int k;
    if (l > d)
        return -1;
    else {
        k = (l + d) / 2;
        if (niz[k] > p)
            return bin_pretraga(niz, p, l, k - 1);
        else if (niz[k] < p)
            return bin_pretraga(niz, p, k + 1, d);
        else return k;
    }
}*/

//ZADATAK 7
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MAX_KAR 21

typedef struct {
    float oc;
    char ime[MAX_KAR], prez[MAX_KAR];
} STUDENT;

void insertion_sort(STUDENT niz[MAX], int n);
void umetni(STUDENT niz[MAX], int k);

int main(int argc, char** argv) {

    int i = 0, j;
    STUDENT niz[MAX];

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    FILE *f = fopen(argv[1], "r");

    if (f == NULL) {
        printf("Greska!");
        exit(0);
    }

    while (fscanf(f, "%s%s%f", niz[i].ime, niz[i].prez, &niz[i].oc) != EOF)
        i++;


    insertion_sort(niz, i);

    for (j = 0; j < i; j++)
        printf("%s %s %f\n", niz[j].ime, niz[j].prez, niz[j].oc);

    return 0;
}

void insertion_sort(STUDENT niz[MAX], int n) {
    int i;
    for (i = 1; i < n; i++)
        umetni(niz, i);
}

void umetni(STUDENT niz[MAX], int k) {
    int i, j;
    STUDENT x;
    x = niz[k];
    for (i = 0; i < k; i++)
        if (x.oc < niz[i].oc) {
            for (j = k; j > i; j--)
                niz[j] = niz[j - 1];
            niz[i] = x;
            break;
        }
}*/

//ZADATAK 8

//ZADATAK 9

//ZADATAK 10

//ZADATAK 11

//ZADATAK 12

