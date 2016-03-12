#include<stdio.h>
#include"polinom.h"

#define MAX_KOE 100

int main(){
    
    int i,n,m,k,x,u,d,a[MAX_KOE],b[MAX_KOE],c[MAX_KOE];
    
    unos(a,&n);
    //printf("Uneti skalar:\n");
    //scanf("%d",&d);
    //unos(b,&m);
    //k=suma_polinoma(a,n,b,m,c);
    //mnoz_skalarom(a,n,d);
    //printf("Uneti vrednost x:\n");
    //scanf("%d",&x);
    //printf("%d",vr_poly(a,n,x));
    //u=mul_poly(a,n,b,m,c);
    ispis_polinoma(c,u);
    
    return 0;
}
