#include<stdio.h>

int parna_c(int n) {

    int br = 0;

    if (n < 10) {
        if (n % 2 == 0) return 0;
        else return n;
    } else {
        br = parna_c(n / 10);
        if ((n % 10) % 2 == 0)
            return br;
        else return br * 10 + n % 10;
    }
}

int main() {

    int n;

    printf("Unesi broj:\n");
    scanf("%d", &n);

    printf("Novi broj je:\n");
    printf("%d", parna_c(n));

    printf("\n");

    return 0;

}
