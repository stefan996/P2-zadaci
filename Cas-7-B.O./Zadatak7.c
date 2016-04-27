#include <stdio.h>
#include<stdlib.h>

void print_bits(int n);
unsigned invert_bits(unsigned x, int p, int n);

int main() {
    int n, x, p;

    printf("Unesi x, p, n:\n");
    scanf("%d%d%d", &x, &p, &n);

    if (p < 0 || p > 31 || p + n > 31 || n < 0 || n > 31) {
        printf("Greska!");
        exit(0);
    }

    printf("x  :");
    print_bits(x);
    printf("inv:");
    print_bits(invert_bits(x, p, n));

    return 0;
}

void print_bits(int n) {
    unsigned i = 1 << (sizeof (int)*8 - 1);

    while (i) {
        if (i & n)
            printf("1");
        else
            printf("0");

        i >>= 1;
    }
    putchar('\n');
}

unsigned invert_bits(unsigned x, int p, int n) {
    unsigned i = 0;
    i = ~i;
    i <<= n;
    i = ~i;
    i <<= p;

    return i^x;
}
