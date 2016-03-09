#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 200

int main(int argc, char** argv) {

    int i, j;

    for (i = 0; i < argc; i++)
        if (argv[i][0] == '-') {
            j = 1;
            while (argv[i][j] != '\0') {
                printf("%c ", argv[i][j]);
                j++;
            }
        }
    return 0;
}
