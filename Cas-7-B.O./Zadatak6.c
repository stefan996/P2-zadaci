#include <stdio.h>
#include<stdlib.h>

void print_bits(int n);
unsigned set_bits(unsigned x, int p, int n, unsigned y);

int main() {
    int n, x, p, y;

    printf("Unesi x, y, p, n:\n");
    scanf("%d%d%d%d", &y, &x, &p, &n);

    if (p < 0 || p > 31 || p + n > 31 || n < 0 || n > 31) {
        printf("Greska!");
        exit(0);
    }

    printf("x:");
    print_bits(x);
    printf("y:");
    print_bits(y);
    printf("k:");
    print_bits(set_bits(x, p, n, y));

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

unsigned set_bits(unsigned x, int p, int n, unsigned y) {
    int i = 0;

    y = y << (sizeof (unsigned)*8 - n);
    y = y >> (sizeof (unsigned)*8 - n - p);
    i = ~i;
    i <<= n;
    i = ~i;
    i <<= p;
    i = ~i;
    x = x&i;

    return x | y;
}
