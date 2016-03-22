//Zadaci sa sajta: http://www.prog2-i-smer.matf.bg.ac.rs/vezbe.html
//Cas 4

//ZADATAK 1
//Pod a
/*
#include<stdio.h>

void ispis(int n) {

    if (n == 1)printf("1 ");
    else {
        ispis(n - 1);
        printf("%d ", n);
    }
}

int main() {

    ispis(5);

    return 0;
}*/
//Pod b
/*
#include<stdio.h>

void ispis(int n) {

    if (n == 1)printf("1 ");
    else {
        printf("%d ", n);
        ispis(n - 1);
    }
}

int main() {

    ispis(5);

    return 0;
}*/

//ZADATAK 2
/*
#include<stdio.h>

void heksa(int n) {

    int c;
    if (n < 16)
        printf("%d", n);
    else {
        heksa(n / 16);
        c = n % 16;
        if (c < 10)
            printf("%d", c);
        else
            printf("%c", c + 'A' - 10);
    }

}

int main() {

    int n;

    printf("Unesi broj\n");
    scanf("%d", &n);

    printf("Heksadekadni broj je: ");
    heksa(n);
    printf("\n");

    return 0;

}*/

//ZADATAK 3
/*
#include<stdio.h>

int parni(int n) {

    if (n < 10)
        if (n % 2 == 0) return 1;
        else return 0;
    else {

        if ((n % 10) % 2 == 0)
            return 1 + parni(n / 10);
        else
            return parni(n / 10);
    }
}

int main() {

    int n;

    printf("Unesi broj\n");
    scanf("%d", &n);

    printf("Broj parnih je: %d ", parni(n));

    printf("\n");

    return 0;

}*/

//ZADATAK 4
/*
#include<stdio.h>

int max_c(int n) {
    int max = 0, br;

    if (n < 10)
        if (n > max) return n;
        else return max;
    else {
        br = max_c(n / 10);
        if (br > (n % 10))
            return br;
        else return n % 10;
    }
}

int main() {

    int n;

    printf("Unesi broj\n");
    scanf("%d", &n);

    printf("Max cifra je: %d ", max_c(n));

    printf("\n");

    return 0;

}*/

//ZADATAK 5
/*
#include<stdio.h>

int uklanja(int n, int cifra) {

    int br = 0;

    if (n < 10) {
        if (n == cifra) return 0;
        else return n;
    } else {
        br = uklanja(n / 10, cifra);
        if (n % 10 == cifra)
            return br;
        else return br * 10 + n % 10;
    }
}

int main() {

    int n, cifra;

    printf("Unesi broj i cifru:\n");
    scanf("%d%d", &n, &cifra);

    printf("Novi broj je: %d ", uklanja(n, cifra));

    printf("\n");

    return 0;

}*/

//ZADATAK 6
/*
#include<stdio.h>
#define max 100

int niz_c(int n, int niz[max]) {
    int i = 0;
    if (n < 10) {
        niz[i] = n;
        return ++i;
    } else {
        i = niz_c(n / 10, niz);
        niz[i] = n % 10;
        return ++i;
    }
}

int main() {

    int n, niz[max], i, d;

    printf("Unesi broj:\n");
    scanf("%d", &n);
    d = niz_c(n, niz);
    printf("Niz brojeva je:\n");

    for (i = 0; i < d; i++)printf("%d ", niz[i]);

    printf("\n");

    return 0;

}*/

//ZADATAK 7
/*
#include<stdio.h>

int obrnuto(int n, int *stepen) {
    int k;

    if (n < 10) {
        return n;
    } else {
        k = obrnuto(n / 10, stepen);
        (*stepen) *= 10;
        return (n % 10)*(*stepen) + k;
    }
}

int main() {

    int n, stepen = 1;

    printf("Unesi broj:\n");
    scanf("%d", &n);

    printf("Obrnuti brojevi su:\n");
    printf("%d", obrnuto(n, &stepen));

    printf("\n");

    return 0;

}*/

//ZADATAK 8

