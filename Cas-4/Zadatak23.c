#include<stdio.h>
#include<math.h>

void podbroj(int n, int d);

int main() {
    int n, d;
    printf("Unesite broj n i d:\n");
    scanf("%d%d", &n, &d);
    podbroj(n, d);
    return 0;
}

void podbroj(int n, int d) {
    if (n < pow(10, d))
        printf("%d ", n);
    else {
        printf("%d ", n % (int) pow(10, d));
        n /= 10;
        podbroj(n, d);
    }
}
