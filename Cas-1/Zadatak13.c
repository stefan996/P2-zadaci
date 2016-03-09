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
}
