#include <stdio.h>
#include<stdlib.h>

void print_bits(int n);
int suma(int n);

int main() {
    int x;

    printf("Unesi x:\n");
    scanf("%d", &x);

    if (suma(x) == 1)
        printf("Jeste!");
    else
        printf("Nije!");

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

int suma(int n) {
    int i, k = 1, br = 0;
    for (i = 0; i < (sizeof (int)*8); i++) {
        if (k & n)
            br++;
        k <<= 1;
    }
    return br;
}
