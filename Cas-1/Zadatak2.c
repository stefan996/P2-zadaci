#include <stdio.h>
#include <stdlib.h>
#define max 21

int main() {

    FILE *f = fopen("/home/luka/Desktop/Vezbanje/knjiga.txt", "r");
    int br = 0;

    if (f == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    while (fgetc(f) != EOF)
        if (fgetc(f) == '\n')br++;

    printf("%d", br + 1);
    fclose(f);

    return 0;
}
