#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max_dim 200

int unesiSkup(char *s, FILE* f);
void prebroj(char *s, int *br_slova, int *br_cifara);

int main(int argc, char** argv) {

    int br_cifara, br_slova, br;
    char s[max_dim];
    FILE *f;

    if (argc != 2) {
        printf("greska");
        exit(0);
    }

    if ((f = fopen(argv[1], "r")) == NULL) {
        printf("greska");
        exit(0);
    }

    unesiSkup(s, f);
    prebroj(s, &br_slova, &br_cifara);
    printf("broj slova: %d\nbroj cifara: %d", br_slova, br_cifara);

    fclose(f);

    return 0;
}

int unesiSkup(char *s, FILE* f) {
    char c;
    int i = 0;
    while ((c = getc(f)) != EOF && c != '\n') {
        if (isdigit(c) || isalpha(c)) {
            s[i] = c;
            i++;
        } else break;
    }
    s[i] = '\0';
    return i;
}

void prebroj(char *s, int *br_slova, int *br_cifara) {
    int i, d, br_sl = 0, br_cif = 0;
    d = strlen(s);
    for (i = 0; i < d; i++) {
        if (isdigit(s[i]))br_cif++;
        else if (isalpha(s[i]))br_sl++;
    }
    *br_slova = br_sl;
    *br_cifara = br_cif;
}
