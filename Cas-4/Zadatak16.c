#include<stdio.h>
#define MAX 100

void crtanje(int n, int raz);

int main() {

    int n;

    printf("Unesi n:\n");
    scanf("%d", &n);

    crtanje(n, 0);

    printf("\n");

    return 0;

}

void crtanje(int n, int raz) {
    int i;

    if (n == 1) {
        for (i = 0; i < raz; i++)printf(" ");
        printf("+");
    } else {
        crtanje(n - 1, raz + 1);
        printf("\n");
        for (i = 0; i < raz; i++)printf(" ");
        for (i = 0; i < n; i++)printf("+");
    }
}
