#include<stdio.h>

int uklanja(int n, int cifra) {

    int br = 0;

    if (n < 10) {
        if (n == cifra) return 0;
        else return n;
    } else {
        br = uklanja(n / 10, cifra);
        if (n % 10 == cifra)
            return br;
        else return br * 10 + n % 10;
    }
}

int main() {

    int n, cifra;

    printf("Unesi broj i cifru:\n");
    scanf("%d%d", &n, &cifra);

    printf("Novi broj je: %d ", uklanja(n, cifra));

    printf("\n");

    return 0;

}
