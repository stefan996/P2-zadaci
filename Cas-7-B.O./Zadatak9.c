#include <stdio.h>
#include<stdlib.h>

void print_bits(int n);
unsigned mirror(unsigned x);

int main() {
    int x;

    printf("Unesi x:\n");
    scanf("%d", &x);

    printf("x   :");
    print_bits(x);
    printf("mirr:");
    print_bits(mirror(x));

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

unsigned mirror(unsigned x) {
    unsigned i = 1;
    unsigned n = 0;
    int br = sizeof (unsigned)*8 - 1;
    while (br--) {
        n = n | (x & i);
        n <<= 1;
        x >>= 1;

    }
    return n;
}
