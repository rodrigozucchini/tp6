/*Implemente otra función para el ingreso de caracteres por teclado, usando la misma técnica
que en el punto 1, pero esta vez se le indica a la función un máximo de caracteres a ingresar,
si el usuario ingresa más caracteres, éstos serán ignorados. Ante cualquier error, se deberá
devolver NULL.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * devuelve_char3();

int main(int argc, char const *argv[])
{
    char *p = devuelve_char3();
    printf("Usted ingreso %s \n",p);
    free(p); // libero memoria que asigne devuelve_char3();
    return 0;
}

char * devuelve_char3() {
    int n; // cantidad de caracteres a ingresar
    char c = 0;
    int i = 0;
    printf("ingrese la cantidad de caracteres a ingresar\n");
    scanf("%d", &n);
    getchar();
    char cadena_texto[n+1];
    printf("Su cadena de texto tendra %d caracteres + el NULL FINAL\n", n);

    if (cadena_texto == NULL) {
        return NULL; // Devolver NULL en caso de error de asignación de memoria
    }

    while((c = getchar()) != '\n' && i < n) {
        cadena_texto[i] = c;
         i++;
    }
    cadena_texto[i] = '\0';

    return strdup(cadena_texto);
}
