#include<stdio.h>

int prost1(int n, int i) {
    if (i == 1)
        return 1;

    else {
        if (n % i == 0)
            return 0;
        else
            return prost1(n, i - 1);
    }
}

int prost(int n) {

    return prost1(n, n / 2);
}

int main() {

    int n, id;
    printf("Unesite broj:\n");
    scanf("%d", &n);

    id = prost(n);

    if (id)
        printf("Broj je prost!\n");
    else
        printf("Broj nije prost!\n");

    return 0;
}
