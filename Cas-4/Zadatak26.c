#include<stdio.h>
#include<stdlib.h>

int f(int a, int b);

int main() {
    int a, b;
    FILE *g = fopen("rez.txt", "w");

    if (g == NULL) {
        printf("Greska!");
        exit(0);
    }

    printf("Unesite brojeve a i b:\n");
    scanf("%d%d", &a, &b);

    fprintf(g, "%d", f(a, b));
    fclose(g);

    return 0;
}

int f(int a, int b) {
    if (a == 0 && b == 0)
        return 1;
    else if (a < 0 && b >= 0)
        return -f(-a, b);
    else if (a >= 0 && b < 0)
        return -f(a, -b);
    else if (a < 0 && b < 0)
        return f(-a, -b);
    else
        return f(b, a - 1) + 2;
}
