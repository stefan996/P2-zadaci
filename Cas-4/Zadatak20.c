#include<stdio.h>
#define max 100

void niz(int n, int t[max]);

int main() {
    int n, i, t[max], k = 1;
    printf("Unesite broj n:\n");
    scanf("%d", &n);
    printf("Unesite niz:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &t[i]);
    niz(n, t);
    for (i = 0; i < n; i++)
        printf("%d ", t[i]);
    return 0;
}

void niz(int n, int t[max]) {
    if (n == 1)
        t[0] += 1;
    else {
        niz(n - 1, t);
        t[n - 1] += n;
    }
}
