#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

void insertion_sort(int niz[MAX], int n);
void umetni(int niz[MAX], int k);
int bin_pretraga(int niz[MAX], int p, int l, int d);

int main() {

    int n, i, k, niz[MAX], x;

    printf("Uneti n i x:\n");
    scanf("%d%d", &n, &x);

    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    insertion_sort(niz, n);

    printf("Sortiran niz:");
    for (i = 0; i < n; i++)
        printf("%d ", niz[i]);

    for (i = 0; i < n; i++) {
        k = bin_pretraga(niz, x - niz[i], 0, n);
        if (k >= 0) {
            printf("\nTo su clanovi %d i %d!", niz[k], niz[i]);
            return 0;
        } else {
            printf("\nNe postoji takav clan!");
            return 0;
        }
    }
    return 0;
}

void insertion_sort(int niz[MAX], int n) {
    int i;
    for (i = 1; i < n; i++)
        umetni(niz, i);
}

void umetni(int niz[MAX], int k) {
    int i, x, j;
    x = niz[k];
    for (i = 0; i < k; i++)
        if (x < niz[i]) {
            for (j = k; j > i; j--)
                niz[j] = niz[j - 1];
            niz[i] = x;
            break;
        }
}

int bin_pretraga(int niz[MAX], int p, int l, int d) {
    int k;
    if (l > d)
        return -1;
    else {
        k = (l + d) / 2;
        if (niz[k] > p)
            return bin_pretraga(niz, p, l, k - 1);
        else if (niz[k] < p)
            return bin_pretraga(niz, p, k + 1, d);
        else return k;
    }
} 
