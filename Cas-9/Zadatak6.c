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
}
