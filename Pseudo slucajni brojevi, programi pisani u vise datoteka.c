//Zadaci sa sajta: http://www.prog2-i-smer.matf.bg.ac.rs/vezbe.html
//Cas 3

//ZADATAK 1
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

double frand();

int main() {
    int i = 0;

    while (i <= 30) {
        printf("%lf\n", frand());
        i++;
    }

    return 0;
}

double frand() {
    return (double) rand() / RAND_MAX;
}*/

//ZADATAK 2
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DUZ 200

double slucajanRealan(int a, int b);
int slucajanCeo(int a, int b);

int main(int argc, char** argv) {

    int n, a, b, A[MAX_DUZ], i;
    double B[MAX_DUZ];

    if (argc != 4) {
        printf("greska");
        exit(0);
    }

    n = atoi(argv[1]);
    a = atoi(argv[2]);
    b = atoi(argv[3]);

    if (b < a || n > MAX_DUZ) {
        printf("greska");
        exit(0);
    }

    for (i = 0; i < n; i++) {
        A[i] = slucajanCeo(a, b);
        B[i] = slucajanRealan(a, b);
    }

    for (i = 0; i < n; i++)
        printf("A:%d B:%.1lf\n", A[i], B[i]);

    return 0;
}

double slucajanRealan(int a, int b) {
    return ((double) rand() / RAND_MAX)*(b - a) + a;
}

int slucajanCeo(int a, int b) {
    return rand() % (b - a + 1) + a;
}*/

//ZADATAK 3

//polinom.c
/*
#include<stdio.h>
#include"polinom.h"
#define MAX_KOE 100

void unos(int a[MAX_KOE], int* n) {
    int i;
    printf("Uneti stepen polinoma:\n");
    scanf("%d", &(*n));
    for (i = 0; i <= (*n); i++)
        scanf("%d", &a[i]);
}

void ispis_polinoma(int a[MAX_KOE], int n) {
    int i, b = 0, p = 0;
    for (i = 0; i <= n; i++)
        if (a[i] != 0) {
            p = 1;
            if (i == 0) {
                printf("%d", a[i]);
                b++;
            } else if (a[i] > 0) {
                if (b == 0) {
                    if (i == 1) {
                        if (a[i] == 1)
                            printf("x");
                        else
                            printf("%d*x", a[i]);
                    } else {
                        if (a[i] == 1)
                            printf("x^%d", i);
                        else
                            printf("%d*x^%d", a[i], i);
                    }
                    b++;
                } else {
                    if (i == 1) {
                        if (a[i] == 1)
                            printf("+x");
                        else
                            printf("+%d*x", a[i]);
                    } else {
                        if (a[i] == 1)
                            printf("+x^%d", i);
                        else
                            printf("+%d*x^%d", a[i], i);
                    }
                }
            } else if (a[i] < 0) {
                if (i == 1) {
                    if (a[i] == -1)
                        printf("-x");
                    else
                        printf("%d*x", a[i]);
                } else {
                    if (a[i] == -1)
                        printf("-x^%d", i);
                    else
                        printf("%d*x^%d", a[i], i);
                }
                b++;
            }
        }
    if (p != 1)printf("0");
}

int suma_polinoma(int a[MAX_KOE], int n, int b[MAX_KOE], int m, int c[MAX_KOE]) {
    int i, nova_duz;

    if (m > n)nova_duz = m;
    else nova_duz = n;

    for (i = 0; i < nova_duz; i++)
        if (i <= n && i <= m)
            c[i] = a[i] + b[i];
    for (; i <= n; i++)
        c[i] = a[i];
    for (; i <= m; i++)
        c[i] = b[i];
    return nova_duz;
}

void mnoz_skalarom(int a[MAX_KOE], int n, int c) {
    int i;
    for (i = 0; i <= n; i++)
        a[i] = a[i] * c;
}

int vr_poly(int a[MAX_KOE], int n, int x) {
    int s = 0, i;
    for (i = n; i >= 0; i--)
        s = s * x + a[i];
    return s;
}

int mul_poly(int a[MAX_KOE], int n, int b[MAX_KOE], int m, int c[MAX_KOE]) {
    int i, j;
    for (i = 0; i <= (n + m); i++)c[i] = 0;
    for (i = 0; i <= n; i++)
        for (j = 0; j <= m; j++)
            c[i + j] += a[i] * b[j];
    return (n + m);
}*/

//polinom.h
/*
#define MAX_KOE 100

void unos(int a[MAX_KOE], int* n); 
void ispis_polinoma(int a[MAX_KOE], int n);
int suma_polinoma(int a[MAX_KOE], int n, int b[MAX_KOE], int m, int c[MAX_KOE]);
void mnoz_skalarom(int a[MAX_KOE], int n, int c);
int vr_poly(int a[MAX_KOE], int n, int x);
int mul_poly(int a[MAX_KOE], int n, int b[MAX_KOE], int m, int c[MAX_KOE]);*/

