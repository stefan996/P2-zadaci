#include<stdio.h>
#define MAX 100

int max_br(int niz[MAX], int n);

int main() {

    int i, n, niz[MAX];

    printf("Unesi n:\n");
    scanf("%d", &n);

    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    printf("Max je: %d", max_br(niz, n - 1));

    printf("\n");

    return 0;

}

int max_br(int niz[MAX], int n) {
    int max;

    if (n == 0)
        max = niz[0];
    else {
        max = max_br(niz, n - 1);
        if (niz[n] > max)max = niz[n];
    }
    return max;
}
