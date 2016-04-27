#include <stdio.h>
#include<stdlib.h>

#define MAX 100

int novi_br(int* niz, int n);

int main() {
    int n, niz[MAX], i;

    printf("Unesi n:\n");
    scanf("%d", &n);

    if (n < 0 || n > 32) {
        printf("-1");
        exit(0);
    }

    printf("Uneti %d brojeva:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    printf("%d", novi_br(niz, n));

    return 0;
}

int novi_br(int* niz, int n) {
    int i, j, x = 0;
    unsigned k = 1;

    for (i = 0; i < n; i++) {
        k <<= i;
        x = x | (niz[i] & k);
        k >>= i;
    }
    return x;
}
