#define MAX_DUZ 1000

typedef struct {
    int duz;
    int niz[MAX_DUZ];
} VelikiBroj;

VelikiBroj ucitaj_broj(FILE* f);
void ispis(VelikiBroj b, FILE* g);
int poredi(VelikiBroj a, VelikiBroj b);
VelikiBroj saberi(VelikiBroj a, VelikiBroj b);
VelikiBroj mnozi_skalarom(VelikiBroj a, int x);
VelikiBroj mnozi_dva(VelikiBroj a, VelikiBroj b);
