//Zadaci sa sajta: http://www.prog2-i-smer.matf.bg.ac.rs/vezbe.html
//Cas 7

//ZADATAK 1

//ZADATAK 2
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MAX_KAR 21

void sortiranje(char niz[][MAX_KAR], int n);

int main() {

    int n, i, k;
    char niz[MAX][MAX_KAR];

    printf("Uneti n:\n");
    scanf("%d", &n);

    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%s", niz[i]);

    sortiranje(niz, n);

    for (i = 0; i < n; i++)
        printf("%s ", niz[i]);

    return 0;
}

void sortiranje(char niz[][MAX_KAR], int n) {
    int i, d1, d, j;
    char pom[MAX_KAR];
    for (j = 0; j < n; j++)
        for (i = 0; i < n - 1; i++) {
            d = strlen(niz[i]);
            d1 = strlen(niz[i + 1]);
            if (d1 < d) {
                strcpy(pom, niz[i]);
                strcpy(niz[i], niz[i + 1]);
                strcpy(niz[i + 1], pom);
            }
        }
}*/

//ZADATAK 3
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MAX_KAR 21

int poredi(const void* a, const void* b);

int main() {

    int n, i, k;
    char niz[MAX][MAX_KAR];

    printf("Uneti n:\n");
    scanf("%d", &n);

    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%s", niz[i]);

    qsort(niz, n, sizeof (char)*MAX_KAR, poredi);

    for (i = 0; i < n; i++)
        printf("%s ", niz[i]);

    return 0;
}

int poredi(const void* a, const void* b) {
    return strlen((char*) a) - strlen((char*) b);
}*/

//ZADATAK 4
/*  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MAX_KAR 21

void sortiranje(char niz[][MAX_KAR], int n);

int main() {

    int n, i, k;
    char niz[MAX][MAX_KAR];

    printf("Uneti n:\n");
    scanf("%d", &n);

    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%s", niz[i]);

    sortiranje(niz, n);

    for (i = 0; i < n; i++)
        printf("%s ", niz[i]);

    return 0;
}

void sortiranje(char niz[][MAX_KAR], int n) {
    int i, d1, d, j;
    char pom[MAX_KAR];
    for (j = 0; j < n; j++)
        for (i = 0; i < n - 1; i++) {
            if (strcmp(niz[i], niz[i + 1]) > 0) {
                strcpy(pom, niz[i]);
                strcpy(niz[i], niz[i + 1]);
                strcpy(niz[i + 1], pom);
            }
        }
}*/

//ZADATAK 5
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MAX_KAR 21

int poredi(const void* a, const void* b);

int main() {

    int n, i, k;
    char niz[MAX][MAX_KAR];

    printf("Uneti n:\n");
    scanf("%d", &n);

    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%s", niz[i]);

    qsort(niz, n, sizeof (char)*MAX_KAR, poredi);

    for (i = 0; i < n; i++)
        printf("%s ", niz[i]);

    return 0;
}

int poredi(const void* a, const void* b) {
    return strcmp((char*) a, (char*) b);
}*/

//ZADATAK 6
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

void insertion_sort(int niz[MAX], int n);
void umetni(int niz[MAX], int k);
int bin_pretraga(int niz[MAX], int p, int l, int d);

int main() {

    int n, i, k, niz[MAX], x;

    printf("Uneti n i x:\n");
    scanf("%d%d", &n, &x);

    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    insertion_sort(niz, n);

    printf("Sortiran niz:");
    for (i = 0; i < n; i++)
        printf("%d ", niz[i]);

    for (i = 0; i < n; i++) {
        k = bin_pretraga(niz, x - niz[i], 0, n);
        if (k >= 0) {
            printf("\nTo su clanovi %d i %d!", niz[k], niz[i]);
            return 0;
        } else {
            printf("\nNe postoji takav clan!");
            return 0;
        }
    }
    return 0;
}

void insertion_sort(int niz[MAX], int n) {
    int i;
    for (i = 1; i < n; i++)
        umetni(niz, i);
}

void umetni(int niz[MAX], int k) {
    int i, x, j;
    x = niz[k];
    for (i = 0; i < k; i++)
        if (x < niz[i]) {
            for (j = k; j > i; j--)
                niz[j] = niz[j - 1];
            niz[i] = x;
            break;
        }
}

int bin_pretraga(int niz[MAX], int p, int l, int d) {
    int k;
    if (l > d)
        return -1;
    else {
        k = (l + d) / 2;
        if (niz[k] > p)
            return bin_pretraga(niz, p, l, k - 1);
        else if (niz[k] < p)
            return bin_pretraga(niz, p, k + 1, d);
        else return k;
    }
}*/

