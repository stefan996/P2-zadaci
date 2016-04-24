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
}
