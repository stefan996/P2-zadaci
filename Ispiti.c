//Ispitni zadaci

//Oktobar 2015

//ZADATAK 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv) {
    float *niz, s, max;
    int i = 1, k = 0;

    if ((argc - 1) % 3 != 0) {
        printf("-1\n");
        exit(0);
    }

    argc /= 3;
    niz = malloc(argc * sizeof (float));

    while (argc--) {
        s = (atof(argv[i]) + atof(argv[i + 1]) + atof(argv[i + 2])) / 2;
        niz[k] = sqrt(s * (s - atof(argv[i]))*(s - atof(argv[i + 1]))*(s - atof(argv[i + 2])));
        k++;
        i += 3;
    }

    max = niz[0];
    for (i = 1; i < k; i++)
        if (niz[i] > max)
            max = niz[i];


    printf("%.2f\n", max);

    return 0;
}


//ZADATAK 2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_KAR 21

typedef struct {
    int br_koef;
    char ime[MAX_KAR];
    float niz_koef[MAX_KAR];
} polinom;

void sort(polinom* p, int br_pol);

int main(int argc, char** argv) {
    int br_pol, i = 0, k;
    polinom *p;
    FILE* f = fopen("polinomi.txt", "r");

    if (f == NULL) {
        printf("Greska u otvaranju datoteke!\n");
        exit(0);
    }

    fscanf(f, "%d", &br_pol);

    p = malloc(br_pol * sizeof (polinom));
    if (p == NULL) {
        printf("Greska pri alokaciji memorije!\n");
        exit(0);
    }

    while (fscanf(f, "%s%d", p[i].ime, &p[i].br_koef) != EOF) {
        for (k = 0; k < p[i].br_koef; k++)
            fscanf(f, "%f", &p[i].niz_koef[k]);
        i++;
    }

    sort(p, br_pol);

    for (i = 0; i < br_pol; i++)
        printf("%s\n", p[i].ime);
    return 0;
}

void sort(polinom* p, int br_pol) {
    int i, j;
    polinom pom;
    char s[MAX_KAR];
    for (i = 1; i < br_pol; i++)
        for (j = 0; j < br_pol - 1; j++) {
            if (p[j].br_koef < p[j + 1].br_koef) {
                pom = p[j];
                p[j] = p[j + 1];
                p[j + 1] = pom;
            } else if (p[j].br_koef == p[j + 1].br_koef) {
                if (strlen(p[j].ime) < strlen(p[j + 1].ime)) {
                    strcpy(s, p[j].ime);
                    strcpy(p[j].ime, p[j + 1].ime);
                    strcpy(p[j + 1].ime, s);
                }
            }
        }
}

//ZADATAK 3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_BR 32

unsigned inv(int niz[MAX_BR], int n);

