#include<stdio.h>

int fib(int n);

int main() {
    int n, m;
    printf("Unesite broj n:\n");
    scanf("%d", &n);
    if (n == 0)printf("0\n");
    printf("%d. clan Fibonacijevog niza je: %d\n", n, fib(n));
    return 0;
}

int fib(int n) {
    if (n == 2 || n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}
