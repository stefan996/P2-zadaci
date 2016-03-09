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
}