//ZADATAK 7
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MAX_KAR 21

typedef struct {
    float oc;
    char ime[MAX_KAR], prez[MAX_KAR];
} STUDENT;

void insertion_sort(STUDENT niz[MAX], int n);
void umetni(STUDENT niz[MAX], int k);

int main(int argc, char** argv) {

    int i = 0, j;
    STUDENT niz[MAX];

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    FILE *f = fopen(argv[1], "r");

    if (f == NULL) {
        printf("Greska!");
        exit(0);
    }

    while (fscanf(f, "%s%s%f", niz[i].ime, niz[i].prez, &niz[i].oc) != EOF)
        i++;


    insertion_sort(niz, i);

    for (j = 0; j < i; j++)
        printf("%s %s %f\n", niz[j].ime, niz[j].prez, niz[j].oc);

    return 0;
}

void insertion_sort(STUDENT niz[MAX], int n) {
    int i;
    for (i = 1; i < n; i++)
        umetni(niz, i);
}

void umetni(STUDENT niz[MAX], int k) {
    int i, j;
    STUDENT x;
    x = niz[k];
    for (i = 0; i < k; i++)
        if (x.oc < niz[i].oc) {
            for (j = k; j > i; j--)
                niz[j] = niz[j - 1];
            niz[i] = x;
            break;
        }
}*/

//ZADATAK 8
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MAX_KAR 21

typedef struct {
    float oc;
    char ime[MAX_KAR], prez[MAX_KAR];
} STUDENT;

int poredi(const void* a, const void* b);

int main(int argc, char** argv) {

    int i = 0, j;
    STUDENT niz[MAX];

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    FILE *f = fopen(argv[1], "r");

    if (f == NULL) {
        printf("Greska!");
        exit(0);
    }

    while (fscanf(f, "%s%s%f", niz[i].ime, niz[i].prez, &niz[i].oc) != EOF)
        i++;


    qsort(niz, i, sizeof (STUDENT), poredi);

    for (j = 0; j < i; j++)
        printf("%s %s %f\n", niz[j].ime, niz[j].prez, niz[j].oc);

    return 0;
}

int poredi(const void* a, const void* b) {
    STUDENT* n = (STUDENT*) a;
    STUDENT* m = (STUDENT*) b;

    return n->oc - m->oc;
}*/

//ZADATAK 9
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

void insertion_sort(int niz[MAX], int n);
void umetni(int niz[MAX], int k);
int prebroj(int niz[MAX], int n);

int main() {
    int n, i, k, niz[MAX];

    printf("Uneti n:\n");
    scanf("%d", &n);

    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    insertion_sort(niz, n);

    printf("Sortiran niz:");
    for (i = 0; i < n; i++)
        printf("%d ", niz[i]);

    printf("\n%d", prebroj(niz, n));

    return 0;
}

void insertion_sort(int niz[MAX], int n) {
    int i;
    for (i = 1; i < n; i++)
        umetni(niz, i);
}

void umetni(int niz[MAX], int k) {
    int i, x, j;
    x = niz[k];
    for (i = 0; i < k; i++)
        if (x < niz[i]) {
            for (j = k; j > i; j--)
                niz[j] = niz[j - 1];
            niz[i] = x;
            break;
        }
}

int prebroj(int niz[MAX], int n) {
    int i, br = 1, br_max = 1, max;
    max = niz[0];
    for (i = 1; i < n; i++) {
        if (niz[i] != niz[i - 1]) {
            if (br > br_max) {
                br_max = br;
                max = niz[i - 1];
            }
            br = 1;
        } else
            br++;
    }

    return max;
}*/

//ZADATAK 10
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

void insertion_sort(int niz[MAX], int n);
void umetni(int niz[MAX], int k);
int rastojanje(int niz[MAX], int n, int *l, int *d);

int main() {
    int n, i, l, d, niz[MAX], k;

    printf("Uneti n:\n");
    scanf("%d", &n);

    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    insertion_sort(niz, n);

    printf("Sortiran niz:");
    for (i = 0; i < n; i++)
        printf("%d ", niz[i]);

    k = rastojanje(niz, n, &l, &d);

    printf("\nNa najmanjem rastojanju %d su brojevi %d i %d!", k, niz[l], niz[d]);

    return 0;
}

void insertion_sort(int niz[MAX], int n) {
    int i;
    for (i = 1; i < n; i++)
        umetni(niz, i);
}

