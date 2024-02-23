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
    char nombre_buscar[20];

    // Ingreso de datos de las personas
    for (int i = 0; i < NPERSONAS; i++) {
        printf("Introduzca el nombre y la fecha de nacimiento de la persona %d (en formato 'nombre_fecha'): ", i + 1);
        scanf("%s", nombre_fecha);

        // Separar el nombre y la fecha usando strtok
        nombre = strtok(nombre_fecha, "_");
        fecha = strtok(NULL, "_");

        // Separar la fecha en día/mes/año
        dia = strtok(fecha, "/");
        mes = strtok(NULL, "/");
        anio = strtok(NULL, "/");

        // Calcular el año como un número entero
        int anio_int = atoi(anio);

        // Crear una cadena con el nombre y la fecha en el formato "nombre anio"
        lista[i] = (char *)malloc(strlen(nombre) + strlen(anio) + 3); // +3 para el ' ', '\0', y el carácter nulo
        sprintf(lista[i], "%s %s", nombre, anio);
    }

    // Imprimir la lista de personas y sus fechas de nacimiento
    printf("\nLista de personas y sus fechas de nacimiento:\n");
    for (int i = 0; i < NPERSONAS; i++) {
        printf("%s\n", lista[i]);
    }

    // Solicitar el nombre de la persona a buscar
    printf("\nIngrese el nombre de la persona que desea buscar: ");
    scanf("%s", nombre_buscar);

    // Buscar la persona en la lista
    char *fecha_nacimiento = NULL;
    for (int i = 0; i < NPERSONAS; i++) {
        if (strstr(lista[i], nombre_buscar) != NULL) {
            fecha_nacimiento = strtok(lista[i], " "); // Extraer la fecha de nacimiento
            break;
        }
    }

    // Mostrar la fecha de nacimiento de la persona encontrada
    if (fecha_nacimiento != NULL) {
        printf("La fecha de nacimiento de %s es %s.\n", nombre_buscar, fecha_nacimiento);
    } else {
        printf("La persona %s no fue encontrada en la lista.\n", nombre_buscar);
    }

    // Liberar memoria guardada
    for (int i = 0; i < NPERSONAS; i++) {
        free(lista[i]);
    }

    return 0;
}
