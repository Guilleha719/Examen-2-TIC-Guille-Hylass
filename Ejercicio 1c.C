#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NPERSONAS 3

int main(void) {
    char *lista[NPERSONAS];
    char *pintercambio;
    char nombre_fecha[20]; // El formato es nombre_fecha
    char *nombre;
    char *fecha;
    char *dia, *mes, *anio;

    for (int i = 0; i < NPERSONAS; i++) {
        printf("Introduzca el nombre y la fecha de nacimiento de la persona %d (en formato 'nombre_fecha'): ", i + 1);
        scanf("%s", nombre_fecha);

        // Separar el nombre y la fecha usando strtok
        nombre = strtok(nombre_fecha, "_");
        fecha = strtok(NULL, "_");

        // Separar la fecha en día, mes y año
        dia = strtok(fecha, "/");
        mes = strtok(NULL, "/");
        anio = strtok(NULL, "/");

        // Calcular el año como un número entero
        int anio_int = atoi(anio);

        // Crear una cadena con el nombre y la fecha en el formato "año nombre"
        lista[i] = (char *)malloc(strlen(nombre) + strlen(anio) + 3); // +3 para el ' ', '\0', y el carácter nulo
        sprintf(lista[i], "%s %s", anio, nombre);
    }

    // Ordenar la lista por el año de nacimiento 
    for (int i = 0; i < NPERSONAS - 1; i++) {
        for (int j = 0; j < NPERSONAS - 1 - i; j++) {
            int anio1, anio2;
            sscanf(lista[j], "%d", &anio1);
            sscanf(lista[j + 1], "%d", &anio2);
            if (anio1 > anio2) {
                pintercambio = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = pintercambio;
            }
        }
    }

    // Imprimir la lista ordenada
    printf("\nListado ordenado por el año de nacimiento de los usuarios:\n");
    for (int i = 0; i < NPERSONAS; i++) {
        printf("%s\n", lista[i]);
    }

    // Liberar memoria guardada
    for (int i = 0; i < NPERSONAS; i++) {
        free(lista[i]);
    }

    return 0;
}
