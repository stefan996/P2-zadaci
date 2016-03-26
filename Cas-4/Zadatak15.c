#include<stdio.h>

void suma(int n, int *s);

int main() {
    int n, s = 0;
    printf("Unesite broj:\n");
    scanf("%d", &n);
    suma(n, &s);
    printf("%d", s);
    return 0;
}

void suma(int n, int *s) {
    static int a = n;
    if (n == 1)
        *s += 1;
    else {
        suma(n - 1, s);
        if (a % n == 0) *s += n;
    }
}
