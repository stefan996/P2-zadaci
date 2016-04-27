#include <stdio.h>
#include<stdlib.h>

void print_bits(int n);
int broji(int n);

int main() {
    int x;

    printf("Unesi x:\n");
    scanf("%d", &x);

    printf("%d\n", broji(x));

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

int broji(int n) {
    unsigned i1 = 1, i2 = 2;
    int br = 0;

    while (i2) {
        if ((i1 & n) && (i2 & n))
            br++;
        i1 <<= 1;
        i2 <<= 1;
    }

    return br;
}
