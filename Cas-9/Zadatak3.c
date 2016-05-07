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
}
