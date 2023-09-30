#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

void registrarPuntoInteres(Mapa* mapa) {
    // Implementación pendiente
}

void mostrarDatosPuntoInteres(Mapa* mapa) {
    // Implementación pendiente
}

void eliminarPuntoInteres(Mapa* mapa) {
    // Implementación pendiente
}

void registrarTurista(Mapa* mapa) {
    // Implementación pendiente
}

void agregarLugarFavoritoTurista(Mapa* mapa) {
    // Implementación pendiente
}

void mostrarTuristasPorPais(Mapa* mapa) {
    // Implementación pendiente
}

void mostrarPuntosInteresTipo(Mapa* mapa) {
    // Implementación pendiente
}

void importarDesdeCSV(Mapa* mapaPuntos, Mapa* mapaTuristas) {
    // Implementación pendiente
}

void exportarACSV(Mapa* mapaPuntos, Mapa* mapaTuristas) {
    // Implementación pendiente
}



// Función para leer puntos de interés desde un archivo CSV
void leer_puntos_interes_csv(const char* nombre_archivo) {
    FILE* archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    char linea[1024];
    while (fgets(linea, sizeof(linea), archivo)) {
        char* nombre = strtok(linea, ",");
        char* tipo = strtok(NULL, ",");
        char* direccion = strtok(NULL, ",");
        char* horario = strtok(NULL, ",");
        char* descripcion = strtok(NULL, ",");
        descripcion[strcspn(descripcion, "\n")] = '\0'; // Eliminar el salto de línea al final

        // Aquí puedes llamar a la función para agregar el punto de interés al mapa
        agregar_punto_interes(nombre, tipo, direccion, horario, descripcion);
    }

    fclose(archivo);
}



// Función para leer turistas desde un archivo CSV
void leer_turistas_csv(const char* nombre_archivo) {
    FILE* archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    char linea[1024];
    while (fgets(linea, sizeof(linea), archivo)) {
        char* pasaporte = strtok(linea, ",");
        char* nombre = strtok(NULL, ",");
        char* pais = strtok(NULL, ",");
        char* lugares_favoritos = strtok(NULL, ",");
        lugares_favoritos[strcspn(lugares_favoritos, "\n")] = '\0'; // Eliminar el salto de línea al final

        // Aquí puedes llamar a la función para agregar el turista al mapa
        agregar_turista(pasaporte, nombre, pais, lugares_favoritos);
    }

    fclose(archivo);
}
