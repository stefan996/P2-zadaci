#include <stdio.h>
#include<stdlib.h>

void print_bits(int n);
unsigned get_bits(int x, int p, int n);

int main() {
    int n, x, p;

    printf("Unesi x, p, n:\n");
    scanf("%d%d%d", &x, &p, &n);

    print_bits(x);
    print_bits(get_bits(x, p, n));

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

unsigned get_bits(int x, int p, int n) {
    unsigned i = x;
    i = i>>p;
    i = i << p;
    i = i << (sizeof (int)*8 - p - n);
    i = i >> (sizeof (int)*8 - p - n);

    return i;
}
