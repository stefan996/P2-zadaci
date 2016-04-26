//Zadaci sa sajta: http://www.prog2-i-smer.matf.bg.ac.rs/vezbe.html
//Cas 7 Bitovski operatori

//ZADATAK 1
/*
#include <stdio.h>

void print_bits(int n);

int main() {
    int n;

    printf("Unesi broj:\n");
    scanf("%d", &n);

    print_bits(n);

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
}*/

//ZADATAK 2
/*
#include <stdio.h>
#include<stdlib.h>

int proveri(int n, int k);

int main() {
    int n, k;

    printf("Unesi broj i poziciju:\n");
    scanf("%d%d", &n, &k);

    if (k < 0 || n < 0 || k > 31) {
        printf("pozicija nije u dobrom ospegu");
        exit(0);
    }

    if (proveri(n, k))
        printf("jeste\n");
    else
        printf("nije\n");

    return 0;
}

int proveri(int n, int k) {
    int i = 1;
    i <<= k;

    return n & i;
}*/

//ZADATAK 3
/*
#include <stdio.h>
#include<stdlib.h>

int umetni(int n, int k);

int main() {
    int n, k;

    printf("Unesi broj i poziciju:\n");
    scanf("%d%d", &n, &k);

    if (k < 0 || n < 0 || k > 31) {
        printf("pozicija nije u dobrom ospegu");
        exit(0);
    }

    printf("%d\n", umetni(n, k));
    
    return 0;
}

int umetni(int n, int k) {
    int i = 1;
    i <<= k;

    return n | i;
}*/

//ZADATAK 4
/*
#include <stdio.h>
#include<stdlib.h>

int suma(int n);

int main() {
    int n;

    printf("Unesi broj:\n");
    scanf("%d", &n);

    printf("%d\n", suma(n));

    return 0;
}

int suma(int n) {
    int i, k = 1, br = 0;
    for (i = 0; i < (sizeof (int)*8); i++) {
        if (k & n)
            br++;
        k <<= 1;
    }
    return br;
}*/

//ZADATAK 5
/*
#include <stdio.h>
#include<stdlib.h>

void print_bits(int n);
unsigned get_bits(int x, int p, int n);

int main() {
    int n, x, p;

    printf("Unesi x, p, n:\n");
    scanf("%d%d%d", &x, &p, &n);

    if (p < 0 || p > 31 || p + n > 31 || n < 0 || n > 31) {
        printf("Greska!");
        exit(0);
    }

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
    i = i << (sizeof (unsigned)*8 - (unsigned) p - (unsigned) n);
    i = i >> (sizeof (unsigned)*8 - (unsigned) p - (unsigned) n);

    return i;
}*/

//ZADATAK 6
/*
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
}*/

//ZADATAK 7

//ZADATAK 8

//ZADATAK 9

//ZADATAK 10

//ZADATAK 12

//ZADATAK 13

//ZADATAK 14

//ZADATAK 15

//ZADATAK 16