//ZADATAK 9
/*
#include<stdio.h>
#define max 100

int palindrom(int niz[max], int *k, int n);

int main() {

    int i, n, k, niz[max];

    printf("Unesi n:\n");
    scanf("%d", &n);

    k = n - 1;

    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    if (palindrom(niz, &k, n - 1))
        printf("Jeste!");
    else
        printf("Nije!");
    printf("\n");

    return 0;

}

int palindrom(int niz[max], int *k, int n) {

    if (n == 0) {
        if (niz[*k] == niz[n]) {
            (*k)--;
            return 1;
        } else
            return 0;
    } else {
        palindrom(niz, k, n - 1);
        if (niz[*k] == niz[n]) {
            (*k)--;
            return 1;
        } else
            return 0;
    }
}*/

//ZADATAK 10
/*
#include<stdio.h>

int parna_c(int n) {

    int br = 0;

    if (n < 10) {
        if (n % 2 == 0) return 0;
        else return n;
    } else {
        br = parna_c(n / 10);
        if ((n % 10) % 2 == 0)
            return br;
        else return br * 10 + n % 10;
    }
}

int main() {

    int n;

    printf("Unesi broj:\n");
    scanf("%d", &n);

    printf("Novi broj je:\n");
    printf("%d", parna_c(n));

    printf("\n");

    return 0;

}*/

//ZADATAK 11
/*
#include<stdio.h>

int neparna_c(int n) {

    int br = 0;

    if (n < 10) {
        if (n % 2 != 0) return n * 10;
        else return n;
    } else {
        br = neparna_c(n / 10);
        if ((n % 10) % 2 != 0)
            return (br * 10 + n % 10) * 10;
        else
            return br * 10 + n % 10;
    }
}

int main() {

    int n;

    printf("Unesi broj:\n");
    scanf("%d", &n);

    printf("Novi broj je:\n");
    printf("%d", neparna_c(n));

    printf("\n");

    return 0;
}*/

//ZADATAK 12
/*
#include<stdio.h>
#define MAX 100

int max_br(int niz[MAX], int n);

int main() {

    int i, n, niz[MAX];

    printf("Unesi n:\n");
    scanf("%d", &n);

    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    printf("Max je: %d", max_br(niz, n - 1));

    printf("\n");

    return 0;

}

int max_br(int niz[MAX], int n) {
    int max;

    if (n == 0)
        max = niz[0];
    else {
        max = max_br(niz, n - 1);
        if (niz[n] > max)max = niz[n];
    }
    return max;
}*/

//ZADATAK 13
/*
#include<stdio.h>
#define MAX 100

int skalar_proiz(int niz1[MAX], int niz2[MAX], int n);

int main() {

    int i, n, niz1[MAX], niz2[MAX];

    printf("Unesi n:\n");
    scanf("%d", &n);

    printf("Uneti niz1:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz1[i]);

    printf("Uneti niz2:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz2[i]);

    printf("Skalarni proizvod je: %d", skalar_proiz(niz1, niz2, n - 1));

    printf("\n");

    return 0;

}

int skalar_proiz(int niz1[MAX], int niz2[MAX], int n) {

    if (n == 0)
        return niz1[n] * niz2[n];
    else
        return niz1[n] * niz2[n] + skalar_proiz(niz1, niz2, n - 1);
}*/

//ZADATAK 14
//ZADATAK 15

//ZADATAK 16
/*
#include<stdio.h>
#define MAX 100

int crtanje(int n, int raz);

int main() {

    int n;

    printf("Unesi n:\n");
    scanf("%d", &n);

    crtanje(n, 0);

    printf("\n");

    return 0;

}

int crtanje(int n, int raz) {
    int i;

    if (n == 1) {
        for (i = 0; i < raz; i++)printf(" ");
        printf("+");
    } else {
        crtanje(n - 1, raz + 1);
        printf("\n");
        for (i = 0; i < raz; i++)printf(" ");
        for (i = 0; i < n; i++)printf("+");
    }
}*/

//ZADATAK 17
