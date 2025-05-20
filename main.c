#include <stdio.h>
#include <string.h>
#include "librero.h"
int main(int argc, char *argv[])
{
    char productos[5][30];
    int demanda, tiempo[5], recursos, recursos2, recursos3, recursos4, op, tr1, tr2, tr3, tr4, t, tiempos, opc, s, n, cantidad, res;
    do
    {
        menu2(opc);
        scanf("%d",&opc);
        switch (opc)
        {
        case 1:
               producto(productos, tiempo, &recursos, &recursos2, &recursos3, &recursos4);
            break;
        case 2:
            ingresor(recursos, recursos2, recursos3, recursos4,productos);
             break;
        case 3:
        do
        {
            printf("Desea realizar un pedido? Ingrese 1 para repetir, cualquier otro número para salir:\n");
            scanf("%d", &res);
            if (res == 1)
            printf("ingrese la demanda del producto\n");
            scanf("%d",&demanda);
            {
                t = tiempot(demanda, tiempo, op);
                printf("el tiempo necesario para cumplir con la demanda es de %d\n", t);
                recu(op, demanda, &tr1, &tr2, &tr3, &tr4);
                printf("el total de chips que necesita es de %d\n", tr1);
                printf("el total de pantallas que necesita es de %d\n", tr2);
                printf("el total de microfonos que necesita es de %d\n", tr3);
                printf("el total de altavoces que necesita es de %d\n", tr4);
    
                do
                {
                    menu(opc);
                    scanf("%d", &opc);
                    switch (opc)
                    {
                    case 1:
                        caso(t, tiempos, &s);
                        comprobar(&recursos, &recursos2, &recursos3, &recursos4, &tr1, &tr2, &tr3, &tr4, &n);
                        printf("Valor de s: %d, Valor de n: %d\n", s, n);
                        if (s == 1 && n == 4)
                        {
                            printf("si se puede realizar el pedido ya que existe suficiente demanda\n");
                            resta(&recursos, &recursos2, &recursos3, &recursos4, &tr1, &tr2, &tr3, &tr4);
                            restat(t, &tiempos);
                        }
                        else
                        {
                            printf("no se puede realizar el pedido\n");
                        }
    
                        break;
                    case 2:
                        cambio(productos, demanda, tiempo);
    
                        t = tiempot(demanda, tiempo, op);
                        printf("el tiempo necesario para cumplir con la demanda es de %d\n", t);
                        recu(op, demanda, &tr1, &tr2, &tr3, &tr4);
                        printf("el total de chips que necesita es de %d\n", tr1);
                        printf("el total de pantallas que necesita es de %d\n", tr2);
                        printf("el total de microfonos que necesita es de %d\n", tr3);
                        printf("el total de altavoces que necesita es de %d\n", tr4);
                        break;
                    case 3:
                        eliminar(productos, demanda, tiempo);
                        break;
                    case 4:
                        printf("el stock de chips actual es del %d\n", recursos);
                        printf("el stock de pantallas actuales es de %d\n", recursos2);
                        printf("el stock de microfonos actuales es de %d\n", recursos3);
                        printf("el stock de altavoces actuales es de %d\n", recursos4);
                        printf("el tiempo restante es de %d\n", tiempos);
                        break;
                    case 5:
                        agregar(op, cantidad, &recursos, &recursos2, &recursos3, &recursos4);
                        break;
                    default:
                        break;
                    }
                } while (opc != 6);
            }
    
        } while (res == 1);
        default:
            break;
        }
    } while (opc);
    
  

    return 0;
}
