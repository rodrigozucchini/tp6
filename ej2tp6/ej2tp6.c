/*Modifique la función anterior, de forma tal que ésta ya no tenga ningún límite en cuanto a la
cantidad de caracteres ingresados por teclado. Para ello se requiere solicitar memoria
dinámica (malloc(), realloc(), calloc() ) a medida que sea necesario, para dar
lugar a más cantidad de caracteres a ingresar ( realloc() ), hasta que termine el ingreso por
teclado. No pida memoria "de a 1 caracter", ello sería muy ineficiente, hágalo "de a bloques"
de caracteres múltiplo de potencias de 2, ejemplo: 256, 512, 1024, etc. Ante cualquier error, se
deberá devolver NULL.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <consola.h>

int main(int argc, char const *argv[])
{
    printf("Ingrese Caracteres:");
    char *p = devuelve_char2();
    printf("Usted ingreso %s \n",p);
    free(p); // libero memoria que asigne a devuelve_char2();
    return 0;
}
