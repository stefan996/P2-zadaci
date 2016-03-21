#include<stdio.h>

void heksa(int n) {

    int c;
    if (n < 16)
        printf("%d", n);
    else {
        heksa(n / 16);
        c = n % 16;
        if (c < 10)
            printf("%d", c);
        else
            printf("%c", c + 'A' - 10);
    }

}

int main() {

    int n;

    printf("Unesi broj\n");
    scanf("%d", &n);

    printf("Heksadekadni broj je: ");
    heksa(n);
    printf("\n");

    return 0;

}
