#include <stdio.h>

void print_bits(int n);

int main() {
    int n;

    printf("Unesi broj:\n");
    scanf("%d", &n);

    print_bits(n);

    return 0;
}

void print_bits(int n) {
    unsigned i = 1 << (sizeof (int)*8 - 1);

    while (i) {
        if (i & n)
            printf("1");
        else
            printf("0");

        i >>= 1;
    }
    putchar('\n');
}
