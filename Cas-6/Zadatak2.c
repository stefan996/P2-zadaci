#include<stdio.h>

#define MAX 100

int bin_pretraga(int x, int niz[MAX], int leva, int desna);

int main() {
    int x, n, niz[MAX], i;

    printf("Uneti n i x:\n");
    scanf("%d%d", &n, &x);

    printf("Uneti n brojeva:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    printf("%d\n", bin_pretraga(x, niz, 0, n));

    return 0;
}

int bin_pretraga(int x, int niz[MAX], int leva, int desna) {
    int i, k;
    if (leva > desna)
        return -1;
    k = (leva + desna) / 2;
    if (niz[k] > x)
        return bin_pretraga(x, niz, leva, k - 1);
    else if (niz[k] < x)
        return bin_pretraga(x, niz, k + 1, desna);
    else if (niz[k] == x)
        return k;
}
