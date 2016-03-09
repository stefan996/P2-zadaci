#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 100

int palindrom(char niz[]);

int main() {

    FILE *f, *g;
    int k;
    char c, rec[max];

    if ((f = fopen("/home/luka/Desktop/Vezbanje/razno.txt", "r")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    if ((g = fopen("/home/luka/Desktop/Vezbanje/palindromi.txt", "w")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    while (fscanf(f, "%s", rec) != EOF)
        if (palindrom(rec)) {
            fputs(rec, g);
            fputc(' ', g);
        }

    fclose(f);
    fclose(g);

    return 0;
}

int palindrom(char niz[]) {
    char a[max];
    int i, k = 0, p, br = 0, n;
    n = strlen(niz);
    for (i = 0; i < n; i++) {
        if (isalpha(niz[i])) {
            a[k] = niz[i];
            k++;
        }
    }
    for (i = 0; i < k; i++)
        a[i] = tolower(a[i]);
    p = k - 1;
    for (i = 0; i < k / 2; i++) {
        if (a[i] == a[p]) {
            br++;
            p--;
        } else break;
    }

    if (br == k / 2)return 1;
    else return 0;
}
