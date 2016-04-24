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
}

