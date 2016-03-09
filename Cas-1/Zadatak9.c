#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 100

int main() {

    FILE *f, *g;
    char c;

    if ((f = fopen("/home/luka/Desktop/Vezbanje/plain.txt", "r")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    if ((g = fopen("/home/luka/Desktop/Vezbanje/sifra.txt", "w")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    while ((c = fgetc(f)) != EOF) {
        if (islower(c)) {
            if (c == 'a')c = 'Z';
            else c = toupper(c - 1);
        } else if (isupper(c)) {
            if (c == 'A')c = 'z';
            else c = tolower(c - 1);
        }
        fputc(c, g);
    }


    fclose(f);
    fclose(g);

    return 0;
}
