#include<stdio.h>
#define max 100

int palindrom(int niz[max], int *k, int n);

int main() {

    int i, n, k, niz[max];

    printf("Unesi n:\n");
    scanf("%d", &n);

    k = n - 1;

    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    if (palindrom(niz, &k, n - 1))
        printf("Jeste!");
    else
        printf("Nije!");
    printf("\n");

    return 0;

}

int palindrom(int niz[max], int *k, int n) {

    if (n == 0) {
        if (niz[*k] == niz[n]) {
            (*k)--;
            return 1;
        } else
            return 0;
    } else {
        palindrom(niz, k, n - 1);
        if (niz[*k] == niz[n]) {
            (*k)--;
            return 1;
        } else
            return 0;
    }
}
