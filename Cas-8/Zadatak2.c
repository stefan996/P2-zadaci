#include <stdio.h>
#include<stdlib.h>

int proveri(int n, int k);

int main() {
    int n, k;

    printf("Unesi broj i poziciju:\n");
    scanf("%d%d", &n, &k);

    if (k < 0 || n < 0 || k > 31) {
        printf("pozicija nije u dobrom ospegu");
        exit(0);
    }

    if (proveri(n, k))
        printf("jeste\n");
    else
        printf("nije\n");

    return 0;
}

int proveri(int n, int k) {
    int i = 1;
    i <<= k;

    return n & i;
}
