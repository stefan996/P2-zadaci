#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 50

int main(int argc, char** argv) {

    int i;

    printf("%d\n", argc);

    for (i = 0; i < argc; i++)
        printf("%d. %s\n", i + 1, argv[i]);

    return 0;
}
