#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

double frand();

int main() {
    int i = 0;

    while (i <= 30) { //moze vise ili manje od 30
        printf("%lf\n", frand());
        i++;
    }

    return 0;
}

double frand() {
    return (double) rand() / RAND_MAX;
}
