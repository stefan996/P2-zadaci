//Zadaci sa sajta: http://www.prog2-i-smer.matf.bg.ac.rs/vezbe.html
//Cas 9

//CAS-6 ZADATAK 6
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_KAR 21
#define KORAK 10

typedef struct {
    float po;
    char prez[MAX_KAR];
} STUDENT;

int poredi(const void* a, const void* b);

int main() {

    int i = 0, alocirano = KORAK;
    char pre[MAX_KAR];
    STUDENT* niz = NULL, *k, *pom = NULL;
    FILE *f = fopen("/home/luka/Desktop/Vezbanje/studenti.txt", "r");

    if (f == NULL) {
        printf("Greska!");
        exit(0);
    }

    niz = (STUDENT*) malloc(alocirano * sizeof (STUDENT));

    if (niz == NULL) {
        printf("Greska!");
        exit(0);
    }

    while (fscanf(f, "%s%f", niz[i].prez, &niz[i].po) != EOF) {
        i++;
        if (i >= alocirano) {
            alocirano += KORAK;
            pom = (STUDENT*) realloc(niz, alocirano * sizeof (STUDENT));
            if (pom == NULL) {
                printf("Greska!");
                exit(0);
            } else niz = pom;
        }
    }

    printf("Uneti prezime studenta:\n");
    scanf("%s", pre);

    k = (STUDENT*) bsearch(pre, niz, i, sizeof (STUDENT), poredi);

    if (k != NULL)
        printf("%.2f", k->po);
    else
        printf("Nema!");
    
    free(niz);
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

//ZADATAK 1
/*
#include<stdio.h>
#include<stdlib.h>

int main() {

    int *niz, n, i;

    printf("Uneti n:\n");
    scanf("%d", &n);

    niz = (int*) malloc(n * sizeof (int));
    
    if (niz == NULL) {
        printf("Greska!");
        exit(0);
    }

    printf("Uneti clanove niza:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    printf("Clanovi su:\n");
    for (i = 0; i < n; i++)
        printf("%d ", niz[i]);
    
    fclose(f);
    free(niz);

    return 0;
}*/

//ZADATAK 2
/*
#include<stdio.h>
#include<stdlib.h>

int main() {

    int *niz, n, i;

    printf("Uneti n:\n");
    scanf("%d", &n);

    niz = (int*) malloc(2 * n * sizeof (int));
    
    if (niz == NULL) {
        printf("Greska!");
        exit(0);
    }

    printf("Uneti clanove niza:\n");
    for (i = 0; i < 2 * n; i++)
        scanf("%d", &niz[i]);

    printf("Clanovi su:\n");
    for (i = 0; i < 2 * n - 1; i += 2)
        printf("%d/%d  ", niz[i], niz[i + 1]);
    
    fclose(f);
    free(niz);
    
    return 0;
}*/

//ZADATAK 3
/*
#include<stdio.h>
#include<stdlib.h>

int main() {

    int *niz = NULL, *pom = NULL, n, i = 0;
    FILE *f = fopen("/home/luka/Desktop/Vezbanje/brojevi.txt", "r");

    if (f == NULL) {
        printf("Greska!");
    }

    niz = (int*) realloc(niz, sizeof (int));

    if (niz == NULL) {
        printf("Greska!");
        exit(0);
    }

    while (fscanf(f, "%d", &niz[i]) != EOF) {
        i++;
        pom = (int *) realloc(niz, (i + 1) * sizeof (int));

        if (pom == NULL) {
            printf("Greska!");
            exit(0);
        } else niz = pom;
    }

    printf("Clanovi su:\n");
    for (n = 0; n < i; n++)
        printf("%d ", niz[n]);

    fclose(f);
    free(niz);

    return 0;
}*/

//ZADATAK 4
/*
#include<stdio.h>
#include<stdlib.h>

#define KORAK 10

int main() {

    int *niz = NULL, *pom = NULL, n, i = 0, alocirano = 0;
    FILE *f = fopen("/home/luka/Desktop/Vezbanje/brojevi.txt", "r");

    if (f == NULL) {
        printf("Greska!");
        exit(0);
    }

    alocirano += KORAK;
    niz = (int*) realloc(niz, alocirano * sizeof (int));

    if (niz == NULL) {
        printf("Greska!");
        exit(0);
    }

    while (fscanf(f, "%d", &niz[i]) != EOF) {
        i++;

        if (i >= alocirano) {
            alocirano += KORAK;
            pom = (int *) realloc(niz, alocirano * sizeof (int));

            if (pom == NULL) {
                printf("Greska!");
                exit(0);
            } else niz = pom;
        }
    }

    printf("Clanovi su:\n");
    for (n = 0; n < i; n++)
        printf("%d ", niz[n]);

    fclose(f);
    free(niz);

    return 0;
}*/

//ZADATAK 5
/*
#include<stdio.h>
#include<stdlib.h>

int main() {

    int **niz = NULL, *pom = NULL, n, m, i, j;

    printf("Uneti dimenzije matrice:\n");
    scanf("%d%d", &n, &m); // n-broj vrsta m-broj kolona

    niz = (int**) malloc(n * sizeof (int*));

    if (niz == NULL) {
        printf("Greska!");
        exit(0);
    }

    for (i = 0; i < n; i++) {
        pom = (int*) malloc(m * sizeof (int));
        if (pom == NULL) {
            printf("Greska!");
            exit(0);
        } else niz[i] = pom;
    }

    printf("Uneti elemente matrice:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &niz[i][j]);

    printf("Elementi matrice su:");
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < m; j++)
            printf("%d ", niz[i][j]);
    }

    for (i = 0; i < n; i++)
        free(niz[i]);

    free(niz);

    return 0;
}*/

//ZADATAK 6
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_DUZ 21

int poredi(const void* a, const void* b);

int main() {

    char** niz = NULL, *rec = NULL, *k;
    int n, i;

    rec = (char*) malloc(MAX_DUZ * sizeof (char));

    printf("Uneti rec:\n");
    scanf("%s", rec);

    printf("Uneti broj reci:\n");
    scanf("%d", &n);

    niz = (char**) malloc(n * sizeof (char*));

    if (niz == NULL) {
        printf("Greska!");
        exit(0);
    }

    for (i = 0; i < n; i++) {
        niz[i] = (char*) malloc(MAX_DUZ * sizeof (char));
        if (niz[i] == NULL) {
            printf("Greska!");
            exit(0);
        }
    }

    printf("Uneti reci:\n");
    for (i = 0; i < n; i++)
        scanf("%s", niz[i]);

    k = (char*) bsearch(rec, niz, n, sizeof (char*), poredi);

    if (k != NULL)
        printf("Nalazi se na poziciji:%ld\n", ((long int) k - (long int) niz) / (long int) sizeof (char*));
    else
        printf("Nema takve reci!\n");

    for (i = 0; i < n; i++)
        free(niz[i]);

    free(niz);

    return 0;
}

int poredi(const void* a, const void* b) {

    return strcmp((char*) a, *(char**) b);
}*/