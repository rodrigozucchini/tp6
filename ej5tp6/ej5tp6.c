/*Implemente una función que permita saber: a) ¿cuál fué la cadena de caracteres más corta
ingresada? b) ¿cuál fue la cadena más larga? c) ¿cuál es la posición (en el arreglo de
cadenas) de la cadena más corta? d) ¿cuál es la posición de la cadena más larga? . La
función recibirá como argumentos de entrada un arreglo de punteros a cadenas ( char*[] ) , es
decir, el arreglo usado como argumento de la función del punto 4; recibirá también la cantidad
máxima de cadenas ingresadas; como no es posible devolver más de un valor, entonces la
función no devolverá nada ( void ). Entonces: ¿Cómo podemos hacer para devolver las
respuestas a), b), c) ,d) ? . Discútalo con el profesor.*/

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

    free(arregloLineas);
    return 0; 
}