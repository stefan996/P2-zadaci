#include <stdio.h>
#include<stdlib.h>

void print_bits(int n);
unsigned right_rotate(unsigned x, int n);

int main() {
    int n, x;

    printf("Unesi x, n:\n");
    scanf("%d%d", &x, &n);

    if (n < 0) {
        printf("Greska!");
        exit(0);
    }

    printf("x  :");
    print_bits(x);
    printf("rot:");
    print_bits(right_rotate(x, n));

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

unsigned right_rotate(unsigned x, int n) {
    unsigned i = 0;
    n = n % (sizeof (unsigned)*8);
    i = i | x;
    i = i << (sizeof (unsigned)*8 - n);
    x = x>>n;

    return i | x;
}
