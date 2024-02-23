#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NPERSONAS 3

int main(void) {
    char *lista[NPERSONAS];
    char *pintercambio;
    char nombre_fecha[20]; //El formato es nombre_fecha
    char *nombre;
    char *fecha;

    for (int i = 0; i < NPERSONAS; i++) {
        printf("Porfavor escriba el nombre y la fecha de nacimiento de la persona %d (en este estilo 'nombre_fecha(xx/xx/xxxx)'= ", i + 1);
        scanf("%s", nombre_fecha);

        // Separamos el nombre y la fecha usando strtok
        nombre = strtok(nombre_fecha, "_");
        fecha = strtok(NULL, "_");

        //Ponemos memoria para el nombre y copiarlo
        lista[i] = (char *)malloc(strlen(nombre) + 1);
        strcpy(lista[i], nombre);

        // Poner la fecha al final del nombre
        lista[i] = (char *)realloc(lista[i], strlen(lista[i]) + strlen(fecha) + 2); // +2 para el '_' y el carácter nulo
        strcat(lista[i], "_");
        strcat(lista[i], fecha);
    }

    // Imprimir la lista
    printf("\nListado de nombres y de las fechas de nacimiento=\n");
    for (int i = 0; i < NPERSONAS; i++) {
        printf("%s\n", lista[i]);
    }

    // Liberar memoria guardada
    for (int i = 0; i < NPERSONAS; i++) {
        free(lista[i]);
    }

    return 0;
}
