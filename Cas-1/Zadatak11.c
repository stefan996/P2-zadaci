#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 100

int ascii(char rec[max]);

int main() {

    FILE *f, *g;
    int k;
    char c, rec[max];

    if ((f = fopen("/home/luka/Desktop/Vezbanje/ulaz.txt", "r")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    if ((g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    while (fscanf(f, "%s", rec) != EOF)
        if (ascii(rec)) {
            fputs(rec, g);
            fputc(' ', g);
        }


    fclose(f);
    fclose(g);

    return 0;
}

int ascii(char rec[max]) {
    int d, i, br = 0, max1 = 1000;
    d = strlen(rec);
    for (i = 0; i < d; i++)
        br += rec[i];
    printf("%d %s\n", br, rec);
    if (br > max1)return 1;
    else return 0;
}
