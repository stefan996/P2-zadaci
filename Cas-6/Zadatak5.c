#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MAX_KAR 21

int poredi(const void* a, const void* b);

int main() {
    int n, i;
    char* k;
    char s[MAX_KAR], niz[MAX][MAX_KAR];

    printf("Uneti n i nisku:\n");
    scanf("%d%s", &n, s);

    printf("Uneti n niski:\n");
    for (i = 0; i < n; i++)
        scanf("%s", niz[i]);

    k = (char*) bsearch(s, niz, n, MAX_KAR * sizeof (char), poredi);

    if (k != NULL)
        printf("%ld\n", ((long int) k - (long int) niz) / MAX_KAR);
    else
        printf("Nema!");
    //niz opadajuci da bi radilo
    return 0;
}

int poredi(const void* a, const void* b) {

    return strcmp(((char *) b), ((char *) a));
}
