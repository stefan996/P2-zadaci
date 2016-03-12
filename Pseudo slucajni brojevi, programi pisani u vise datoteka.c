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

