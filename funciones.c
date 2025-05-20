#include <stdio.h>
#include <string.h>
int producto(char productos[][30],  int tiempo[5])
{
    int len, cont;
    for (int i = 0; i < 5; i++)
    {
        printf("ingrese el nombre del producto numero %d\n", i + 1);
        fflush(stdin);
        fgets(productos[i], 30, stdin);
        int len = strlen(productos[i]) - 1;
        productos[i][len] = '\0';
        printf("ingrese el tiempo que se demora en hacer el producto\n");
        scanf("%d", &tiempo[i]);
        while (tiempo[i] <= 0)
        {
            printf("Error: el tiempo debe ser un número entero positivo\n");
            printf("Ingrese el tiempo nuevamente: ");
            scanf("%d", &tiempo[i]);
        }
    }
    
}
int tiempot(int demanda, int tiempo[5], int op)
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
void caso(int tiempot, int t, int *s)
{
    *s = 0;

    if (t > tiempot)
    {
        printf(" si se puede cumplir la demanda en el tiempo disponible\n");
        *s = 1;
    }
    else if (t < tiempot)
    {
        printf("no se puede cumplir la demanda en el tiempo disponible\n");
    }
}
void comprobar(int *recurso, int *recursos2, int *recursos3t, int *recursos4t, int *r1, int *r2, int *r3, int *r4, int *n)
{
    *n = 0;

    if (*recurso >= *r1)
    {
        *n = *n + 1;
    }
    if (*recursos2 >= *r2)
    {
        *n = *n + 1;
    }
    if (*recursos3t >= *r3)
    {
        *n = *n + 1;
    }
    if (*recursos4t >= *r4)
    {
        *n = *n + 1;
    }
    if (n < 4)
    {
        printf("no se puede cumplir la demanda ya que no hay suficientes recursos\n");
    }
}
void recu(int op, int demanda[5], int *recurso, int *recursos2, int *recursos3t, int *recursos4t)
{
    printf("Seleccione el producto (1-5): ");
    scanf("%d", &op);
    *recurso = 0;
    *recursos2 = 0;
    *recursos3t = 0;
    *recursos4t = 0;
    switch (op)
    {
    case 1:
        *recurso = 4 * demanda[0];
        *recursos2 = 1 * demanda[0];
        *recursos3t = 2 * demanda[0];
        *recursos4t = 3 * demanda[0];
        break;
    case 2:
        *recurso = 3 * demanda[1];
        *recursos2 = 2 * demanda[1];
        *recursos3t = 1 * demanda[1];
        *recursos4t = 2 * demanda[1];
        break;
    case 3:
        *recurso = 5 * demanda[2];
        *recursos2 = 4 * demanda[2];
        *recursos3t = 3 * demanda[2];
        *recursos4t = 6 * demanda[2];
        break;
    case 4:
        *recurso = 7 * demanda[3];
        *recursos2 = 3 * demanda[3];
        *recursos3t = 2 * demanda[3];
        *recursos4t = 5 * demanda[3];
        break;
    case 5:
        *recurso = 2 * demanda[4];
        *recursos2 = 5 * demanda[4];
        *recursos3t = 3 * demanda[4];
        *recursos4t = 5 * demanda[4];
        break;
    default:
        break;
    }
}
int menu(int opc)
{
    printf("selecciones una opcion\n");
    printf("1.ingresar  nombre producto,tiempo\n");
    printf("1.ver si se puede cumplir con el trabajo\n");
    printf("2.editar informacion de producto\n");
    printf("3.eliminar producto del catalogo\n");
    printf("4.ver stock actual y tiempo disponible restante\n");
    printf("5.agregar un nuevo stock\n");
    printf("6.salir\n");
}
void resta(int *recurso, int *recursos2, int *recursos3t, int *recursos4t, int *r1, int *r2, int *r3, int *r4)
{
    *recurso = *recurso - *r1;
    *recursos2 = *recursos2 - *r2;
    *recursos3t = *recursos3t - *r3;
    *recursos4t = *recursos4t - *r4;
}
void restat(int tiempot, int *t)
{
    *t = *t - tiempot;
}
void cambio(char productos[][30], int demanda[], int tiempo[])
{
    char buscar[30];
    int len, encontrado = 0;
    fflush(stdin);

    printf("Ingrese el nombre del producto que desea editar: ");
    fgets(buscar, 30, stdin);
    len = strlen(buscar);
    if (buscar[len - 1] == '\n')
        buscar[len - 1] = '\0';

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(productos[i], buscar) == 0)
        {
            printf("Producto encontrado: %s\n", productos[i]);
            printf("Ingrese el nuevo nombre del producto: ");
            fflush(stdin);
            fgets(productos[i], 30, stdin);
            len = strlen(productos[i]);
            if (productos[i][len - 1] == '\n')
                productos[i][len - 1] = '\0';
            printf("ingrese la nueva demanda\n");
            scanf("%d", &demanda[i]);
            while (demanda[i] <= 0)
            {
                printf("Error: la demanda debe ser un número entero positivo\n");
                printf("Ingrese la demanda nuevamente: ");
                scanf("%d", &demanda[i]);
            }
            printf("Ingrese el nuevo tiempo de produccion del producto: ");
            scanf("%d", &tiempo[i]);
            while (tiempo[i] <= 0)
            {
                printf("Error: el tiempo debe ser un número entero positivo\n");
                printf("Ingrese el tiempo nuevamente: ");
                scanf("%d", &tiempo[i]);
            }
            printf("Nombre actualizado: %s\n", productos[i]);
            printf("Demanda actualizada: %d\n", demanda[i]);
            printf("Tiempo actualizado: %d\n", tiempo[i]);

            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Producto no encontrado en el catálogo.\n");
    }
}
void agregar(int op, int cantidad, int *recursos, int *recursos2, int *recursos3, int *recursos4)
{
    printf("seleccione que recurso desea agregar\n");
    scanf("%d", &op);
    printf("seleccione la cantidad a agregar\n");
    scanf("%d", &cantidad);
    while (cantidad <= 0)
    {
        printf("Error: la cantidad debe ser un número entero positivo\n");
        printf("Ingrese  la cantidad nuevamente: ");
        scanf("%d", &cantidad);
    }
    switch (op)
    {
    case 1:
        *recursos = *recursos + cantidad;
        break;
    case 2:
        *recursos2 = *recursos2 + cantidad;
        break;
    case 3:
        *recursos3 = *recursos3 + cantidad;
        break;
    case 4:
        *recursos4 = *recursos4 + cantidad;
        break;
    default:
        break;
    }
}
void eliminar(char productos[][30], int demanda[5], int tiempo[5])
{
    char buscar[30];
    int len, encontrado = 0, i;
    fflush(stdin);

    printf("Ingrese el nombre del producto que desea eliminar: ");
    fgets(buscar, 30, stdin);
    len = strlen(buscar);
    if (buscar[len - 1] == '\n')
        buscar[len - 1] = '\0';

    for (i = 0; i < 5; i++)
    {
        if (strcmp(productos[i], buscar) == 0)
        {
            encontrado = 1;
            break;
        }
    }
    if (encontrado)
    {
        strcpy(productos[i], "");
        demanda[i] = 0;
        tiempo[i] = 0;
        printf("Producto eliminado con éxito\n");
    }
    else
    {
        printf("Producto no encontrado\n");
    }
}
int menu2(int opc)
{
    printf("selecciones una opcion\n");
    printf("1.ingresar nombres, tiempoque se demora en el producto\n");
    printf("2.ingresar recursos disponibles en la fabrica\n");
    printf("3.Calcular un pedido\n");
}
int ingresor(int *recursos, int *recursos2, int *recursos3, int *recursos4,char productos[][30]){
    printf(" ingrese la cantidad de chips disponibles en el inventario\n");
    scanf("%d", recursos);
    while (*recursos <= 0)
    {
        printf("Ingrese los recursos nuevamente: ");
        scanf("%d", recursos);
    }
    printf(" ingrese la cantidad de pantallas  disponibles en el inventario\n");
    scanf("%d", recursos2);
    while (*recursos2 <= 0)
    {
        printf("Ingrese los recursos nuevamente: ");
        scanf("%d", recursos2);
    }
    printf(" ingrese la cantidad de  microfonos  disponibles en el inventario\n");
    scanf("%d", recursos3);
    while (*recursos3 <= 0)
    {
        printf("Ingrese los recursos nuevamente: ");
        scanf("%d", recursos3);
    }
    printf(" ingrese la cantidad de altavoces disponibles en el inventario\n");
    scanf("%d", recursos4);
    while (*recursos4 <= 0)
    {
        printf("Ingrese los recursos nuevamente: ");
        scanf("%d", recursos4);
    }
    printf("se necesitan 4 chips, 1 pantalla,2 microfonos y 3 altavoces para el producto 1 con el nombre de %s\n", productos[0]);
    printf("se necesitan 3 chips, 2 pantalla,1 microfonos y 2 altavoces para el producto 2 con el nombre de %s\n", productos[1]);
    printf("se necesitan 5 chips, 4 pantalla,3 microfonos y 6 altavoces para el producto 3 con el nombre de %s\n", productos[2]);
    printf("se necesitan 7 chips, 3 pantalla,2 microfonos y 5 altavoces para el producto 4 con el nombre de %s\n", productos[3]);
    printf("se necesitan 2 chips, 5 pantalla,3 microfonos y 5 altavoces para el producto 5 con el nombre de %s\n", productos[4]);
    

}
    
