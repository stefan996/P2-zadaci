#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MAX_KAR 21

typedef struct {
    float oc;
    char ime[MAX_KAR], prez[MAX_KAR];
} STUDENT;

int poredi(const void* a, const void* b);

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


    qsort(niz, i, sizeof (STUDENT), poredi);

    for (j = 0; j < i; j++)
        printf("%s %s %f\n", niz[j].ime, niz[j].prez, niz[j].oc);

    return 0;
}

int poredi(const void* a, const void* b) {
    STUDENT* n = (STUDENT*) a;
    STUDENT* m = (STUDENT*) b;

    return n->oc - m->oc;
}
