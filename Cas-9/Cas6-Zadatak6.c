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
}
