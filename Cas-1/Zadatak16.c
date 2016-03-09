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
}
