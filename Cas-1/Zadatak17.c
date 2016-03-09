#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max_dim 31
#define max 20
#define max_au 100

typedef struct {
    char marka[max_dim], model[max_dim];
    int cena;
} AUTOMOBIL;

int main() {

    FILE *f;
    char fajl[max], marke[max_dim][max_au];
    int n, i, j, c, k, s, br;
    AUTOMOBIL niz[max_au];

    //cena se ne unosi kao argument nego sa standardnog ulaza
    printf("Uneti datoteku i cenu:\n");
    scanf("%s%d", fajl, &c);


    if ((f = fopen(fajl, "r")) == NULL) {
        printf("greska");
        exit(0);
    }

    fscanf(f, "%d", &n);

    while (fscanf(f, "%s", niz[k].marka) != EOF) {
        fscanf(f, "%s", niz[k].model);
        fscanf(f, "%d", &niz[k++].cena);
    }

    for (i = 0; i < k; i++)
        if (niz[i].cena <= c) {
            s = 0;
            br = 0;
            for (j = 0; j < k; j++)
                if (strcmp(niz[i].marka, niz[j].marka) == 0) {
                    s += niz[j].cena;
                    br++;
                }
            printf("\nMarka: %s\nModel: %s\nProsecna cena za automobil marke %s: %.4f\n", niz[i].marka, niz[i].model, niz[i].marka, (float) s / br);
        }

    fclose(f);

    return 0;
}
