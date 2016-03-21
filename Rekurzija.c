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

    int cifra;
    if (n < 16)
        printf("%d", n);
    else {
        heksa(n / 16);
        cifra = n % 16;
        if (cifra < 10)
            printf("%d", cifra);
        else
            printf("%c", cifra + 'A' - 10);
    }

}

int main() {

    int n;

    printf("Unesi broj\n");
    scanf("%d", &n);

    printf("Heksadekadni zapis broja je: ");
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
#define max 100

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

    printf("Obrnuti brojevi su:\n");
    printf("%d", parna_c(n));

    printf("\n");

    return 0;

}*/

//ZADATAK 11
/*
#include<stdio.h>

int parna_c(int n) {

    int br = 0;

    if (n < 10) {
        if (n % 2 != 0) return n * 10;
        else return n;
    } else {
        br = parna_c(n / 10);
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
    printf("%d", parna_c(n));

    printf("\n");

    return 0;
}*/
