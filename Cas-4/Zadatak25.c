#include<stdio.h>

int izbaci(int n);

int main() {
    int n;
    printf("Unesite broj n:\n");
    scanf("%d", &n);
    printf("%d\n", izbaci(n));
    return 0;
}

int izbaci(int n) {
    if (n < 100)
        return n % 10;
    else
        return izbaci(n / 100)*10 + n % 10;
}
