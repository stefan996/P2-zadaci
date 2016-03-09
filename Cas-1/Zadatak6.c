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

    int k, a = 0, br = 0;
    char c;

    scanf("%d%s", &k, ime1);
    strcat(ime3, ime1);


    if ((f = fopen(ime3, "r")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    while ((c = fgetc(f)) != EOF) {
        if (isdigit(c))
            a++;
        else {
            if (a == k)br++;
            a = 0;
        }
    }

    printf("%d", br);


    fclose(f);

    return 0;
}
