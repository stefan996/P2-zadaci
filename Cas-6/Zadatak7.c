#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int bin_pretraga(int niz[MAX], int l, int d);

int main() {

    int n, i, niz[MAX], k;

    printf("Uneti broj elemenata:\n");
    scanf("%d", &n);

    printf("Uneti %d elemenata:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    k = bin_pretraga(niz, 0, n);
    if (k == -1)
        printf("Nema takvog broja!");
    else
        printf("%d\n", niz[k]);


    return 0;
}

int bin_pretraga(int niz[MAX], int l, int d) {
    int k = (l + d) / 2;
    if (l > d)
        return -1;

    if (niz[k] > 100) {
        if (niz[k - 1] < 100)
            return k;
        else
            return bin_pretraga(niz, l, k);
    } else if (niz[k] < 100)
        return bin_pretraga(niz, k + 1, d);
    else
        return k;
}
