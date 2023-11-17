#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <consola.h>

char * devuelve_char() {
    char cadena_texto[21];
    int i = 0;
    char c = 0;
    while ((c = getchar()) != '\n' && i < 20) {
        cadena_texto[i] = c;
        i++;
    }
    cadena_texto[i] = '\0';

    return strdup(cadena_texto); // asigna memoria y copia cadena_txto en la memoria asignada
}

//Este es con memoria dinamica, sin limites a la cantidad de caracteres a ingresar
//Devuelve un puntero al inicio de los caracteres ingresados, NULL si es error
char * devuelve_char2() {
    int bloque = 32; //ajustar el tamanio de bloque
    int nbloque = 1; // numero total de bloques asignados
    long n = 0; // indica el numero de caracteres ingresados 0..N-1
    char c = 0; // untimo caracter ingresado por teclado
    char *pinicio= (char*) malloc(nbloque*bloque);

    while ((c = getchar()) != '\n') {
        if(n>0 && (n % bloque) == 0) {
            //si n es multiplo de bloque, significa que se lleno el bloque 
            // necesito asignar un bloque mas

            printf("n vale %li agrego bloque %d de %d bytes \n",n ,nbloque ,bloque);
            pinicio = (char *) realloc(pinicio, nbloque*bloque);
                        nbloque++;
            if(pinicio == NULL) return NULL;
        }
        * (pinicio+n) = c;
        n++;
    }
    *(pinicio+n) = '\0';

    return pinicio;
}