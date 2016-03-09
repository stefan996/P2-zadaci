//Pod a
    /*
    #include <stdio.h>
    #include <stdlib.h>

    int main() {

        FILE *f = fopen("/home/luka/Desktop/Vezbanje/ulaz.txt", "r");
        FILE *g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");
        char c;

        if (f == NULL || g == NULL) {
            printf("-1");
            exit(0);
        }

        while (1) {
            c = fgetc(f);
            if (feof(f))
                break;
            fputc(c, g);
        }

        fclose(f);
        fclose(g);
        return 0;
    }*/
    //Pod b
    /*
    #include <stdio.h>
    #include <stdlib.h>
    #define max 21

    int main() {

        FILE *f = fopen("/home/luka/Desktop/Vezbanje/ulaz.txt", "r");
        FILE *g = fopen("/home/luka/Desktop/Vezbanje/izlaz.txt", "w");
        char linija[max];

        if (f == NULL || g == NULL) {
            printf("-1");
            exit(0);
        }

        while (fgets(linija, max, f) != NULL)
            fputs(linija, g);


        fclose(f);
        fclose(g);
        return 0;
    }*/