int main(int argc, char** argv) {
    int i, n, niz[MAX_BR];
    unsigned x;

    printf("Uneti n:\n");
    scanf("%d", &n);

    if (n > 32) {
        printf("-1\n");
        exit(0);
    }

    printf("Uneti n brojeva:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    printf("%u\n", inv(niz, n));
    return 0;
}

unsigned inv(int niz[MAX_BR], int n) {
    unsigned x = 0, mask = 1;
    int i;

    for (i = n - 1; i >= 0; i--) {
        x |= (mask & (~(niz[i] >> i)));
        x <<= 1;
    }
    return x >> 1;
}

//ZADATAK 4

#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/liste.h"
#include <string.h>

void f4(_cvor* lista, int k);
int zbir_cifara(int n);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int n;
    _cvor* lista = NULL;
    FILE* f = fopen(argv[1], "r");
    FILE* k = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (k == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    lista = napravi_listu(f);

    printf("Unesi k:\n");
    scanf("%d", &n);
    //k mi se koristi za datoteku pa sam uzeo n

    f4(lista, n);

    ispis_liste(lista, k);

    oslobodi(lista);
    fclose(f);
    fclose(k);

    return 0;
}

void f4(_cvor* lista, int k) {
    int i, z1, z2;
    _cvor* pom = NULL, *novi = NULL;
    if (lista == NULL)
        return;
    else if (lista->sledeci == NULL)
        return;

    if (abs(lista->vrednost - lista->sledeci->vrednost) == k || abs(lista->vrednost + lista->sledeci->vrednost) == k)
        i = 1;
    else
        i = 0;
    f4(lista->sledeci, k);
    if (i == 1) {
        z1 = zbir_cifara(lista->vrednost);
        z2 = zbir_cifara(lista->sledeci->vrednost);
        pom = lista->sledeci;
        novi = novi_cvor(z1 + z2);
        lista->sledeci = novi;
        novi->sledeci = pom;
    }
}

int zbir_cifara(int n) {
    int cj, rez = 0;
    while (n) {
        cj = n % 10;
        n /= 10;
        rez += cj;
    }

    return rez;
}

//ZADATAK 5

#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/stabla.h"
#include <string.h>
#include <stdlib.h>

int f5(_cvor* s);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, k;
    _cvor* stablo = NULL;

    FILE* f = fopen(argv[1], "r");
    FILE* g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    stablo = unos(f);

    printf("%d\n", f5(stablo));
    //ispis(stablo, g);

    oslobodi(stablo);
    fclose(f);
    fclose(g);

    return 0;
}

int f5(_cvor* s) {
    static int nivo = 1;
    int l, d;
    if (s == NULL)
        return 0;
    nivo++;
    l = f5(s->levo);
    d = f5(s->desno);
    nivo--;
    if (nivo == 1) {
        return l + d - s->vrednost;
    }
    if (nivo % 2 == 0) {
        return s->vrednost - l - d;
    } else {
        return s->vrednost - l - d;
    }
}

//Jun1 2015
//Prva grupa

//ZADATAK 1

#include <stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {
    float s1, v1, s2, v2;

    if (argc != 5) {
        printf("-1\n");
        exit(0);
    }

    s1 = atof(argv[1]);
    v1 = atof(argv[2]);
    s2 = atof(argv[3]);
    v2 = atof(argv[4]);

    printf("%d\n", ((int) (s2 / s1)*(int) (v2 / v1)));
    return 0;
}

//ZADATAK 2

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct {
    float Ax, Ay, Bx, By, duz;
} duzi;

int poredi(const void* a, const void* b);

int main(int argc, char** argv) {
    FILE* f = fopen("duzi.txt", "r");
    int n, i = 0;
    duzi *d;

    if (f == NULL) {
        printf("-1\n");
        return 0;
    }

    fscanf(f, "%d", &n);

    d = malloc(n * sizeof (duzi));
    if (d == NULL) {
        printf("-1\n");
        exit(0);
    }

    while (fscanf(f, "%f%f%f%f", &d[i].Ax, &d[i].Ay, &d[i].Bx, &d[i].By) != EOF)
        i++;

    for (i = 0; i < n; i++)
        d[i].duz = sqrt((d[i].Ax - d[i].Bx)*(d[i].Ax - d[i].Bx)+(d[i].Ay - d[i].By)*(d[i].Ay - d[i].By));

    qsort(d, n, sizeof (duzi), poredi);

    for (i = 0; i < n; i++)
        printf("%.2f %.2f %.2f %.2f %.2f\n", d[i].Ax, d[i].Ay, d[i].Bx, d[i].By, d[i].duz);


    return 0;
}

int poredi(const void* a, const void* b) {
    return ((duzi*) b)->duz - ((duzi*) a)->duz;
}

//ZADATAK 3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_BR 32

unsigned inv(int niz[MAX_BR], int n);

