#include<stdio.h>
#define MAX 100

int skalar_proiz(int niz1[MAX], int niz2[MAX], int n);

int main() {

    int i, n, niz1[MAX], niz2[MAX];

    printf("Unesi n:\n");
    scanf("%d", &n);

    printf("Uneti niz1:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz1[i]);

    printf("Uneti niz2:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz2[i]);

    printf("Skalarni proizvod je: %d", skalar_proiz(niz1, niz2, n - 1));

    printf("\n");

    return 0;

}

int skalar_proiz(int niz1[MAX], int niz2[MAX], int n) {

    if (n == 0)
        return niz1[n] * niz2[n];
    else
        return niz1[n] * niz2[n] + skalar_proiz(niz1, niz2, n - 1);
}
