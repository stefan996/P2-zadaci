#include<stdio.h>

int obrnuto(int n, int *stepen) {
    int k;

    if (n < 10) {
        return n;
    } else {
        k = obrnuto(n / 10, stepen);
        (*stepen) *= 10;
        return (n % 10)*(*stepen) + k;
    }
}

int main() {

    int n, stepen = 1;

    printf("Unesi broj:\n");
    scanf("%d", &n);

    printf("Obrnuti brojevi su:\n");
    printf("%d", obrnuto(n, &stepen));

    printf("\n");

    return 0;

}
