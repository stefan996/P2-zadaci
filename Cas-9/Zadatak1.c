#include<stdio.h>
#include<stdlib.h>

int main() {

    int *niz, n, i;

    printf("Uneti n:\n");
    scanf("%d", &n);

    niz = (int*) malloc(n * sizeof (int));
    
    if (niz == NULL) {
        printf("Greska!");
        exit(0);
    }

    printf("Uneti clanove niza:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    printf("Clanovi su:\n");
    for (i = 0; i < n; i++)
        printf("%d ", niz[i]);
    
    fclose(f);
    free(niz);

    return 0;
}
