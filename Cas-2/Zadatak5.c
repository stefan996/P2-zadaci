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
}
