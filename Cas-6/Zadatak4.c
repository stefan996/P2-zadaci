#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MAX_KAR 21

int bin_pretraga(char s[MAX_KAR], char niz[][MAX_KAR], int leva, int desna);

int main() {
    int n, i;
    char s[MAX_KAR], niz[MAX][MAX_KAR];

    printf("Uneti n i nisku:\n");
    scanf("%d%s", &n, s);

    printf("Uneti n niski:\n");
    for (i = 0; i < n; i++)
        scanf("%s", niz[i]);
    //niz opadajuci da bi radilo
    printf("%d", bin_pretraga(s, niz, 0, i - 1));
    return 0;
}

int bin_pretraga(char s[MAX_KAR], char niz[][MAX_KAR], int leva, int desna) {
    int i, k;
    if (leva > desna)
        return -1;
    k = (leva + desna) / 2;
    if (strcmp(niz[k], s) > 0)
        return bin_pretraga(s, niz, k + 1, desna);
    else if (strcmp(niz[k], s) < 0)
        return bin_pretraga(s, niz, leva, k - 1);
    else if (strcmp(niz[k], s) == 0)
        return k;
}
