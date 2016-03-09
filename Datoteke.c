//Zadaci sa sajta: http://www.prog2-i-smer.matf.bg.ac.rs/vezbe.html
//Cas 1

//ZADATAK 1

    //Pod a
    /*
    #include <stdio.h>
    #include <stdlib.h>

    int main() {

        FILE *f = fopen("/home/luka/Desktop/Vezbanje/ulaz.txt", "r");
        FILE *g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");
        char c;

        if (f == NULL || g == NULL) {
            printf("-1");
            exit(0);
        }

        while (1) {
            c = fgetc(f);
            if (feof(f))
                break;
            fputc(c, g);
        }

        fclose(f);
        fclose(g);
        return 0;
    }*/
    //Pod b
    /*
    #include <stdio.h>
    #include <stdlib.h>
    #define max 21

    int main() {

        FILE *f = fopen("/home/luka/Desktop/Vezbanje/ulaz.txt", "r");
        FILE *g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");
        char linija[max];

        if (f == NULL || g == NULL) {
            printf("-1");
            exit(0);
        }

        while (fgets(linija, max, f) != NULL)
            fputs(linija, g);


        fclose(f);
        fclose(g);
        return 0;
    }*/

//ZADATAK 2
/*
#include <stdio.h>
#include <stdlib.h>
#define max 21

int main() {

    FILE *f = fopen("/home/luka/Desktop/Vezbanje/knjiga.txt", "r");
    int br = 0;

    if (f == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    while (fgetc(f) != EOF)
        if (fgetc(f) == '\n')br++;

    printf("%d", br + 1);
    fclose(f);

    return 0;
}*/

//ZADATAK 3
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

