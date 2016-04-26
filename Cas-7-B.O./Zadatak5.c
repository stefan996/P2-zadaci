#include <stdio.h>
#include<stdlib.h>

void print_bits(unsigned n);
unsigned get_bits(unsigned x, unsigned p, unsigned n);

int main() {
    unsigned n, x, p;

    printf("Unesi x, p, n:\n");
    scanf("%u%u%u", &x, &p, &n);

    print_bits(x);
    print_bits(get_bits(x, p, n));

    return 0;
}

void print_bits(unsigned n) {
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

unsigned get_bits(unsigned x, unsigned p, unsigned n) {
    x = x>>p;
    x = x << p;
    x = x << (sizeof (int)*8 - p - n);
    x = x >> (sizeof (int)*8 - p - n);

    return x;
}
