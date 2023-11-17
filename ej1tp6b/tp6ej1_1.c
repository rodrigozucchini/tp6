#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <consola.h>

//declaro prototipo de la funcion 
int main(int argc, char const *argv[])
{
    printf("Ingrese Caracteres:");
    char *p = devuelve_char();
    printf("Usted ingreso %s\n",p);
    free(p); // libero memoria qu asign devuelve_char();
    return 0;
}