int main(int argc, char** argv) {
    int i, n, niz[MAX_BR];
    unsigned x;

    printf("Uneti n:\n");
    scanf("%d", &n);

    if (n > 32) {
        printf("-1\n");
        exit(0);
    }

    printf("Uneti n brojeva:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    printf("%u\n", inv(niz, n));
    return 0;
}

unsigned inv(int niz[MAX_BR], int n) {
    unsigned x = 0, mask = 1;
    int i;

    for (i = n - 1; i >= 0; i--) {
        x |= (mask & ((niz[i] >> i)));
        x <<= 1;
    }
    return x >> 1;
}

//ZADATAK 4

#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/liste.h"
#include <string.h>

void f4(_cvor* lista, _cvor* prvi);
int zbir(_cvor* lista, _cvor* pokazivac);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int n;
    _cvor* lista = NULL;
    FILE* f = fopen(argv[1], "r");
    FILE* k = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (k == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    lista = napravi_listu(f);

    f4(lista, lista);

    ispis_liste(lista, k);

    oslobodi(lista);
    fclose(f);
    fclose(k);

    return 0;
}

void f4(_cvor* lista, _cvor* prvi) {
    _cvor* pom;
    int i;
    if (lista == NULL)
        return;
    if (lista->sledeci == NULL)
        return;
    if (lista->sledeci->vrednost < zbir(prvi, lista->sledeci))
        i = 1;
    else
        i = 0;
    f4(lista->sledeci, prvi);
    if (i == 1) {
        pom = lista->sledeci;
        lista->sledeci = lista->sledeci->sledeci;
        free(pom);
    }
}

int zbir(_cvor* lista, _cvor* pokazivac) {
    int s = 0;
    if (lista == NULL)
        return 0;
    for (; lista != pokazivac;) {
        s += lista->vrednost;
        lista = lista->sledeci;
    }

    return s;
}

//ZADATAK 5

#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/stabla.h"
#include <string.h>
#include <stdlib.h>

int identicna(_cvor* stablo1, _cvor* stablo2);
void izmeni(_cvor* stablo1, _cvor* stablo2);

int main(int argc, char** argv) {

    if (argc != 3) {
        printf("Greska!");
        exit(0);
    }

    int i;
    _cvor* stablo1 = NULL, *stablo2 = NULL;

    FILE* f = fopen(argv[1], "r");
    FILE* k = fopen(argv[2], "r");
    FILE* g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL || f == NULL || k == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    stablo1 = unos(f);
    stablo2 = unos(k);

    if (identicna(stablo1, stablo2)) {
        izmeni(stablo1, stablo2);
        ispis(stablo1, g);
    } else
        printf("-1\n");


    oslobodi(stablo1);
    oslobodi(stablo2);
    fclose(f);
    fclose(g);
    fclose(k);

    return 0;
}

void izmeni(_cvor* stablo1, _cvor* stablo2) {
    if (stablo1 == NULL && stablo2 == NULL)
        return;
    izmeni(stablo1->levo, stablo2->levo);
    izmeni(stablo1->desno, stablo2->desno);

    stablo1->vrednost += stablo2->vrednost;

}

int identicna(_cvor* stablo1, _cvor* stablo2) {
    int l, d;
    if (stablo1 == NULL && stablo2 == NULL)
        return 1;
    else if (stablo1 != NULL && stablo2 == NULL)
        return 0;
    else if (stablo1 == NULL && stablo2 != NULL)
        return 0;
    l = identicna(stablo1->levo, stablo2->levo);
    d = identicna(stablo1->desno, stablo2->desno);
    if (l == 1 && d == 1)
        return 1;
    else
        return 0;
}

//Januar 2016

//ZADATAK 1

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {
    int i, k;

    k = atoi(argv[1]);

    if (k == 0) {
        printf("-1\n");
        exit(0);
    }

    for (i = k + 1; i < argc; i += k)
        printf("%s ", argv[i]);

    return 0;
}

//ZADATAK 2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_KAR 101

int poredi(const void* a, const void* b);

int main(int argc, char** argv) {
    int i = 0, d, j;
    FILE* f = fopen("recenice.txt", "r");
    char s[MAX_KAR], **pom = NULL, **niz = NULL, *pom1 = NULL;

    if (f == NULL) {
        printf("Greska u otvaranju datoteke!\n");
        exit(0);
    }

    while (fgets(s, MAX_KAR, f) != NULL) {
        d = strlen(s);
        if (isupper(s[0]) && islower(s[1]) && (s[d - 2] == '.' || s[d - 2] == '!' || s[d - 2] == '?') && islower(s[d - 3])) {
            pom = (char**) realloc(niz, (i + 1) * sizeof (char*));
            if (pom == NULL) {
                printf("Greska pri alokaciji!\n");
                for (j = 0; j < i; j++)
                    free(niz[j]);
                free(niz);
                exit(0);
            } else niz = pom;

            pom1 = (char*) malloc(MAX_KAR * sizeof (char));
            if (pom1 == NULL) {
                printf("Greska pri alokaciji!\n");
                for (j = 0; j < i; j++)
                    free(niz[j]);
                free(niz);
                exit(0);
            } else niz[i] = pom1;
            strcpy(niz[i], s);
            i++;
        }
    }

    qsort(niz, i, sizeof (char*), poredi);

    for (j = 0; j < i; j++)
        printf("%s", niz[j]);

    for (j = 0; j < i; j++)
        free(niz[j]);
    free(niz);

    fclose(f);

    return 0;
}

int poredi(const void* a, const void* b) {

    return strcmp(*(char**) a, *(char**) b);
}

//ZADATAK 3

#include <stdio.h>
#include <stdlib.h>

void obradi(unsigned x, unsigned n, unsigned *niz);
int broj_jedinica(unsigned x);

int main(int argc, char** argv) {

    int x, n, i;
    unsigned *niz;

    printf("Uneti x i n:\n");
    scanf("%d%d", &x, &n);

    if (x < 0 || n < 0) {
        printf("-1\n");
        exit(0);
    }

    niz = (unsigned*) malloc(n * sizeof (unsigned));

    printf("Uneti n brojeva:\n");
    for (i = 0; i < n; i++)
        scanf("%u", &niz[i]);

    obradi(x, n, niz);

    for (i = 0; i < n; i++)
        printf("%d ", niz[i]);

    return 0;
}

void obradi(unsigned x, unsigned n, unsigned *niz) {
    int bj_b, bj_x, i;
    unsigned j = 1;
    bj_x = broj_jedinica(x);
    for (i = 0; i < n; i++) {
        bj_b = broj_jedinica(niz[i]);
        if (bj_b > bj_x)
            niz[i] = (~(j << i))&(niz[i]);
        else
            niz[i] = (1 << i) | niz[i];
    }
}

int broj_jedinica(unsigned x) {
    int s = 0, i, d;
    d = sizeof (unsigned)*8;
    while (x) {
        if (x & 1)
            s++;
        x >>= 1;
    }

    return s;
}

//ZADATAK 4

#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/liste.h"
#include <string.h>

void obrni(_cvor* lista);
int duzina(_cvor* lista);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int n;
    _cvor* lista = NULL;
    FILE* f = fopen(argv[1], "r");
    FILE* k = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (k == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    lista = napravi_listu(f);

    obrni(lista);
    ispis_liste(lista, k);

    oslobodi(lista);
    fclose(f);
    fclose(k);

    return 0;
}

void obrni(_cvor* lista) {
    if (lista != NULL) {
        _cvor *j;
        int pom, d, i, p, k;
        d = p = duzina(lista);
        for (i = 0; i < d; i++) {
            p--;
            for (j = lista, k = 0; k < p ; j = j->sledeci, k++) {
                pom = j->sledeci->vrednost;
                j->sledeci->vrednost = j->vrednost;
                j->vrednost = pom;
            }
        }
    }
}

int duzina(_cvor* lista) {
    int i;
    if (lista == NULL)
        return 0;
    for (i = 0; lista != NULL; i++)
        lista = lista->sledeci;

    return i;
}

//ZADATAK 5

#include <stdio.h>
#include "/home/luka/Desktop/Vezbanje/stabla.h"
#include <string.h>
#include <stdlib.h>

void f5(_cvor* s);
int zbir(_cvor* s);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Greska!");
        exit(0);
    }

    int i, k;
    _cvor* stablo = NULL;

    FILE* f = fopen(argv[1], "r");
    FILE* g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");

    if (g == NULL || f == NULL) {
        printf("Greska u otvaranju datoteke.");
        exit(0);
    }

    stablo = unos(f);

    f5(stablo);
    //ispis(stablo, g);

    oslobodi(stablo);
    fclose(f);
    fclose(g);

    return 0;
}

