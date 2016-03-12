#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DUZ 200

double slucajanRealan(int a, int b);
int slucajanCeo(int a, int b);

int main(int argc, char** argv) {

    int n, a, b, A[MAX_DUZ], i;
    double B[MAX_DUZ];

    if (argc != 4) {
        printf("greska");
        exit(0);
    }

    n = atoi(argv[1]);
    a = atoi(argv[2]);
    b = atoi(argv[3]);

    if (b < a || n > MAX_DUZ) {
        printf("greska");
        exit(0);
    }

    for (i = 0; i < n; i++) {
        A[i] = slucajanCeo(a, b);
        B[i] = slucajanRealan(a, b);
    }

    for (i = 0; i < n; i++)
        printf("A:%d B:%.1lf\n", A[i], B[i]);

    return 0;
}

double slucajanRealan(int a, int b) {
    return ((double) rand() / RAND_MAX)*(b - a) + a;
}

int slucajanCeo(int a, int b) {
    return rand() % (b - a + 1) + a;
}
