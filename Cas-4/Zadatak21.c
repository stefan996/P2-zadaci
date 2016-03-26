#include<stdio.h>

int nzd(int n, int m);

int main() {
    int n, m;
    printf("Unesite broj n i m:\n");
    scanf("%d%d", &n, &m);
    printf("NZD je:%d\n", nzd(n, m));
    return 0;
}

int nzd(int n, int m) {
    if (n % m == 0)
        return m;
    else
        nzd(m, n % m);
}
