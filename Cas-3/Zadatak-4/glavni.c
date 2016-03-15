#include<stdio.h>
#include<stdlib.h>
#include"velikibroj.h"

int main(int argc, char** argv) {
    FILE *f = fopen(argv[1], "r"), *g = fopen("velikibroj.txt", "w");
    VelikiBroj a, b, c;
    int x;

    if (f == NULL || g == NULL) {
        printf("greska");
        exit(0);
    }

    if (argc != 2) {
        printf("greska");
        exit(0);
    }

    a = ucitaj_broj(f);
    b = ucitaj_broj(f);
    //     ispis(a,g);
    //     fprintf(g,"\n");
    //     ispis(b,g);
    //     printf("%d",poredi(a,b));
    //     c=saberi(a,b);
    //     printf("Unesi skalar x:\n");
    //     scanf("%d",&x);
    //     c=mnozi_skalarom(a,x);
    c = mnozi_dva(a, b);
    ispis(c, g);
}
