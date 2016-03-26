#include<stdio.h>

int bin_koef(int n, int k);

int main() {
    int n, k;
    printf("Unesite broj n i k:\n");
    scanf("%d%d", &n, &k);
    if (k < 0)printf("0\n");
    printf("%d", bin_koef(n, k));
    return 0;
}

int bin_koef(int n, int k) {
    if (k == 1)
        return n;
    else
        return (n + 1 - k) * bin_koef(n, k - 1) / k;
}
