#include <stdio.h>
#include<stdlib.h>

int suma(int n);

int main() {
    int n;

    printf("Unesi broj:\n");
    scanf("%d", &n);

    printf("%d\n", suma(n));

    return 0;
}

int suma(int n) {
    int i, k = 1, br = 0;
    for (i = 0; i < (sizeof (int)*8); i++) {
        if (k & n)
            br++;
        k <<= 1;
    }
    return br;
}
