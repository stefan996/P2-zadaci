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
}
