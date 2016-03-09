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
}
