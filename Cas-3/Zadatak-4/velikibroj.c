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
//ako su razlicite duzine vraca 1, ako su iste duzine a razliciti vraca -1 i 0 ako su isti
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
}

