#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max_dim 200

int main(int argc, char** argv) {

    FILE *f;

    int otv = 0, zatv = 0;
    char c;

    if (argc != 2) {
        printf("greska");
        exit(0);
    }

    if ((f = fopen(argv[1], "r")) == NULL) {
        printf("greska");
        exit(0);
    }

    while ((c = fgetc(f)) != EOF) {
        if (c == ')')zatv++;
        else if (c == '(')otv++;
        if (zatv > otv) break;
    }
    
    if (otv == zatv)printf("jesu");
    else printf("nisu");

    fclose(f);

    return 0;
}
