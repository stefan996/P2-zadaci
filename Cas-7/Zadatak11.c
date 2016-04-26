#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct {
    int im, br;
} RAZLOMAK;

int poredi(const void* a, const void* b);

int main(int argc, char** argv) {

    int i = 0, j;
    char c;
    RAZLOMAK niz[MAX];

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    FILE *f = fopen(argv[1], "r");

    if (f == NULL) {
        printf("Greska!");
        exit(0);
    }
    
    //zamisljeno je da se u datoteci unose razlomci u obliku 3/4...
    while (fscanf(f, "%d%c%d", &niz[i].br, &c, &niz[i].im) != EOF)
        i++;


    qsort(niz, i, sizeof (RAZLOMAK), poredi);

    for (j = 0; j < i; j++)
        printf("%d/%d\n", niz[j].br, niz[j].im);

    return 0;
}

int poredi(const void* a, const void* b) {

    RAZLOMAK* n = (RAZLOMAK*) a;
    RAZLOMAK* m = (RAZLOMAK*) b;

    return (((n->br)*(m->im)-(m->br)*(n->im))*((n->im)*(m->im)));
}
