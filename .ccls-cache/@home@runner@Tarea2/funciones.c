#include "funciones.h"
#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void registrarPuntoInteres(HashMap* map, char* nombre, char* tipo, char* direccion, char* horario, char* descripcion) {
    // Crear un nuevo punto de interés
    PuntoInteres* nuevoPunto = (PuntoInteres*)malloc(sizeof(PuntoInteres));
    if (nuevoPunto == NULL) {
        // Manejar error de asignación de memoria
        printf("Error al asignar memoria para nuevo punto de interés.\n");
        return;
    }

    // Copiar los datos al nuevo punto de interés
    strncpy(nuevoPunto->nombre, nombre, 100);
    strncpy(nuevoPunto->tipo, tipo, 100);
    strncpy(nuevoPunto->direccion, direccion, 100);
    strncpy(nuevoPunto->horario, horario, 100);
    strncpy(nuevoPunto->descripcion, descripcion, 100);

    // Insertar el nuevo punto de interés en el hashmap
    insertMap(map, nuevoPunto->nombre, nuevoPunto);
}

void mostrarDatosPuntoInteres(HashMap* map, char* nombre) {
    // Buscar el punto de interés en el hashmap
    PuntoInteres* punto = (PuntoInteres*)get(map, nombre);
    if (punto == NULL) {
        // Si no se encuentra el punto de interés, mostrar un mensaje de error
        printf("No se encontró el punto de interés con nombre: %s\n", nombre);
        return;
    }

    // Imprimir los datos del punto de interés
    printf("Nombre: %s\n", punto->nombre);
    printf("Tipo: %s\n", punto->tipo);
    printf("Dirección: %s\n", punto->direccion);
    printf("Horario: %s\n", punto->horario);
    printf("Descripción: %s\n", punto->descripcion);
}

void eliminarPuntoInteres(HashMap* map, char* nombre) {
    // Buscar el punto de interés en el hashmap
    PuntoInteres* punto = (PuntoInteres*)get(map, nombre);
    if (punto == NULL) {
        // Si no se encuentra el punto de interés, mostrar un mensaje de error
        printf("No se encontró el punto de interés con nombre: %s\n", nombre);
        return;
    }

    // Eliminar el punto de interés del hashmap
    eraseNode(map, nombre);
    printf("El punto de interés con nombre: %s ha sido eliminado exitosamente.\n", nombre);

    // Liberar la memoria ocupada por el punto de interés
    free(punto);
}

void registrarTurista(HashMap* map, char* pasaporte, char* nombre, char* pais) {
    // Crear un nuevo turista
    Turista* nuevoTurista = (Turista*)malloc(sizeof(Turista));
    if (nuevoTurista == NULL) {
        printf("Error al asignar memoria para nuevo turista.\n");
        return;
    }

    // Asignar los valores al nuevo turista
    strncpy(nuevoTurista->pasaporte, pasaporte, 100);
    strncpy(nuevoTurista->nombre, nombre, 100);
    strncpy(nuevoTurista->pais, pais, 100);

    // Insertar el nuevo turista en el hashmap
    insertMap(map, nuevoTurista->pasaporte, nuevoTurista);

    printf("Turista registrado exitosamente.\n");
}

void agregarLugarFavoritoTurista(HashMap* map, char* pasaporte, char* nombreLugar) {
    // Buscar el turista en el hashmap
    Turista* turista = get(map, pasaporte);
    if (turista == NULL) {
        printf("No se encontró el turista con pasaporte %s.\n", pasaporte);
        return;
    }

    // Aumentar el tamaño del arreglo de lugares favoritos
    turista->lugaresFavoritos = realloc(turista->lugaresFavoritos, (turista->cantidadLugares + 1) * sizeof(LugarFavorito));
    if (turista->lugaresFavoritos == NULL) {
        printf("Error al asignar memoria para lugares favoritos.\n");
        return;
    }

    // Agregar el nuevo lugar favorito
    strncpy(turista->lugaresFavoritos[turista->cantidadLugares].nombreLugar, nombreLugar, 100);
    turista->cantidadLugares++;

    printf("Lugar favorito agregado exitosamente.\n");
}

void mostrarTuristasPorPais(HashMap* map, char* pais) {
    // Obtener todos los turistas del hashmap
    Turista** turistas = (Turista**) get_all(map);
    if (turistas == NULL) {
        printf("No hay turistas registrados.\n");
        return;
    }

    // Recorrer el arreglo de turistas
    for (int i = 0; turistas[i] != NULL; i++) {
        // Verificar si el turista pertenece al país especificado
        if (strcmp(turistas[i]->pais, pais) == 0) {
            // Mostrar los datos del turista
            printf("Pasaporte: %s\n", turistas[i]->pasaporte);
            printf("Nombre: %s\n", turistas[i]->nombre);
            printf("País: %s\n", turistas[i]->pais);
            printf("------\n");
        }
    }

    // Liberar la memoria del arreglo de turistas
    free(turistas);
}

void mostrarPuntosInteresTipo(HashMap* map, char* tipo) {
    // Obtener todos los puntos de interés del hashmap
    PuntoInteres** puntos = (PuntoInteres**) get_all(map);
    if (puntos == NULL) {
        printf("No hay puntos de interés registrados.\n");
        return;
    }

    // Recorrer el arreglo de puntos de interés
    for (int i = 0; puntos[i] != NULL; i++) {
        // Verificar si el punto de interés pertenece al tipo especificado
        if (strcmp(puntos[i]->tipo, tipo) == 0) {
            // Mostrar los datos del punto de interés
            printf("Nombre: %s\n", puntos[i]->nombre);
            printf("Tipo: %s\n", puntos[i]->tipo);
            printf("Dirección: %s\n", puntos[i]->direccion);
            printf("Horario: %s\n", puntos[i]->horario);
            printf("Descripción: %s\n", puntos[i]->descripcion);
            printf("------\n");
        }
    }

    // Liberar la memoria del arreglo de puntos de interés
    free(puntos);
}



void importarCSV(HashMap* mapPuntos, HashMap* mapTuristas, char* nombreArchivoPuntos, char* nombreArchivoTuristas) {
    // Abre los archivos CSV para lectura
    FILE* archivoPuntos = fopen(nombreArchivoPuntos, "r");
    FILE* archivoTuristas = fopen(nombreArchivoTuristas, "r");
    
    if (!archivoPuntos || !archivoTuristas) {
        printf("Error al abrir los archivos.\n");
        return;
    }
    
    // Leer los datos desde los archivos CSV y almacenarlos en los hashmaps
    
    fclose(archivoPuntos);
    fclose(archivoTuristas);
}

void exportarCSV(HashMap* mapPuntos, HashMap* mapTuristas, char* nombreArchivoPuntos, char* nombreArchivoTuristas) {
    // Abre los archivos CSV para escritura
    FILE* archivoPuntos = fopen(nombreArchivoPuntos, "w");
    FILE* archivoTuristas = fopen(nombreArchivoTuristas, "w");
    
    if (!archivoPuntos || !archivoTuristas) {
        printf("Error al abrir los archivos.\n");
        return;
    }
    
    // Escribir los datos desde los hashmaps a los archivos CSV
    fclose(archivoPuntos);
    fclose(archivoTuristas);
}