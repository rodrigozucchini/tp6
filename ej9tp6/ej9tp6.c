/*9. Realice una función que reciba como entrada un buffer de tipo char * (que representa el
contenido de un archivo de texto, como el indicado en el punto anterior) y un arreglo de tipo
char *[] (que representa un arreglo de punteros a cada una de las líneas de texto del buffer
char * pasado como primer argumento). La función deberá parsear el primer argumento e ir
creando dinámicamente líneas de texto a ser apuntadas por el segundo argumento. La función
no devuelve nada (void), sólo realiza este proceso y termina. Tener en cuenta que luego de la
ejecución de esta función, existirá en memoria el buffer pasado como primer argumento más
las nuevas líneas creadas.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parsearBuffer(const char *buffer, char *lineas[], int *numLineas) {
    *numLineas = 0;
    const char *inicio = buffer;

    while (*buffer) {
        if (*buffer == '\n') {
            lineas[*numLineas] = (char *)malloc(buffer - inicio + 1);
            strncpy(lineas[*numLineas], inicio, buffer - inicio);
            lineas[*numLineas][buffer - inicio] = '\0';
            (*numLineas)++;
            inicio = buffer + 1;
        }
        buffer++;
    }
}

int main() {
    const char *texto = "ASfafsafsaf\nfsafasfasf\nsad\nLingesdasdgsd 3\nLmmbnmbninea 3\nLtrytrtyinea 3\n";
    char *lineas[100]; // Puedes ajustar el tamaño según tus necesidades
    int numLineas = 0;

    parsearBuffer(texto, lineas, &numLineas);

    if (numLineas == 0) {
        printf("El buffer está vacío.\n");
    } else {
        for (int i = 0; i < numLineas; i++) {
            printf("Linea %d: %s\n", i + 1, lineas[i]);
            free(lineas[i]);
        }
    }

    return 0;
}