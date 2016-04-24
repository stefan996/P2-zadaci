#include<stdio.h>

#define MAX 100

int lin_pretraga(int n, int x, int niz[MAX]);

int main() {
    int x, n, niz[MAX], i;

    printf("Uneti n i x:\n");
    scanf("%d%d", &n, &x);

    printf("Uneti n brojeva:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    printf("%d\n", lin_pretraga(n, x, niz));

    return 0;
}

int lin_pretraga(int n, int x, int niz[MAX]) {
    int i;
    for (i = 0; i < n; i++)
        if (niz[i] == x)
            return i;
    return -1;
}
