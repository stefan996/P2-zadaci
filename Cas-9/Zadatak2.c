#include<stdio.h>
#include<stdlib.h>

int main() {

    int *niz, n, i;

    printf("Uneti n:\n");
    scanf("%d", &n);

    niz = (int*) malloc(2 * n * sizeof (int));
    
    if (niz == NULL) {
        printf("Greska!");
        exit(0);
    }

    printf("Uneti clanove niza:\n");
    for (i = 0; i < 2 * n; i++)
        scanf("%d", &niz[i]);

    printf("Clanovi su:\n");
    for (i = 0; i < 2 * n - 1; i += 2)
        printf("%d/%d  ", niz[i], niz[i + 1]);
    
    fclose(f);
    free(niz);
    
    return 0;
}