int main() {

    FILE *f, *g;
    char ime1[max], ime2[max],
            ime3[max] = "/home/luka/Desktop/Vezbanje/",
            ime4[max] = "/home/luka/Desktop/Vezbanje/";
    char c;
    scanf("%s%s", ime1, ime2);

    strcat(ime3, ime1);
    strcat(ime4, ime2);

    if ((f = fopen(ime3, "r")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    if ((g = fopen(ime4, "w")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    while ((c = fgetc(f)) != EOF) {
        c = fgetc(f);

        fputc(c, g);
    }
    fclose(f);
    fclose(g);

    return 0;
}*/

//ZADATAK 4
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 100

int main() {

    FILE *f, *g;
    char ime1[max], ime2[max],
            ime3[max] = "/home/luka/Desktop/Vezbanje/",
            ime4[max] = "/home/luka/Desktop/Vezbanje/";
    char c[2], a;

    scanf("%s%s%s", ime1, ime2, c);

    strcat(ime3, ime1);
    strcat(ime4, ime2);

    if ((f = fopen(ime3, "r")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    if ((g = fopen(ime4, "w")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }
    if (c[0] == 'u') {
        while ((a = fgetc(f)) != EOF) {
            if (islower(a))a = toupper(a);
            fputc(a, g);
        }
    } else while ((a = fgetc(f)) != EOF) {
            if (isupper(a))a = tolower(a);
            fputc(a, g);
        }
    fclose(f);
    fclose(g);

    return 0;
}*/

//ZADATAK 5
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max 100
#define max_br 10

int main() {

    FILE *f;
    char ime1[max],
            ime3[max] = "/home/luka/Desktop/Vezbanje/";

    int niz[max_br], i, maxbr, p = 0, cif;
    char c;

    scanf("%s", ime1);
    strcat(ime3, ime1);


    if ((f = fopen(ime3, "r")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    for (i = 0; i < max_br; i++)niz[i] = 0;

    while ((c = fgetc(f)) != EOF)
        if (isdigit(c)) {
            niz[c - '0']++;
            p = 1;
        }

    maxbr = niz[0];
    cif = 0;
    for (i = 1; i < max_br; i++)
        if (niz[i] > maxbr) {
            cif = i;
            maxbr = niz[i];
        }

    if (p == 0)printf("-1");
    else printf("%d", cif);
    fclose(f);

    return 0;
}*/

//ZADATAK 6
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max 100
#define max_br 10

int main() {

    FILE *f;
    char ime1[max],
            ime3[max] = "/home/luka/Desktop/Vezbanje/";

    int k, a = 0, br = 0;
    char c;

    scanf("%d%s", &k, ime1);
    strcat(ime3, ime1);


    if ((f = fopen(ime3, "r")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    while ((c = fgetc(f)) != EOF) {
        if (isdigit(c))
            a++;
        else {
            if (a == k)br++;
            a = 0;
        }
    }

    printf("%d", br);


    fclose(f);

    return 0;
}*/

//ZADATAK 7
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 100

int susedni(int mat[][max], int m, int n, int i, int j);

int main() {

    FILE *f;
    int m, n, i, j, mat[max][max];
    char c;

    if ((f = fopen("/home/luka/Desktop/Vezbanje/matrice.txt", "r")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    fscanf(f, "%d%d", &m, &n);


    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (fscanf(f, "%d", &mat[i][j]) == EOF) {
                printf("Lose uneta matrica.\n");
                exit(-1);
            }


    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (susedni(mat, m, n, i, j))printf("(%d, %d, %d)\n", i, j, mat[i][j]);


    fclose(f);

    return 0;
}

int susedni(int mat[][max], int m, int n, int i, int j) {
    int k, p, s = 0;
    for (k = -1; k < 2; k++)
        for (p = -1; p < 2; p++)
            if (k + i >= 0 && k + i <= m && p + j >= 0 && p + j <= n)
                s += mat[k + i][p + j];
    s -= mat[i][j];
    if (s == mat[i][j])return 1;
    else return 0;
}*/

//ZADATAK 8
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 100

int main() {

    FILE *f, *g;
    char ime1[max], ime2[max],
            ime3[max] = "/home/luka/Desktop/Vezbanje/",
            ime4[max] = "/home/luka/Desktop/Vezbanje/";
    char c;
    scanf("%s%s", ime1, ime2);

    strcat(ime3, ime1);
    strcat(ime4, ime2);

    if ((f = fopen(ime3, "r")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    if ((g = fopen(ime4, "w")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    while ((c = fgetc(f)) != EOF) {
        if (isdigit(c))c = '0';
        else if (isalpha(c))c = '1';
        else c = '2';
        fputc(c, g);
    }
    fclose(f);
    fclose(g);

    return 0;
}*/

//ZADATAK 9
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 100

int main() {

    FILE *f, *g;
    char c;

    if ((f = fopen("/home/luka/Desktop/Vezbanje/plain.txt", "r")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    if ((g = fopen("/home/luka/Desktop/Vezbanje/sifra.txt", "w")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    while ((c = fgetc(f)) != EOF) {
        if (islower(c)) {
            if (c == 'a')c = 'Z';
            else c = toupper(c - 1);
        } else if (isupper(c)) {
            if (c == 'A')c = 'z';
            else c = tolower(c - 1);
        }
        fputc(c, g);
    }


    fclose(f);
    fclose(g);

    return 0;
}*/

//ZADATAK 10
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 100

void rotiraj(char rot[max], int k);

int main() {

    FILE *f, *g;
    int k;
    char ime1[max], ime2[max] = "/home/luka/Desktop/Vezbanje/", rot[max];


    scanf("%s%d", ime1, &k);
    strcat(ime2, ime1);


    if ((f = fopen(ime2, "r")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    if ((g = fopen("/home/luka/Desktop/Vezbanje/rotirano.txt", "w")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    while (fscanf(f, "%s", rot) != EOF) {
        rotiraj(rot, k);
        fputs(rot, g);
        fputc(' ', g);
    }

    fclose(f);
    fclose(g);

    return 0;
}

void rotiraj(char rot[max], int k) {
    int d, j, i;
    char t;
    d = strlen(rot);
    for (j = 0; j < k; j++) {
        t = rot[0];
        for (i = 0; i < d - 1; i++)
            rot[i] = rot[i + 1];
        rot[d - 1] = t;
    }
}*/

//ZADATAK 11 
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 100

int ascii(char rec[max]);

int main() {

    FILE *f, *g;
    int k;
    char c, rec[max];

    if ((f = fopen("/home/luka/Desktop/Vezbanje/ulaz.txt", "r")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    if ((g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    while (fscanf(f, "%s", rec) != EOF)
        if (ascii(rec)) {
            fputs(rec, g);
            fputc(' ', g);
        }


    fclose(f);
    fclose(g);

    return 0;
}

int ascii(char rec[max]) {
    int d, i, br = 0, max1 = 1000;
    d = strlen(rec);
    for (i = 0; i < d; i++)
        br += rec[i];
    printf("%d %s\n", br, rec);
    if (br > max1)return 1;
    else return 0;
}*/

//ZADATAK 12
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 100

int palindrom(char niz[]);

int main() {

    FILE *f, *g;
    int k;
    char c, rec[max];

    if ((f = fopen("/home/luka/Desktop/Vezbanje/razno.txt", "r")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    if ((g = fopen("/home/luka/Desktop/Vezbanje/palindromi.txt", "w")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    while (fscanf(f, "%s", rec) != EOF)
        if (palindrom(rec)) {
            fputs(rec, g);
            fputc(' ', g);
        }

    fclose(f);
    fclose(g);

    return 0;
}

int palindrom(char niz[]) {
    char a[max];
    int i, k = 0, p, br = 0, n;
    n = strlen(niz);
    for (i = 0; i < n; i++) {
        if (isalpha(niz[i])) {
            a[k] = niz[i];
            k++;
        }
    }
    for (i = 0; i < k; i++)
        a[i] = tolower(a[i]);
    p = k - 1;
    for (i = 0; i < k / 2; i++) {
        if (a[i] == a[p]) {
            br++;
            p--;
        } else break;
    }

    if (br == k / 2)return 1;
    else return 0;
}*/

//ZADATAK 13
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max 50

int main() {

    FILE *f, *g;
    int k, n, i = 0, j, m = 0, br;
    char reci[max][max], ime1[max] = "/home/luka/Desktop/Vezbanje/",
            ime2[max], rec[max][max];

    scanf("%s", ime2);
    strcat(ime1, ime2);

    if ((f = fopen(ime1, "r")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    if ((g = fopen("/home/luka/Desktop/Vezbanje/rez.txt", "w")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    fscanf(f, "%d", &n);

    while (fscanf(f, "%s", reci[i]) != EOF)
        i++;

    for (i = 0; i < n; i++)printf("%s ", reci[i]);

    strcpy(rec[0], reci[0]);
    m++;

    for (k = 1; k < n; k++) {
        br = 0;
        for (j = 0; j < m; j++) {
            if ((strcmp(reci[k], rec[j])) != 0)
                br++;
            else break;
        }
        if (br == m) {
            strcpy(rec[m], reci[k]);
            m++;
        }

    }

    for (j = 0; j < m; j++) {
        fputs(rec[j], g);
        fputc(' ', g);
    }

    fclose(f);
    fclose(g);

    return 0;
}*/

//ZADATAK 14
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max 50

int main() {

    FILE *f, *g;
    int k = 0, n, i = 0, j, m = 0, br = 0, d, p = 0;
    char reci[max][max], ime1[max] = "/home/luka/Desktop/Vezbanje/",
            ime2[max], rec[max];

    scanf("%s", ime2);
    strcat(ime1, ime2);

    if ((f = fopen(ime1, "r")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    if ((g = fopen("/home/luka/Desktop/Vezbanje/rez.txt", "w")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    fscanf(f, "%d", &n);

    while (fscanf(f, "%s", reci[i]) != EOF)
        i++;

    for (i = 0; i < n; i++)
        printf("%s ", reci[i]);

    strcpy(rec, reci[0]);
    m = strlen(rec);

    for (i = 1; i < n; i++) {
        d = strlen(reci[i]);
        k = 0;
        br = 0;
        p = 0;
        for (j = 0; j < d; j++) {
            if (reci[i][j] == '_')p = 1;
            if (reci[i][j] == rec[k]) {
                k++;
                br++;
            } else if (br != m) {
                br = 0;
                k = 0;
            }
        }
        if (br == m && p == 1) {
            fputs(reci[i], g);
            fputc(' ', g);
        }
    }

    fclose(f);
    fclose(g);

    return 0;
}*/

//ZADATAK 16
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max_dim 21
#define max 100

typedef struct {
    int imen, broj;
} RAZLOMAK;

int main() {

    FILE *f, *g;
    char prvi_f[max_dim], drugi_g[max_dim], opc[4], c1, c2, c;
    int a, br, i = 0, j;
    float t;
    RAZLOMAK niz[max];

    printf("Uneti dve datoteke i opciju:\n");
    scanf("%s%s%s", prvi_f, drugi_g, opc);

    c1 = opc[1];
    c2 = opc[2];

    if ((f = fopen(prvi_f, "r")) == NULL) {
        printf("greska");
        exit(0);
    }

    if ((g = fopen(drugi_g, "w")) == NULL) {
        printf("greska");
        exit(0);
    }

    fscanf(f, "%d", &br);
    while (fscanf(f, "%d", &niz[i].broj) != EOF) {
        fscanf(f, "%c", &c);
        fscanf(f, "%d", &niz[i].imen);
        i++;
    }

    if (c2 == 0) {
        if (c1 == 'x')
            for (j = 0; j < br; j++)
                fprintf(g, "%d/%d\n", niz[j].imen, niz[j].broj);
        else if (c1 == 'y')
            for (j = 0; j < br; j++)
                fprintf(g, "%.1f\n", (float) niz[j].broj / (float) niz[j].imen);
    } else if (c2 != 0)
        for (j = 0; j < br; j++)
            fprintf(g, "%d/%d %.1f\n", niz[j].imen, niz[j].broj, (float) niz[j].broj / (float) niz[j].imen);

    fclose(f);
    fclose(g);

    return 0;
}*/






