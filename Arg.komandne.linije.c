//Zadaci sa sajta: http://www.prog2-i-smer.matf.bg.ac.rs/vezbe.html
//Cas 2

//ZADATAK 1
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 50

int main(int argc, char** argv) {

    int i;

    printf("%d\n", argc);

    for (i = 0; i < argc; i++)
        printf("%d. %s\n", i + 1, argv[i]);

    return 0;
}*/

//ZADATAK 2
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 200

int main(int argc, char** argv) {

    int i, a, b, A[max];
    if (argc != 3) {
        printf("greska");
        exit(0);
    }
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    if (a > b || b - a > max) {
        printf("greska");
        exit(0);
    }
    for (i = 0; i <= b - a; i++) {
        A[i] = a + i;
        printf("%d ", A[i]);
    }

    return 0;
}*/

//ZADATAK 3
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 200

int main(int argc, char** argv) {

    int i, j;

    for (i = 0; i < argc; i++)
        if (argv[i][0] == '-') {
            j = 1;
            while (argv[i][j] != '\0') {
                printf("%c ", argv[i][j]);
                j++;
            }
        }
    return 0;
}*/

//ZADATAK 4
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max_dim 50

int main(int argc, char** argv) {

    int i, j, k, A[max_dim][max_dim], m, n, min, ind_i, ind_j;

    if (argc != 3) {
        printf("greska");
        exit(0);
    }

    m = atoi(argv[1]);
    n = atoi(argv[2]);

    if (m > 50 || n > 50) {
        printf("greska");
        exit(0);
    }

    printf("Uneti matricu:\n");

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    for (i = 0; i < m; i++) {
        min = A[i][0];
        ind_j = 0;
        ind_i = i;
        for (j = 0; j < n; j++) {
            if (min > A[i][j]) {
                min = A[i][j];
                ind_i = i;
                ind_j = j;
            }
        }
        for (k = 0; k < m; k++)
            if (min < A[k][ind_j])break;
        if (k == m)printf("%d %d %d\n", ind_i, ind_j, min);
    }

    return 0;
}*/

//ZADATAK 5
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max_dim 200

int main(int argc, char** argv) {

    FILE *f, *g;
    char linija1[max_dim], linija2[max_dim];
    int br = 1;

    if (argc != 3) {
        printf("greska");
        exit(0);
    }

    if ((f = fopen(argv[1], "r")) == NULL) {
        printf("greska");
        exit(0);
    }

    if ((g = fopen(argv[2], "r")) == NULL) {
        printf("greska");
        exit(0);
    }

    while (fgets(linija1, max_dim, f) != NULL && fgets(linija2, max_dim, g) != NULL) {
        if (strcmp(linija1, linija2) != 0)
            printf("%d ", br);
        br++;
    }

    while (fgets(linija1, max_dim, f) != NULL) {
        printf("%d ", br);
        br++;
    }

    while (fgets(linija2, max_dim, g) != NULL) {
        printf("%d ", br);
        br++;
    }

    fclose(f);
    fclose(g);

    return 0;
}*/

//ZADATAK 6
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max_dim 200

typedef struct {
    unsigned int a, b;
    char ime[5];
} _pravougaonik;

int main(int argc, char** argv) {

    FILE *f;
    _pravougaonik niz[max_dim];
    int i = 0, j, max_p = 0;

    if (argc != 2) {
        printf("greska");
        exit(0);
    }

    if ((f = fopen(argv[1], "r")) == NULL) {
        printf("greska");
        exit(0);
    }

    while (fscanf(f, "%d%d%s", &niz[i].a, &niz[i].b, niz[i].ime) != EOF)
        i++;

    for (j = 0; j < i; j++) {
        if (niz[j].a == niz[j].b)printf("%s ", niz[j].ime);
        else if (niz[j].a * niz[j].b > max_p)max_p = niz[j].a * niz[j].b;
    }

    if (max_p != 0)
        printf("%d", max_p);

    fclose(f);

    return 0;
}*/

//ZADATAK 7
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max_dim 200

int main(int argc, char** argv) {

    FILE *f;

    int otv = 0, zatv = 0;
    char c;

    if (argc != 2) {
        printf("greska");
        exit(0);
    }

    if ((f = fopen(argv[1], "r")) == NULL) {
        printf("greska");
        exit(0);
    }

    while ((c = fgetc(f)) != EOF) {
        if (c == ')')zatv++;
        else if (c == '(')otv++;
        if (zatv > otv) break;
    }
    
    if (otv == zatv)printf("jesu");
    else printf("nisu");

    fclose(f);

    return 0;
}*/

