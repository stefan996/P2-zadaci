#include<stdio.h>

void ispis(int n) {

    if (n == 1)printf("1 ");
    else {
        printf("%d ", n);
        ispis(n - 1);
    }
}

int main() {

    ispis(5);

    return 0;
}
