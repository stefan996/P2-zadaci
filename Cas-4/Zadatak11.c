#include<stdio.h>

int neparna_c(int n) {

    int br = 0;

    if (n < 10) {
        if (n % 2 != 0) return n * 10;
        else return n;
    } else {
        br = neparna_c(n / 10);
        if ((n % 10) % 2 != 0)
            return (br * 10 + n % 10) * 10;
        else
            return br * 10 + n % 10;
    }
}

int main() {

    int n;

    printf("Unesi broj:\n");
    scanf("%d", &n);

    printf("Novi broj je:\n");
    printf("%d", neparna_c(n));

    printf("\n");

    return 0;
}
