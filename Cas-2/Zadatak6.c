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
}
