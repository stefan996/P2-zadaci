#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 100

int main() {

    FILE *f, *g;
    char ime1[max], ime2[max],
            ime3[max] = "/home/luka/Desktop/Vezbanje/",
            ime4[max] = "/home/luka/Desktop/Vezbanje/";
    char c[2], a;

    scanf("%s%s%s", ime1, ime2, c);

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
    if (c[0] == 'u') {
        while ((a = fgetc(f)) != EOF) {
            if (islower(a))a = toupper(a);
            fputc(a, g);
        }
    } else while ((a = fgetc(f)) != EOF) {
            if (isupper(a))a = tolower(a);
            fputc(a, g);
        }
    fclose(f);
    fclose(g);

    return 0;
}
