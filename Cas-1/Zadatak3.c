#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

int main() {

    FILE *f, *g;
    char ime1[max], ime2[max],
            ime3[max] = "/home/luka/Desktop/Vezbanje/",
            ime4[max] = "/home/luka/Desktop/Vezbanje/";
    char c;
    scanf("%s%s", ime1, ime2);

    strcat(ime3, ime1);
    strcat(ime4, ime2);

    if ((f = fopen(ime3, "r")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    if ((g = fopen(ime4, "w")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    while ((c = fgetc(f)) != EOF) {
        c = fgetc(f);

        fputc(c, g);
    }
    fclose(f);
    fclose(g);

    return 0;
}
