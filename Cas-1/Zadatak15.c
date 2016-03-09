#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max_dim 21
#define max 201

int uporedi(char* r, char l[max]);

int main() {

    FILE *f, *g;
    char prvi_f[max_dim], drugi_g[max_dim], r[max], linija[max][max];
    int n, i = 0, br, br_l = -1, j;

    printf("Uneti dve datoteke i n:\n");
    scanf("%s%s%d", prvi_f, drugi_g, &n);


    if ((f = fopen(prvi_f, "r")) == NULL) {
        printf("greska");
        exit(0);
    }

    if ((g = fopen(drugi_g, "w")) == NULL) {
        printf("greska");
        exit(0);
    }

    fscanf(f, "%s", r);

    while ((fgets(linija[i++], max, f)) != NULL);

    for (j = 0; j < i; j++) {
        br_l++;
        br = uporedi(r, linija[j]);
        if (br >= n)
            fprintf(g, "%d:%d\n", br, br_l);
    }

    fclose(f);
    fclose(g);

    return 0;
}

int uporedi(char* r, char l[max]) {
    int d, i, dr, j, k, br = 0;
    dr = strlen(r);
    d = strlen(l);
    for (i = 0; i < d; i++) {
        k = 0;
        if (l[i] == r[0]) {
            k = i;
            for (j = 0; j < dr; j++) {
                if (l[k] != r[j])break;
                k++;
            }
        }
        if (k - i == dr)br++;
    }
    return br;
}
