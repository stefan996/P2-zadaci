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

//ZADATAK 8 - nismo radili alokaciju

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
/*
#include<stdio.h>

int prost1(int n, int i) {
    if (i == 1)
        return 1;

    else {
        if (n % i == 0)
            return 0;
        else
            return prost1(n, i - 1);
    }
}

int prost(int n) {

    return prost1(n, n / 2);
}

int main() {

    int n, id;
    printf("Unesite broj:\n");
    scanf("%d", &n);

    id = prost(n);

    if (id)
        printf("Broj je prost!\n");
    else
        printf("Broj nije prost!\n");

    return 0;
}*/

//ZADATAK 15
/*
#include<stdio.h>

void suma(int n, int *s);

int main() {
    int n, s = 0;
    printf("Unesite broj:\n");
    scanf("%d", &n);
    suma(n, &s);
    printf("%d", s);
    return 0;
}

void suma(int n, int *s) {
    static int a = n;
    if (n == 1)
        *s += 1;
    else {
        suma(n - 1, s);
        if (a % n == 0) *s += n;
    }
}*/

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
/*
#include<stdio.h>

int bin_koef(int n, int k);

int main() {
    int n, k;
    printf("Unesite broj n i k:\n");
    scanf("%d%d", &n, &k);
    if (k < 0)printf("0\n");
    printf("%d", bin_koef(n, k));
    return 0;
}

int bin_koef(int n, int k) {
    if (k == 1)
        return n;
    else
        return (n + 1 - k) * bin_koef(n, k - 1) / k;
}*/

//ZADATAK 18 XXX ne znam sta mi traze

//ZADATAK 19 - nismo radili repnu

//ZADATAK 20
/*
#include<stdio.h>
#define max 100

void niz(int n, int t[max]);

int main() {
    int n, i, t[max], k = 1;
    printf("Unesite broj n:\n");
    scanf("%d", &n);
    printf("Unesite niz:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &t[i]);
    niz(n, t);
    for (i = 0; i < n; i++)
        printf("%d ", t[i]);
    return 0;
}

void niz(int n, int t[max]) {
    if (n == 1)
        t[0] += 1;
    else {
        niz(n - 1, t);
        t[n - 1] += n;
    }
}*/

//ZADATAK 21
/*
#include<stdio.h>

int nzd(int n, int m);

int main() {
    int n, m;
    printf("Unesite broj n i m:\n");
    scanf("%d%d", &n, &m);
    printf("NZD je:%d\n", nzd(n, m));
    return 0;
}

int nzd(int n, int m) {
    if (n % m == 0)
        return m;
    else
        nzd(m, n % m);
}*/

//ZADATAK 22
/*
#include<stdio.h>

int fib(int n);

int main() {
    int n, m;
    printf("Unesite broj n:\n");
    scanf("%d", &n);
    if (n == 0)printf("0\n");
    printf("%d. clan Fibonacijevog niza je: %d\n", n, fib(n));
    return 0;
}

int fib(int n) {
    if (n == 2 || n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}*/

//ZADATAK 23
/*
#include<stdio.h>
#include<math.h>

void podbroj(int n, int d);

int main() {
    int n, d;
    printf("Unesite broj n i d:\n");
    scanf("%d%d", &n, &d);
    podbroj(n, d);
    return 0;
}

void podbroj(int n, int d) {
    if (n < pow(10, d))
        printf("%d ", n);
    else {
        printf("%d ", n % (int) pow(10, d));
        n /= 10;
        podbroj(n, d);
    }
}*/

//ZADATAK 24
/*
#include<stdio.h>
#define MAX 100

int uzastopni(int n, int* niz, int a, int b, int c);

int main() {
    int n, i, a, b, c, niz[MAX];
    
    printf("Unesite broj n:\n");
    scanf("%d", &n);
    
    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);
    
    printf("Unesite tri broja:\n");
    scanf("%d%d%d", &a, &b, &c);
    
    if (uzastopni(n, niz, a, b, c))
        printf("Jesu!");
    else
        printf("Nisu!");
    
    return 0;
}

int uzastopni(int n, int* niz, int a, int b, int c) {
    if (n < 3) return 0;
    else if (niz[n - 1] == c && niz[n - 2] == b && niz[n - 3] == a)
        return 1;
    else
        return uzastopni(n - 1, niz, a, b, c);
}*/

//ZADATAK 25
/*
#include<stdio.h>

int izbaci(int n);

int main() {
    int n;
    printf("Unesite broj n:\n");
    scanf("%d", &n);
    printf("%d\n", izbaci(n));
    return 0;
}

int izbaci(int n) {
    if (n < 100)
        return n % 10;
    else
        return izbaci(n / 100)*10 + n % 10;
}*/

//ZADATAK 26
/*
#include<stdio.h>
#include<stdlib.h>

int f(int a, int b);

int main() {
    int a, b;
    FILE *g = fopen("rez.txt", "w");

    if (g == NULL) {
        printf("Greska!");
        exit(0);
    }

    printf("Unesite brojeve a i b:\n");
    scanf("%d%d", &a, &b);

    fprintf(g, "%d", f(a, b));
    fclose(g);

    return 0;
}

int f(int a, int b) {
    if (a == 0 && b == 0)
        return 1;
    else if (a < 0 && b >= 0)
        return -f(-a, b);
    else if (a >= 0 && b < 0)
        return -f(a, -b);
    else if (a < 0 && b < 0)
        return f(-a, -b);
    else
        return f(b, a - 1) + 2;
}*/
