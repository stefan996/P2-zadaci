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
}
