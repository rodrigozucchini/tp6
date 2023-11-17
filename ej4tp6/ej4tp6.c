/*Implemente una función que permita ingresar un conjunto de líneas de texto ingresadas por
teclado; la función recibe como argumento la cantidad máxima de líneas de texto a ingresar y
un arreglo de punteros a caracter ( char*[] ) que contendrá todas las líneas ingresadas por
teclado y asignadas dinámicamente (por lo tanto, las otras funciones que la utilicen serán
responsables de liberar la memoria de este arreglo una vez que el mismo ya no se requiera (
free())) a su vez, reutilizará, usará la función del punto 2. La función devolverá el número
de lineas efectivamente ingresadas (un número menor o igual al máximo de líneas a ingresar).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int devuelve_char4();

int main(int argc, char const *argv[])
{
    int maximoLineasXUsuario;
    printf("Ingrese la cantidad de lineas que quiere utilizar\n");
    scanf("%d", &maximoLineasXUsuario); // pido maximo
    printf("Su programa usara %d lineas \n",maximoLineasXUsuario);
    char **lineas; // inicializo
    int numeroLineasIngresadas = devuelve_char4(&lineas, maximoLineasXUsuario); // en munero lineas ingresadas llamo a la funcion devuelvo_char4
    free(lineas); // Liberar memoria del arreglo de punteros
    return 0;
}

int devuelve_char4(char ***arregloLineas, int maximoLineasXUsuario) { // traigo argumentos
    char lineas[100]; 
    *arregloLineas = (char **)malloc(maximoLineasXUsuario * sizeof(char *));  //asigno dinámicamente memoria para un arreglo de punteros a caracteres llamado arregloLineas

    printf("Ingrese lineas de texto (Presione Enter para ingresar lineas diferentes):\n"); 


    for (int nLineas = 0; nLineas <= maximoLineasXUsuario && fgets(lineas, sizeof(lineas), stdin); nLineas++) {
        (*arregloLineas)[nLineas] = strdup(lineas);

    }

    for(int i = 1; i <= maximoLineasXUsuario; i++) {
        printf("En la linea %d usted escribio [%s] \n", i, (*arregloLineas)[i]);
    }
    free(arregloLineas);
    return 0; 
}
