#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max_dim 50

int main(int argc, char** argv) {

    int i, j, k, A[max_dim][max_dim], m, n, min, ind_i, ind_j;

    if (argc != 3) {
        printf("greska");
        exit(0);
    }

    m = atoi(argv[1]);
    n = atoi(argv[2]);

    if (m > 50 || n > 50) {
        printf("greska");
        exit(0);
    }

    printf("Uneti matricu:\n");

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    for (i = 0; i < m; i++) {
        min = A[i][0];
        ind_j = 0;
        ind_i = i;
        for (j = 0; j < n; j++) {
            if (min > A[i][j]) {
                min = A[i][j];
                ind_i = i;
                ind_j = j;
            }
        }
        for (k = 0; k < m; k++)
            if (min < A[k][ind_j])break;
        if (k == m)printf("%d %d %d\n", ind_i, ind_j, min);
    }

    return 0;
}
