#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max 100
#define max_br 10

int main() {

    FILE *f;
    char ime1[max],
            ime3[max] = "/home/luka/Desktop/Vezbanje/";

    int niz[max_br], i, maxbr, p = 0, cif;
    char c;

    scanf("%s", ime1);
    strcat(ime3, ime1);


    if ((f = fopen(ime3, "r")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    for (i = 0; i < max_br; i++)niz[i] = 0;

    while ((c = fgetc(f)) != EOF)
        if (isdigit(c)) {
            niz[c - '0']++;
            p = 1;
        }

    maxbr = niz[0];
    cif = 0;
    for (i = 1; i < max_br; i++)
        if (niz[i] > maxbr) {
            cif = i;
            maxbr = niz[i];
        }

    if (p == 0)printf("-1");
    else printf("%d", cif);
    fclose(f);

    return 0;
}
