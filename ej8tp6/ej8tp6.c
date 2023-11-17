/*Realice una función que reciba como entrada un buffer de tipo char * y devuelva como
retorno la cantidad de líneas (\n) que hay en el mismo. Suponiendo que dicho buffer tiene la
forma de un archivo de texto: <<texto>>\n<<texto>>\n\n...\n\0*/
#include <stdio.h>

int contarLineas(const char *buffer) {
    int contador = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            contador++;
        }
    }

    return contador;
}

int main() {
    const char *texto = "hola\na\ntodos\nllego el\nleon\n...";
    int lineas = contarLineas(texto);

    printf("Numero de lineas en el buffer: %d\n", lineas);

    return 0;
}