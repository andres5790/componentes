#include <stdio.h>
#include <string.h>
void producto(char productos[][30], int demanda[5], int tiempo[5], int recursos, int recursos2, int recursos3, int recursos4)
{
    int len, cont;
    for (int i = 0; i < 5; i++)
    {
        printf("ingrese el nombre del producto numero %d", i + 1);
        fflush(stdin);
        fgets(productos[i], 30, stdin);
        int len = strlen(productos[i]) - 1;
        productos[i][len] = '\0';
        printf("ingrese la demanda del producto\n");
        scanf("%d", &demanda[i]);
        printf("ingrese el tiempo que se demora en hacer el producto\n");
        scanf("%d", &tiempo[i]);
    }
    printf(" ingrese la cantidad de chips disponibles en el inventario\n");
    scanf("%d", &recursos);
    printf(" ingrese la cantidad de pantallas  disponibles en el inventario\n");
    scanf("%d", &recursos2);
    printf(" ingrese la cantidad de  microfonos  disponibles en el inventario\n");
    scanf("%d", &recursos3);
    printf(" ingrese la cantidad de altavoces disponibles en el inventario\n");
    scanf("%d", &recursos4);
    printf("se necesitan 4 chips, 1 pantalla,2 microfonos y 3 altavoces para el producto 1 con el nombre de %s\n", productos[0]);
    printf("se necesitan 3 chips, 2 pantalla,1 microfonos y 2 altavoces para el producto 2 con el nombre de %s\n", productos[1]);
    printf("se necesitan 5 chips, 4 pantalla,3 microfonos y 6 altavoces para el producto 3 con el nombre de %s\n", productos[2]);
    printf("se necesitan 7 chips, 3 pantalla,2 microfonos y 5 altavoces para el producto 4 con el nombre de %s\n", productos[3]);
    printf("se necesitan 2 chips, 5 pantalla,3 microfonos y 5 altavoces para el producto 5 con el nombre de %s\n", productos[4]);
}
int tiempot(int demanda[5], int tiempo[5], int op)
{
    int tiempot;
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
void caso(int tiempot, int tiempo[5], int op, int t, int s)
{
    s = 0;
    t = t - tiempot;
    if (t > tiempot)
    {
        printf("el si se puede cumplir la demanda en el tiempo disponible\n");
    }
    else if (t < tiempot)
    {
        printf("no se puede cumplir la demanda en el tiempo disponible\n");
    }
}
void comprobar(int recurso, int recursos2, int recursos3t, int recursos4t)
{
}
int recu(int *recurso, int *recursos2, int *recursos3t, int *recursos4t, int op, int demanda[5])
{
    switch (op)
    {
    case 1:
        recurso = 4 * demanda[0];
        recursos2 = 1 * demanda[0];
        recursos3t = 2 * demanda[0];
        recursos4t = 3 * demanda[0];
        break;
    case 2:
        recurso = 3 * demanda[1];
        recursos2 = 2 * demanda[1];
        recursos3t = 1 * demanda[1];
        recursos4t = 2 * demanda[1];
        break;
    case 3:
        recurso = 5 * demanda[2];
        recursos2 = 4 * demanda[2];
        recursos3t = 3 * demanda[2];
        recursos4t = 6 * demanda[2];
        break;
    case 4:
        recurso = 4 * demanda[3];
        recursos2 = 1 * demanda[3];
        recursos3t = 2 * demanda[3];
        recursos4t = 3 * demanda[3];
        break;
    default:
        break;
    }
    return recurso,recursos2,recursos3t,recursos4t;
}
