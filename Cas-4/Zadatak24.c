#include<stdio.h>
#define MAX 100

int uzastopni(int n, int* niz, int a, int b, int c);

int main() {
    int n, i, a, b, c, niz[MAX];
    
    printf("Unesite broj n:\n");
    scanf("%d", &n);
    
    printf("Uneti niz:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);
    
    printf("Unesite tri broja:\n");
    scanf("%d%d%d", &a, &b, &c);
    
    if (uzastopni(n, niz, a, b, c))
        printf("Jesu!");
    else
        printf("Nisu!");
    
    return 0;
}

int uzastopni(int n, int* niz, int a, int b, int c) {
    if (n < 3) return 0;
    else if (niz[n - 1] == c && niz[n - 2] == b && niz[n - 3] == a)
        return 1;
    else
        return uzastopni(n - 1, niz, a, b, c);
}
