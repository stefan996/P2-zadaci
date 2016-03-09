#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 100

int susedni(int mat[][max], int m, int n, int i, int j);

int main() {

    FILE *f;
    int m, n, i, j, mat[max][max];
    char c;

    if ((f = fopen("/home/luka/Desktop/Vezbanje/matrice.txt", "r")) == NULL) {
        fprintf(stderr, "-1");
        exit(0);
    }

    fscanf(f, "%d%d", &m, &n);


    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (fscanf(f, "%d", &mat[i][j]) == EOF) {
                printf("Lose uneta matrica.\n");
                exit(-1);
            }


    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (susedni(mat, m, n, i, j))printf("(%d, %d, %d)\n", i, j, mat[i][j]);


    fclose(f);

    return 0;
}

int susedni(int mat[][max], int m, int n, int i, int j) {
    int k, p, s = 0;
    for (k = -1; k < 2; k++)
        for (p = -1; p < 2; p++)
            if (k + i >= 0 && k + i <= m && p + j >= 0 && p + j <= n)
                s += mat[k + i][p + j];
    s -= mat[i][j];
    if (s == mat[i][j])return 1;
    else return 0;
}
