#include <stdio.h>
#include<stdlib.h>

#define MAX_KAR 9

void print_bits(int n);
void nadji_heksa(int n, char s[MAX_KAR]);
char nadji_br(int n);

int main() {
    int x;
    char s[MAX_KAR];

    printf("Unesi x:\n");
    scanf("%d", &x);

    nadji_heksa(x, s);

    printf("%s", s);

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

char nadji_br(int n) {
    switch (n) {
        case 0: return 0 + '0';
        case 1: return 1 + '0';
        case 10: return 2 + '0';
        case 11: return 3 + '0';
        case 100: return 4 + '0';
        case 101: return 5 + '0';
        case 110: return 6 + '0';
        case 111: return 7 + '0';
        case 1000: return 8 + '0';
        case 1001: return 9 + '0';
        case 1010: return 'A';
        case 1011: return 'B';
        case 1100: return 'C';
        case 1101: return 'D';
        case 1110: return 'E';
        case 1111: return 'F';
    }
}

void nadji_heksa(int n, char s[MAX_KAR]) {
    int br, i, j;
    unsigned k = 1 << (sizeof (unsigned)*8 - 1);
    for (i = 0; i < 8; i++) {
        br = 0;
        for (j = 0; j<sizeof (int); j++) {
            if (k & n)
                br = br * 10 + 1;
            else
                br = br * 10;
            k >>= 1;
        }
        s[i] = nadji_br(br);
    }
    s[i] = '\0';

}
