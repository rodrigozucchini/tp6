/*Realice un simple programa para desplegar un menu de opciones en la consola. Luego
modifíquelo para convertirlo en un “menú genérico”, reusable en sus distintos proyectos. Se
puede “encapsular” todo el menú de la siguiente forma: crear la función int menu(char
*titulo,char *opciones[]) esta función devuelve la opción elegida por el usuario, “encapsula”
toda la lógica del menú (iteración, mensajes de error, títulos, ingresos de datos, etc.), recibe
como argumento el título del menú y un arreglo de tipo char * que contendrá las opciones del
menú (sólo las opciones, sin los números, sin la opción “Salir”, este arreglo termina con NULL).
La forma de uso sería:
char *titulo = “Menu de Prueba”;
char *arrayOpciones[] = { “Opción 1”, “Opción 2”, “Opción 3”, NULL };
int opcion;
opcion = menu(titulo,arrayOpciones);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu();

int main(int argc, char const *argv[])
{
    char *titulo = “Menu de Prueba”;
    char *arrayOpciones[] = { “Opción 1”, “Opción 2”, “Opción 3”, NULL };
    int opcion;

    opcion = menu(titulo,arrayOpciones);
    return 0;
}

int menu() { 

    return 0; 
}