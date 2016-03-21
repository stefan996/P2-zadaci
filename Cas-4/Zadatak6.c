#include<stdio.h>
#define max 100

int niz_c(int n, int niz[max]) {
    int i = 0;
    if (n < 10) {
        niz[i] = n;
        return ++i;
    } else {
        i = niz_c(n / 10, niz);
        niz[i] = n % 10;
        return ++i;
    }
}

int main() {

    int n, niz[max], i, d;

    printf("Unesi broj:\n");
    scanf("%d", &n);
    d = niz_c(n, niz);
    printf("Niz brojeva je:\n");

    for (i = 0; i < d; i++)printf("%d ", niz[i]);

    printf("\n");

    return 0;

}