void f5(_cvor* s) {
    int i;
    if (s == NULL)
        return;
    if (s->desno != NULL) {
        if (zbir(s->levo) < s->desno->vrednost)
            i = 1;
        else
            i = 0;
    } else i = 0;
    f5(s->levo);
    if (i == 1)
        printf("%d ", s->vrednost);
    f5(s->desno);

}

int zbir(_cvor* s) {
    int l, d;
    if (s == NULL)
        return 0;
    l = zbir(s->levo);
    d = zbir(s->desno);

    return l + d + s->vrednost;
}

//Septembar 2015

//ZADATAK 1

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int ima(char* s,char c);

int main(int argc,char** argv){
  int i,br,d;
  char c;

  if(argc!=4){
    printf("-1\n");
    exit(0);
  }

  c=argv[2][0];

  br=atoi(argv[3]);

  if(ima(argv[1],c)){
    d=strlen(argv[1]);
    for(i=0;i<d;i++)
      if(argv[1][i]==c){
        for(i=i+1;argv[1][i]!=c;i++)
          argv[1][i]+=br;
        break;
      }
    printf("%s\n",argv[1]);
  }else
    printf("%s\n",argv[1]);

  return 0;
}

int ima(char* s,char c){
  int i,d,br=0;
  d=strlen(s);
  for(i=0;i<d;i++)
    if(c==s[i]){
      br++;
      if(br>1)
        return 1;
    }
  return 0;
}

