#include <stdio.h>
#include <string.h>
void productos(char productos[30], int demanda[5], int tiempo[5], int recursos[5], int recursos2[5])
{
    int len;
    for (int i = 0; i < 5; i++)
    {
        printf("ingrese el nombre del producto numero %d", i + 1);
        fflush(stdin);
        fgets(productos[i], 30, stdin);
        len = strlen(productos) - 1;
        productos[len] = '\0';
        printf("ingrese la demanda del producto\n");
        scanf("%d", &demanda[i]);
        printf("ingrese el tiempo que se demora en hacer el producto\n");
        scanf("%d", &tiempo[i]);
        printf(" ingrese la cantidad del recurso 1  necesarios\n");
        scanf("%d", &recursos[i]);
        printf(" ingrese la cantidad del recurso 2  necesarios\n");
        scanf("%d", &recursos2[i]);
    }
}
int tiempot(int demanda[5], int tiempo[5], int tiempot, int op)
{
    printf("seleccione el numero del producto para calcular el tiempo requerido\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        tiempot = demanda[0] * tiempo[0];
        break;
    case 2:
        tiempot = demanda[1] * tiempo[1];
        break;
    case 3:
        tiempot = demanda[2] * tiempo[2];
        break;
    case 4:
        tiempot = demanda[3] * tiempo[3];
        break;
    case 5:
        tiempot = demanda[4] * tiempo[4];
        break;
    default:
        break;
    }
    return tiempot;
}
void caso(int tiempot, int tiempo[5],int op,int t)
{
    
        t=t-tiempot;
        if (t>tiempot)
        {
            printf("el si se puede cumplir la demanda en el tiempo disponible\n");
        }else if (t<tiempot)
        {
            printf("no se puede cumplir la demanda en el tiempo disponible\n");
        }
        
}
void recursos(int recurso[5],int recursos2[5],int recursost,int recursost2){
    recursost=recursost-recurso;
}
