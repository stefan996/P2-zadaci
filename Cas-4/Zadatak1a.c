#include<stdio.h>

void ispis(int n) {

    if (n == 1)printf("1 ");
    else {
        ispis(n - 1);
        printf("%d ", n);
    }
}

int main() {

    ispis(5);

    return 0;
}
