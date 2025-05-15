#include <stdio.h>
#include <string.h>
#include "librero.h"
int main (int argc, char *argv[]) {
    char productos[5][30];
    int demanda[5], tiempo[5],  recursos,  recursos2,recuros3,recursos4,op,t;
    producto(productos,demanda,tiempo,recursos,recursos2,recuros3,recursos4);
    t=tiempot(demanda,tiempo,op);
    printf("el tiempo necesario para cumplir con la demanda es de %d",t);
    recu(recursos,  recursos2,recuros3,recursos4,op,demanda);
    
    return 0;
}