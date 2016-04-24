#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int poredi(const void * a, const void * b);

int main() {
    int x, n, niz[MAX], i;
    int* br;

    printf("Uneti n i x:\n");
    scanf("%d%d", &n, &x);

    printf("Uneti n brojeva:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    br = (int*) bsearch(&x, niz, n, sizeof (int), poredi);

    if (br != NULL)
        printf("%ld", br - niz);
    else
        printf("Nije pronadjen!");

    return 0;
}

int poredi(const void * a, const void * b) {
    return (*(int*) a - *(int*) b);
}
