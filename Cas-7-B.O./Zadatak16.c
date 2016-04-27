#include <stdio.h>
#include<stdlib.h>

#define MAX 32

unsigned novi_br(int* niz, int n, int p);

int main() {
    int x, n, niz[MAX], i;

    printf("Unesi x, n:\n");
    scanf("%d%d", &x, &n);

    if (n < 0 || n > 32) {
        printf("-1");
        exit(0);
    }

    printf("Uneti %d brojeva:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    printf("%u", novi_br(niz, n, x));

    return 0;
}

unsigned novi_br(int* niz, int n, int p) {
    int i;
    unsigned k = 1, x = 0;

    for (i = 0; i < 32; i++) {
        if (i < n) {
            if ((k & niz[i]) == (k & p))
                x |= k;
        } else if (0 == (k & p))
            x |= k;
        k <<= 1;
    }
    return x;
}
