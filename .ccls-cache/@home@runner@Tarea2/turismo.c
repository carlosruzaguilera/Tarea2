#include "turismo.h"
#include <stdio.h>

void registrarPuntoInteres(PuntoInteres *puntosInteres, int *contadorPuntos) {
    printf("Ingrese el nombre del punto de interés: ");
    scanf("%99s", puntosInteres[*contadorPuntos].nombre);
    printf("Ingrese el tipo del punto de interés: ");
    scanf("%99s", puntosInteres[*contadorPuntos].tipo);
    printf("Ingrese la dirección del punto de interés: ");
    scanf("%99s", puntosInteres[*contadorPuntos].direccion);
    printf("Ingrese el horario del punto de interés: ");
    scanf("%99s", puntosInteres[*contadorPuntos].horario);
    printf("Ingrese la descripción del punto de interés: ");
    scanf("%99s", puntosInteres[*contadorPuntos].descripcion);
    (*contadorPuntos)++;
}

void mostrarPuntoInteres(PuntoInteres *puntosInteres, int contadorPuntos, char *nombre) {
    for(int i = 0; i < contadorPuntos; i++) {
        if(strcmp(puntosInteres[i].nombre, nombre) == 0) {
            printf("Nombre: %s\n", puntosInteres[i].nombre);
            printf("Tipo: %s\n", puntosInteres[i].tipo);
            printf("Dirección: %s\n", puntosInteres[i].direccion);
            printf("Horario: %s\n", puntosInteres[i].horario);
            printf("Descripción: %s\n", puntosInteres[i].descripcion);
            return;
        }
    }
    printf("No se encontró el punto de interés con el nombre %s.\n", nombre);
}

void eliminarPuntoInteres(PuntoInteres *puntosInteres, int *contadorPuntos, char *nombre) {
    int index = -1;
    for(int i = 0; i < *contadorPuntos; i++) {
        if(strcmp(puntosInteres[i].nombre, nombre) == 0) {
            index = i;
            break;
        }
    }
    if(index != -1) {
        for(int i = index; i < (*contadorPuntos) - 1; i++) {
            puntosInteres[i] = puntosInteres[i + 1];
        }
        (*contadorPuntos)--;
        printf("Punto de interés eliminado exitosamente.\n");
    } else {
        printf("No se encontró el punto de interés con el nombre %s.\n", nombre);
    }
}

void registrarTurista(Turista *turistas, int *contadorTuristas) {
    printf("Ingrese el pasaporte del turista: ");
    scanf("%99s", turistas[*contadorTuristas].pasaporte);
    printf("Ingrese el nombre del turista: ");
    scanf("%99s", turistas[*contadorTuristas].nombre);
    printf("Ingrese el país del turista: ");
    scanf("%99s", turistas[*contadorTuristas].pais);
    (*contadorTuristas)++;
}

void agregarLugarFavorito(Turista *turistas, int contadorTuristas, char *pasaporte, char *nombreLugar) {
    for(int i = 0; i < contadorTuristas; i++) {
        if(strcmp(turistas[i].pasaporte, pasaporte) == 0) {
            strcat(turistas[i].lugaresFavoritos, nombreLugar);
            strcat(turistas[i].lugaresFavoritos, ";");
            printf("Lugar favorito agregado exitosamente.\n");
            return;
        }
    }
    printf("No se encontró el turista con el pasaporte %s.\n", pasaporte);
}

void mostrarTuristasPorPais(Turista *turistas, int contadorTuristas, char *pais) {
    int encontrado = 0;
    for(int i = 0; i < contadorTuristas; i++) {
        if(strcmp(turistas[i].pais, pais) == 0) {
            printf("Pasaporte: %s\n", turistas[i].pasaporte);
            printf("Nombre: %s\n", turistas[i].nombre);
            printf("Lugares Favoritos: %s\n", turistas[i].lugaresFavoritos);
            encontrado = 1;
        }
    }
    if(!encontrado) {
        printf("No se encontraron turistas del país %s.\n", pais);
    }
}

void mostrarPuntosInteresPorTipo(PuntoInteres *puntosInteres, int contadorPuntos, char *tipo) {
    int encontrado = 0;
    for(int i = 0; i < contadorPuntos; i++) {
        if(strcmp(puntosInteres[i].tipo, tipo) == 0) {
            printf("Nombre: %s\n", puntosInteres[i].nombre);
            printf("Dirección: %s\n", puntosInteres[i].direccion);
            printf("Horario: %s\n", puntosInteres[i].horario);
            printf("Descripción: %s\n", puntosInteres[i].descripcion);
            encontrado = 1;
        }
    }
    if(!encontrado) {
        printf("No se encontraron puntos de interés del tipo %s.\n", tipo);
    }
}

void importarDesdeCSV(PuntoInteres *puntosInteres, int *contadorPuntos, char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if(archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombreArchivo);
        return;
    }
    while(fscanf(archivo, "%99[^,],%99[^,],%99[^,],%99[^,],%99[^\n]\n", puntosInteres[*contadorPuntos].nombre, puntosInteres[*contadorPuntos].tipo, puntosInteres[*contadorPuntos].direccion, puntosInteres[*contadorPuntos].horario, puntosInteres[*contadorPuntos].descripcion) == 5) {
        (*contadorPuntos)++;
    }
    fclose(archivo);
    printf("Datos importados exitosamente desde %s.\n", nombreArchivo);
}

void exportarACSV(PuntoInteres *puntosInteres, int contadorPuntos, char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "w");
    if(archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombreArchivo);
        return;
    }
    for(int i = 0; i < contadorPuntos; i++) {
        fprintf(archivo, "%s,%s,%s,%s,%s\n", puntosInteres[i].nombre, puntosInteres[i].tipo, puntosInteres[i].direccion, puntosInteres[i].horario, puntosInteres[i].descripcion);
    }
    fclose(archivo);
    printf("Datos exportados exitosamente a %s.\n", nombreArchivo);
}