//glavni.c
/*
#include<stdio.h>
#include"polinom.h"

#define MAX_KOE 100

int main(){
    
    int i,n,m,k,x,u,d,a[MAX_KOE],b[MAX_KOE],c[MAX_KOE];
    
    unos(a,&n);
    //printf("Uneti skalar:\n");
    //scanf("%d",&d);
    unos(b,&m);
    //k=suma_polinoma(a,n,b,m,c);
    //mnoz_skalarom(a,n,d);
    //printf("Uneti vrednost x:\n");
    //scanf("%d",&x);
    //printf("%d",vr_poly(a,n,x));
    u=mul_poly(a,n,b,m,c);
    ispis_polinoma(c,u);
    
    return 0;
}*/


//ZADATAK 4

//velikibroj.c
/*
#include<stdio.h>
#include<ctype.h>
#include"velikibroj.h"

VelikiBroj ucitaj_broj(FILE* f) {
    VelikiBroj a;
    char c;
    int i = 0;
    while ((c = fgetc(f)) != '\n') {
        if (isdigit(c))
            a.niz[i] = c - '0';
        else
            break;
        i++;
    }
    a.duz = i;
    return a;
}

void ispis(VelikiBroj b, FILE* g) {
    int i;
    for (i = 0; i < b.duz; i++)
        fprintf(g, "%d", b.niz[i]);
}

int poredi(VelikiBroj a, VelikiBroj b) {
    int i;
    if (a.duz > b.duz || a.duz < b.duz) return 1;
    for (i = 0; i < a.duz; i++)
        if (a.niz[i] != b.niz[i]) return -1;
    return 0;
}

VelikiBroj saberi(VelikiBroj a, VelikiBroj b) {
    VelikiBroj c;
    int p = 0, j, i, br, min, t, k;
    if (a.duz > b.duz) {
        t = 0;
        c.duz = a.duz;
    } else {
        t = 1;
        c.duz = b.duz;
    }
    for (i = a.duz, j = b.duz, k = c.duz; i >= 0 && j >= 0; i--, j--, k--) {
        br = a.niz[i] + b.niz[j] + p;
        c.niz[k] = br % 10;
        p = br / 10;
    }
    for (; k >= 0; k--) {
        if (t == 0) {
            br = p + a.niz[k];
            c.niz[k] = br % 10;
        } else if (t == 1) {
            br = p + b.niz[k];
            c.niz[k] = br % 10;
        }
        p = br / 10;
    }
    if (p != 0) {
        c.duz++;
        j = c.niz[c.duz - 1];
        for (i = c.duz - 1; i > 0; i--)
            c.niz[i] = c.niz[i - 1];
        c.niz[c.duz] = j;
        c.niz[0] = p;
    }
    return c;
}

VelikiBroj mnozi_skalarom(VelikiBroj a, int x) {
    VelikiBroj c;
    int i, p = 0, br, j;
    c.duz = a.duz;
    for (i = c.duz; i >= 0; i--) {
        br = a.niz[i] * x + p;
        c.niz[i] = br % 10;
        p = br / 10;
    }
    if (p != 0) {
        c.duz++;
        j = c.niz[c.duz - 1];
        for (i = c.duz - 1; i > 0; i--)
            c.niz[i] = c.niz[i - 1];
        c.niz[c.duz] = j;
        c.niz[0] = p;
    }
    return c;
}

VelikiBroj mnozi_dva(VelikiBroj a, VelikiBroj b) {
    VelikiBroj c, d;
    int i, j, k, p = 1;
    for (i = b.duz - 1; i >= 0; i--) {
        c = mnozi_skalarom(a, b.niz[i]);
        if (i == b.duz - 1) {
            d.duz = c.duz;
            d = saberi(c, d);
        } else {
            c.niz[c.duz] = 0;
            for (j = 0; j < p; j++)
                c.niz[++c.duz] = 0;
            p++;
            d = saberi(c, d);
        }
    }
    return d;
}*/

//velikibroj.h
/*
#define MAX_DUZ 1000

typedef struct {
    int duz;
    int niz[MAX_DUZ];
} VelikiBroj;

VelikiBroj ucitaj_broj(FILE* f);
void ispis(VelikiBroj b, FILE* g);
int poredi(VelikiBroj a, VelikiBroj b);
VelikiBroj saberi(VelikiBroj a, VelikiBroj b);
VelikiBroj mnozi_skalarom(VelikiBroj a, int x);
VelikiBroj mnozi_dva(VelikiBroj a, VelikiBroj b);*/

//glavni.c
/*
#include<stdio.h>
#include<stdlib.h>
#include"velikibroj.h"

int main(int argc, char** argv) {
    FILE *f = fopen(argv[1], "r"), *g = fopen("velikibroj.txt", "w");
    VelikiBroj a, b, c;
    int x;

    if (f == NULL || g == NULL) {
        printf("greska");
        exit(0);
    }

    if (argc != 2) {
        printf("greska");
        exit(0);
    }

    a = ucitaj_broj(f);
    b = ucitaj_broj(f);
    //     ispis(a,g);
    //     fprintf(g,"\n");
    //     ispis(b,g);
    //     printf("%d",poredi(a,b));
    //     c=saberi(a,b);
    //     printf("Unesi skalar x:\n");
    //     scanf("%d",&x);
    //     c=mnozi_skalarom(a,x);
    c = mnozi_dva(a, b);
    ispis(c, g);
}*/


