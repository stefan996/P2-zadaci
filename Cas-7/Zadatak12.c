#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MAX_KAR 21
#define MAX_IDE 3

typedef struct {
    char ime[MAX_KAR], id_ime[MAX_IDE];
    int id_br;
} STUDENT;

int poredi(const void* a, const void* b);
int poredi1(const void* a, const void* b);
int poredi2(const void* a, const void* b);
int poredi3(const void* a, const void* b);

int main(int argc, char** argv) {

    int i = 0, j;
    char c;
    STUDENT niz[MAX], x;
    STUDENT *k;

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    FILE *f = fopen(argv[1], "r");

    if (f == NULL) {
        printf("Greska!");
        exit(0);
    }

    while (fscanf(f, "%s %c%c%d", niz[i].ime, &niz[i].id_ime[0], &niz[i].id_ime[1], &niz[i].id_br) != EOF)
        i++;

    printf("Uneti studenta:\n");
    scanf("%s %c%c%d", x.ime, &x.id_ime[0], &x.id_ime[1], &x.id_br);
    printf("\n");

    //sortira po broju
    qsort(niz, i, sizeof (STUDENT), poredi);

    //sortira po slovima
    //qsort(niz, i, sizeof (STUDENT), poredi1);

    //trazi studenta po broju u identifikaciji
    k = (STUDENT*) bsearch(&x.id_br, niz, i, sizeof (STUDENT), poredi2);

    //trazi studenta po slovima u identifikaciji
    //k = (STUDENT*) bsearch(x.id_ime, niz, i, sizeof (STUDENT), poredi3);

    for (j = 0; j < i - 1; j++)
        printf("%s %s%d\n", niz[j].ime, niz[j].id_ime, niz[j].id_br);
    printf("\n");

    //ispisuje nadjenog studenta
    if (k != NULL)
        printf("%s %s%d\n", k->ime, k->id_ime, k->id_br);
    else
        printf("Nema takvog!\n");
    return 0;
}

//sortira po brojevima

int poredi(const void* a, const void* b) {

    STUDENT* n = (STUDENT*) a;
    STUDENT* m = (STUDENT*) b;

    return n->id_br - m->id_br;
}

//sortira po slovima 

int poredi1(const void* a, const void* b) {

    STUDENT* n = (STUDENT*) a;
    STUDENT* m = (STUDENT*) b;

    return strcmp((n->id_ime), (m->id_ime));
}

//pretrazuje studenta po broju

int poredi2(const void* a, const void* b) {

    int* n = (int*) a;
    STUDENT* m = (STUDENT*) b;

    return *n - m->id_br;
}

//pretrazuje studenta po slovu

int poredi3(const void* a, const void* b) {

    char* n = (char*) a;
    STUDENT* m = (STUDENT*) b;

    return strcmp(n, m->id_ime);
}
