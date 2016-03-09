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
}
