#include <stdio.h>
#include<stdlib.h>

int umetni(int n, int k);

int main() {
    int n, k;

    printf("Unesi broj i poziciju:\n");
    scanf("%d%d", &n, &k);

    if (k < 0 || n < 0 || k > 31) {
        printf("pozicija nije u dobrom ospegu");
        exit(0);
    }

    printf("%d\n", umetni(n, k));
    
    return 0;
}

int umetni(int n, int k) {
    int i = 1;
    i <<= k;

    return n | i;
}
