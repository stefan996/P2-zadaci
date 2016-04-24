#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define MAX_KAR 6

int bin_pretraga(char niz[][MAX_KAR], int l, int d);

int main() {

    int n, i, k;
    char niz[MAX][MAX_KAR];

    printf("Uneti n:\n");
    scanf("%d", &n);

    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%s", &niz[i]);

    printf("%d", bin_pretraga(niz, 0, n));

    return 0;
}

int bin_pretraga(char niz[][MAX_KAR], int l, int d) {
    int k = (l + d) / 2;
    if (l > d)
        return -1;
    if (niz[k][0] == 'b') {
        if (niz[k - 1][0] == 'f')
            return k;
        else
            return bin_pretraga(niz, l, k - 1);
    } else if (niz[k][0] == 'f')
        return bin_pretraga(niz, k + 1, d);
}
