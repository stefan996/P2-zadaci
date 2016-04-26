#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

void insertion_sort(int niz[MAX], int n);
void umetni(int niz[MAX], int k);
int rastojanje(int niz[MAX], int n, int *l, int *d);

int main() {
    int n, i, l, d, niz[MAX], k;

    printf("Uneti n:\n");
    scanf("%d", &n);

    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    insertion_sort(niz, n);

    printf("Sortiran niz:");
    for (i = 0; i < n; i++)
        printf("%d ", niz[i]);

    k = rastojanje(niz, n, &l, &d);

    printf("\nNa najmanjem rastojanju %d su brojevi %d i %d!", k, niz[l], niz[d]);

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

int rastojanje(int niz[MAX], int n, int *l, int *d) {
    int i, r;
    r = niz[1] - niz[0];
    *d = 1;
    *l = 0;
    for (i = 2; i < n; i++)
        if ((niz[i] - niz[i - 1]) < r) {
            r = niz[i] - niz[i - 1];
            *l = i - 1;
            *d = i;
        }
    return r;
}