//ZADATAK 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KAR 50
#define MAX_SATI 24

typedef struct {
    int h, m;
    char ime[MAX_KAR];
} filmovi;

int poredi(const void* a, const void* b);

int main(int argc, char** argv) {
    FILE *f = fopen("bioskop.txt", "r");
    filmovi *niz = NULL, *pom = NULL;
    int i = 0, j, max_niz[MAX_SATI], max, ind_max;
    char c;

    if (f == NULL) {
        printf("-1\n");
        exit(0);
    }

    niz = (filmovi*) malloc(sizeof (filmovi));
    if (niz == NULL) {
        printf("-1\n");
        exit(0);
    }

    while (fscanf(f, "%s%d%c%d", niz[i].ime, &niz[i].h, &c, &niz[i].m) != EOF) {
        i++;
        pom = (filmovi*) realloc(niz, (i + 1) * sizeof (filmovi));
        if (pom == NULL) {
            printf("-1\n");
            free(niz);
            exit(0);
        } else niz = pom;
    }

    if (i == 0) {
        printf("-1\n");
        free(niz);
        exit(0);
    }

    qsort(niz, i, sizeof (filmovi), poredi);

    for (j = 0; j < 24; j++)
        max_niz[j] = 0;

    for (j = 0; j < i; j++)
        max_niz[niz[j].h]++;

    max = max_niz[0];
    ind_max = 0;
    for (j = 0; j < 24; j++)
        if (max_niz[j] > max) {
            max = max_niz[j];
            ind_max = j;
        }

    for (j = 0; j < i; j++)
        printf("%s\n", niz[j].ime);

    printf("%d:00\n", ind_max);

    free(niz);
    fclose(f);
    return 0;
}

int poredi(const void* a, const void* b) {
    filmovi* n = (filmovi*) a;
    filmovi* m = (filmovi*) b;

    if (n->h == m->h)
        return m->m - n->m;
    else
        return m->h - n->h;
}


//ZADATAK 3

//ZADATAK 4

//ZADATAK 5

