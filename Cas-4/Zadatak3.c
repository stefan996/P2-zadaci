#include<stdio.h>

int parni(int n) {

    if (n < 10)
        if (n % 2 == 0) return 1;
        else return 0;
    else {

        if ((n % 10) % 2 == 0)
            return 1 + parni(n / 10);
        else
            return parni(n / 10);
    }
}

int main() {

    int n;

    printf("Unesi broj\n");
    scanf("%d", &n);

    printf("Broj parnih je: %d ", parni(n));

    printf("\n");

    return 0;

}
