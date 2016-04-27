//Pod a:
/*
#include <stdio.h>
#include<stdlib.h>

void print_bits(int n);
int suma(int n);
int naj_poz(int n);

int main() {
    int x;

    printf("Unesi x:\n");
    scanf("%d", &x);
    print_bits(naj_poz(x));
    printf("\n%d", naj_poz(x));

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

int naj_poz(int n) {
    unsigned i = 0, br;
    i = ~i;
    br = suma(n);
    i = i << (sizeof (unsigned)*8 - br);
    i >>= 1;

    return i;
}*/

//Pod b:
/*
#include <stdio.h>
#include<stdlib.h>

void print_bits(int n);
int suma(int n);
int naj_poz(int n);

int main() {
    int x;

    printf("Unesi x:\n");
    scanf("%d", &x);
    print_bits(naj_poz(x));
    printf("\n%d", naj_poz(x));

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

int naj_poz(int n) {
    unsigned i = 0, br;
    i = ~i;
    br = suma(n);
    i = i >> (sizeof (unsigned)*8 - br);

    return i;
}*/
