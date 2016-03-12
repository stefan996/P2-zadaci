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
}