//ZADATAK 8
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max_dim 100
#define max_oc 10

typedef struct {
    char ime[max_dim];
    int oc[max_oc], br_ocena;
    float pr_oc;
} STUDENT;

int main(int argc, char** argv) {

    FILE *f;
    char ime[max_dim], prez[max_dim], c;
    STUDENT niz[max_dim];
    int i = 0, j, k, max_ind = 0, s, e = 0;
    float max_pr = 0;

    if (argc != 2) {
        printf("greska");
        exit(0);
    }

    if ((f = fopen(argv[1], "r")) == NULL) {
        printf("greska");
        exit(0);
    }

    for (i = 0; i < max_dim; i++)
        niz[i].br_ocena = 0;

    i = 0;
    while (!feof(f)) {
        e++;
        fscanf(f, "%s%s", ime, prez);
        strcpy(niz[i].ime, ime);
        strcat(niz[i].ime, " ");
        strcat(niz[i].ime, prez);
        fscanf(f, "%d", &niz[i].oc[niz[i].br_ocena]);
        while (niz[i].oc[niz[i].br_ocena] != 0) {
            niz[i].br_ocena++;
            fscanf(f, "%d", &niz[i].oc[niz[i].br_ocena]);
        }
        i++;
    }
    i--;

    for (j = 0; j < i; j++) {
        s = 0;
        for (k = 0; k < niz[j].br_ocena; k++)
            s += niz[j].oc[k];
        niz[j].pr_oc = (float) (s / niz[j].br_ocena);
        if (niz[j].pr_oc > max_pr) {
            max_pr = niz[j].pr_oc;
            max_ind = j;
        }
    }

    if (e > 1) {
        printf("%s ", niz[max_ind].ime);
        for (j = 0; j < niz[max_ind].br_ocena; j++)
            printf("%d ", niz[max_ind].oc[j]);
        printf("%.2f", niz[max_ind].pr_oc);
    }

    fclose(f);

    return 0;
}*/

//ZADATAK 9
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max_dim 200

int unesiSkup(char *s, FILE* f);
void prebroj(char *s, int *br_slova, int *br_cifara);

int main(int argc, char** argv) {

    int br_cifara, br_slova, br;
    char s[max_dim];
    FILE *f;

    if (argc != 2) {
        printf("greska");
        exit(0);
    }

    if ((f = fopen(argv[1], "r")) == NULL) {
        printf("greska");
        exit(0);
    }

    unesiSkup(s, f);
    prebroj(s, &br_slova, &br_cifara);
    printf("broj slova: %d\nbroj cifara: %d", br_slova, br_cifara);

    fclose(f);

    return 0;
}

int unesiSkup(char *s, FILE* f) {
    char c;
    int i = 0;
    while ((c = getc(f)) != EOF && c != '\n') {
        if (isdigit(c) || isalpha(c)) {
            s[i] = c;
            i++;
        } else break;
    }
    s[i] = '\0';
    return i;
}

void prebroj(char *s, int *br_slova, int *br_cifara) {
    int i, d, br_sl = 0, br_cif = 0;
    d = strlen(s);
    for (i = 0; i < d; i++) {
        if (isdigit(s[i]))br_cif++;
        else if (isalpha(s[i]))br_sl++;
    }
    *br_slova = br_sl;
    *br_cifara = br_cif;
}*/

//ZADATAK 10
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max_dim 200

typedef struct {
    int x;
    int y;
    int z;
} vektor;

int main(int argc, char** argv) {

    FILE *f;
    int n, i, max_d = 0, ind_max = 0, duz, j;
    vektor niz[max_dim];

    if (argc != 2) {
        printf("-1");
        exit(0);
    }

    if ((f = fopen(argv[1], "r")) == NULL) {
        printf("-1");
        exit(0);
    }

    fscanf(f, "%d", &n);

    while (fscanf(f, "%d%d%d", &niz[i].x, &niz[i].y, &niz[i].z) != EOF)
        i++;

    if (i == 0) {
        printf("-1");
        exit(0);
    }

    for (j = 0; j < i; j++) {
        duz = abs(niz[j].x * niz[j].x + niz[j].y * niz[j].y + niz[j].z * niz[j].z);
        if (duz > max_d) {
            max_d = duz;
            ind_max = j;
        }
    }

    printf("%d %d %d", niz[ind_max].x, niz[ind_max].y, niz[ind_max].z);

    fclose(f);

    return 0;
}*/