#include<stdio.h>

int max_c(int n) {
    int max = 0, br;

    if (n < 10)
        if (n > max) return n;
        else return max;
    else {
        br = max_c(n / 10);
        if (br > (n % 10))
            return br;
        else return n % 10;
    }
}

int main() {

    int n;

    printf("Unesi broj\n");
    scanf("%d", &n);

    printf("Max cifra je: %d ", max_c(n));

    printf("\n");

    return 0;

}
