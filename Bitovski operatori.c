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
/*
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
}*/

//ZADATAK 8
/*
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
}*/

//ZADATAK 9
/*
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
}*/

//ZADATAK 10
/*
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
}*/

//ZADATAK 11
/*
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
}*/

//ZADATAK 12

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

//ZADATAK 13

//ZADATAK 14
/*
#include <stdio.h>
#include<stdlib.h>

#define MAX_KAR 9

void print_bits(int n);
void nadji_heksa(int n, char s[MAX_KAR]);
char nadji_br(int n);

int main() {
    int x;
    char s[MAX_KAR];

    printf("Unesi x:\n");
    scanf("%d", &x);

    nadji_heksa(x, s);

    printf("%s", s);

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

char nadji_br(int n) {
    switch (n) {
        case 0: return 0 + '0';
        case 1: return 1 + '0';
        case 10: return 2 + '0';
        case 11: return 3 + '0';
        case 100: return 4 + '0';
        case 101: return 5 + '0';
        case 110: return 6 + '0';
        case 111: return 7 + '0';
        case 1000: return 8 + '0';
        case 1001: return 9 + '0';
        case 1010: return 'A';
        case 1011: return 'B';
        case 1100: return 'C';
        case 1101: return 'D';
        case 1110: return 'E';
        case 1111: return 'F';
    }
}

void nadji_heksa(int n, char s[MAX_KAR]) {
    int br, i, j;
    unsigned k = 1 << (sizeof (unsigned)*8 - 1);
    for (i = 0; i < 8; i++) {
        br = 0;
        for (j = 0; j<sizeof (int); j++) {
            if (k & n)
                br = br * 10 + 1;
            else
                br = br * 10;
            k >>= 1;
        }
        s[i] = nadji_br(br);
    }
    s[i] = '\0';

}*/

//ZADATAK 15
/*
#include <stdio.h>
#include<stdlib.h>

#define MAX 100

int novi_br(int* niz, int n);

int main() {
    int n, niz[MAX], i;

    printf("Unesi n:\n");
    scanf("%d", &n);

    if (n < 0 || n > 32) {
        printf("-1");
        exit(0);
    }

    printf("Uneti %d brojeva:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    printf("%d", novi_br(niz, n));

    return 0;
}

int novi_br(int* niz, int n) {
    int i, j, x = 0;
    unsigned k = 1;

    for (i = 0; i < n; i++) {
        k <<= i;
        x = x | (niz[i] & k);
        k >>= i;
    }
    return x;
}*/

//ZADATAK 16
/*
#include <stdio.h>
#include<stdlib.h>

#define MAX 32

unsigned novi_br(int* niz, int n, int p);

int main() {
    int x, n, niz[MAX], i;

    printf("Unesi x, n:\n");
    scanf("%d%d", &x, &n);

    if (n < 0 || n > 32) {
        printf("-1");
        exit(0);
    }

    printf("Uneti %d brojeva:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    printf("%u", novi_br(niz, n, x));

    return 0;
}

unsigned novi_br(int* niz, int n, int p) {
    int i;
    unsigned k = 1, x = 0;

    for (i = 0; i < 32; i++) {
        if (i < n) {
            if ((k & niz[i]) == (k & p))
                x |= k;
        } else if (0 == (k & p))
            x |= k;
        k <<= 1;
    }
    return x;
}*/
