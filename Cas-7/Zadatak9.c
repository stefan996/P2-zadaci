#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

void insertion_sort(int niz[MAX], int n);
void umetni(int niz[MAX], int k);
int prebroj(int niz[MAX], int n);

int main() {
    int n, i, k, niz[MAX];

    printf("Uneti n:\n");
    scanf("%d", &n);

    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    insertion_sort(niz, n);

    printf("Sortiran niz:");
    for (i = 0; i < n; i++)
        printf("%d ", niz[i]);

    printf("\n%d", prebroj(niz, n));

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

int prebroj(int niz[MAX], int n) {
    int i, br = 1, br_max = 1, max;
    max = niz[0];
    for (i = 1; i < n; i++) {
        if (niz[i] != niz[i - 1]) {
            if (br > br_max) {
                br_max = br;
                max = niz[i - 1];
            }
            br = 1;
        } else
            br++;
    }

    return max;
}
