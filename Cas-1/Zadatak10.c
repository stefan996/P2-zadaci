#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 100

void rotiraj(char rot[max], int k);

int main() {

    FILE *f, *g;
    int k;
    char ime1[max], ime2[max] = "/home/luka/Desktop/Vezbanje/", rot[max];


    scanf("%s%d", ime1, &k);
    strcat(ime2, ime1);


    if ((f = fopen(ime2, "r")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    if ((g = fopen("/home/luka/Desktop/Vezbanje/rotirano.txt", "w")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    while (fscanf(f, "%s", rot) != EOF) {
        rotiraj(rot, k);
        fputs(rot, g);
        fputc(' ', g);
    }

    fclose(f);
    fclose(g);

    return 0;
}

void rotiraj(char rot[max], int k) {
    int d, j, i;
    char t;
    d = strlen(rot);
    for (j = 0; j < k; j++) {
        t = rot[0];
        for (i = 0; i < d - 1; i++)
            rot[i] = rot[i + 1];
        rot[d - 1] = t;
    }
}
