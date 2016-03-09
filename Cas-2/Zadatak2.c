#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 200

int main(int argc, char** argv) {

    int i, a, b, A[max];
    if (argc != 3) {
        printf("greska");
        exit(0);
    }
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    if (a > b || b - a > max) {
        printf("greska");
        exit(0);
    }
    for (i = 0; i <= b - a; i++) {
        A[i] = a + i;
        printf("%d ", A[i]);
    }

    return 0;
}
