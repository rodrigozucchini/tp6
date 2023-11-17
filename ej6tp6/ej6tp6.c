/*
Reutilice las funciones anteriores en un programa que permita el ingreso de líneas de texto por
teclado, muestre en pantalla la línea más pequeña ingresada y la línea más larga ingresada.
Pruebe su correcto funcionamiento. Libere la memoria utilizada de forma correcta, haga n
repeticiones ( for() ) de esto para asegurarse de no tener problemas de memoria.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cadena_de_caracteres();

int main(int argc, char const *argv[])
{
    int maximoLineasXUsuario;
    printf("Ingrese la cantidad de lineas que quiere utilizar\n");
    scanf("%d", &maximoLineasXUsuario); // pido maximo
    printf("Su programa usara %d lineas \n",maximoLineasXUsuario);
    char **lineas; // inicializo
    int numeroLineasIngresadas = cadena_de_caracteres(&lineas, maximoLineasXUsuario); // en munero lineas ingresadas llamo a la funcion devuelvo_char4
    free(lineas); // Liberar memoria del arreglo de punteros
    return 0;
}

int cadena_de_caracteres(char ***arregloLineas, int maximoLineasXUsuario) { 
    char lineas[100]; 
    *arregloLineas = (char **)malloc(maximoLineasXUsuario * sizeof(char *));  //asigno dinámicamente memoria para un arreglo de punteros a caracteres llamado arregloLineas
	int pmen = 0, pmay = 0, lmen = 100, lmay = 0;
    int longitud[100];

    printf("Ingrese lineas de texto (Presione Enter para ingresar lineas diferentes):\n"); 

    for (int nLineas = 0; nLineas <= maximoLineasXUsuario && fgets(lineas, sizeof(lineas), stdin); nLineas++) {
        (*arregloLineas)[nLineas] = strdup(lineas);
        longitud[nLineas] = strlen((*arregloLineas)[nLineas])-1;
    }


    for(int i = 1; i <= maximoLineasXUsuario; i++) {
        
        if (longitud[i] > lmay) {
            lmay = longitud[i];
            pmay = i;
        }

        if (longitud[i] < lmen) {
            lmen = longitud[i];
            pmen = i;
        }
    }

    for(int i = 1; i <= maximoLineasXUsuario; i++) {
        printf("En la linea %d usted escribio [%s] \n", i, (*arregloLineas)[i]);
    }

    if(maximoLineasXUsuario == 0) {
        printf("La cadena mas corta tiene %d caracteres\n",lmen-100);
    } else {
        printf("La cadena mas corta tiene %d caracteres\n",lmen);
    }

    printf("La direccion de la cadena mas corta es la %d \n",pmen);
    printf("La cadena mas larga tiene %d caracteres\n",lmay);
    printf("La direccion de la cadena mas larga es la %d \n",pmay);


    for (int i = 0; i < maximoLineasXUsuario; i++) {
        free((*arregloLineas)[i]);
    }

    free(*arregloLineas);


    return 0; 
}