void umetni(int niz[MAX], int k) {
    int i, x, j;
    x = niz[k];
    for (i = 0; i < k; i++)
        if (x < niz[i]) {
            for (j = k; j > i; j--)
                niz[j] = niz[j - 1];
            niz[i] = x;
            break;
        }
}

int rastojanje(int niz[MAX], int n, int *l, int *d) {
    int i, r;
    r = niz[1] - niz[0];
    *d = 1;
    *l = 0;
    for (i = 2; i < n; i++)
        if ((niz[i] - niz[i - 1]) < r) {
            r = niz[i] - niz[i - 1];
            *l = i - 1;
            *d = i;
        }
    return r;
}*/

//ZADATAK 11
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct {
    int im, br;
} RAZLOMAK;

int poredi(const void* a, const void* b);

int main(int argc, char** argv) {

    int i = 0, j;
    char c;
    RAZLOMAK niz[MAX];

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    FILE *f = fopen(argv[1], "r");

    if (f == NULL) {
        printf("Greska!");
        exit(0);
    }
    
    //zamisljeno je da se u datoteci unose razlomci u obliku 3/4...
    while (fscanf(f, "%d%c%d", &niz[i].br, &c, &niz[i].im) != EOF)
        i++;


    qsort(niz, i, sizeof (RAZLOMAK), poredi);

    for (j = 0; j < i; j++)
        printf("%d/%d\n", niz[j].br, niz[j].im);

    return 0;
}

int poredi(const void* a, const void* b) {

    RAZLOMAK* n = (RAZLOMAK*) a;
    RAZLOMAK* m = (RAZLOMAK*) b;

    return (((n->br)*(m->im)-(m->br)*(n->im))*((n->im)*(m->im)));
}*/

//ZADATAK 12
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MAX_KAR 21
#define MAX_IDE 3

typedef struct {
    char ime[MAX_KAR], id_ime[MAX_IDE];
    int id_br;
} STUDENT;

int poredi(const void* a, const void* b);
int poredi1(const void* a, const void* b);
int poredi2(const void* a, const void* b);
int poredi3(const void* a, const void* b);

int main(int argc, char** argv) {

    int i = 0, j;
    STUDENT niz[MAX], x;
    STUDENT *k;

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    FILE *f = fopen(argv[1], "r");

    if (f == NULL) {
        printf("Greska!");
        exit(0);
    }

    while (fscanf(f, "%s %c%c%d", niz[i].ime, &niz[i].id_ime[0], &niz[i].id_ime[1], &niz[i].id_br) != EOF)
        i++;

    printf("Uneti studenta:\n");
    scanf("%s %c%c%d", x.ime, &x.id_ime[0], &x.id_ime[1], &x.id_br);
    printf("\n");

    //sortira po broju
    qsort(niz, i, sizeof (STUDENT), poredi);

    //sortira po slovima
    //qsort(niz, i, sizeof (STUDENT), poredi1);

    //trazi studenta po broju u identifikaciji
    k = (STUDENT*) bsearch(&x.id_br, niz, i, sizeof (STUDENT), poredi2);

    //trazi studenta po slovima u identifikaciji
    //k = (STUDENT*) bsearch(x.id_ime, niz, i, sizeof (STUDENT), poredi3);

    for (j = 0; j < i - 1; j++)
        printf("%s %s%d\n", niz[j].ime, niz[j].id_ime, niz[j].id_br);
    printf("\n");

    //ispisuje nadjenog studenta
    if (k != NULL)
        printf("%s %s%d\n", k->ime, k->id_ime, k->id_br);
    else
        printf("Nema takvog!\n");
    return 0;
}

//sortira po brojevima

int poredi(const void* a, const void* b) {

    STUDENT* n = (STUDENT*) a;
    STUDENT* m = (STUDENT*) b;

    return n->id_br - m->id_br;
}

//sortira po slovima 

int poredi1(const void* a, const void* b) {

    STUDENT* n = (STUDENT*) a;
    STUDENT* m = (STUDENT*) b;

    return strcmp((n->id_ime), (m->id_ime));
}

//pretrazuje studenta po broju

int poredi2(const void* a, const void* b) {

    int* n = (int*) a;
    STUDENT* m = (STUDENT*) b;

    return *n - m->id_br;
}

//pretrazuje studenta po slovu

int poredi3(const void* a, const void* b) {

    char* n = (char*) a;
    STUDENT* m = (STUDENT*) b;

    return strcmp(n, m->id_ime);
}*/
