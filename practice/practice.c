/*
Un algoritmo para ingresar la cantidad de vendedores y lo que vendio cada uno
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int vendedor;
    int i = 0;
    printf("Queremos que ingreses la cantidad de vendedores que vamos a tener \n");
    scanf("%d", &vendedor);

    double *venta_por_vendedores = (double*) calloc(vendedor,sizeof(double));
    for (i = 0; i < vendedor; i++)
    {
        printf("Ingrese cuanto vendio el vendedor N %d\n",i+1);
        scanf("%lf", venta_por_vendedores+i);
    }
        for (i= 0; i < vendedor; i++)
    {
        printf("La cantidad que vende el vendedor Numero %d es de %lf\n", i+1, venta_por_vendedores[i]);
    }
    free(venta_por_vendedores);

    return 0;
}
