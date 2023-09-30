#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "hashmap.h"

// Declaraciones de las estructuras
typedef struct {
    char nombre[101];
    char tipo[101];
    char direccion[101];
    char horario[101];
    char descripcion[101];
} PuntoInteres;

typedef struct {
    char nombreLugar[101];
} LugarFavorito;

typedef struct {
    char pasaporte[101];
    char nombre[101];
    char pais[101];
    LugarFavorito* lugaresFavoritos;
    int cantidadLugares;
} Turista;

// Declaraciones de las funciones
void registrarPuntoInteres(HashMap* map, char* nombre, char* tipo, char* direccion, char* horario, char* descripcion);
void mostrarDatosPuntoInteres(HashMap* map, char* nombre);
void eliminarPuntoInteres(HashMap* map, char* nombre);
void registrarTurista(HashMap* map, char* pasaporte, char* nombre, char* pais);
void agregarLugarFavoritoTurista(HashMap* map, char* pasaporte, char* nombreLugar);
void mostrarTuristasPorPais(HashMap* map, char* pais);
void mostrarPuntosInteresTipo(HashMap* map, char* tipo);
void importarCSV(HashMap* mapPuntos, HashMap* mapTuristas, char* nombreArchivoPuntos, char* nombreArchivoTuristas);
void exportarCSV(HashMap* mapPuntos, HashMap* mapTuristas, char* nombreArchivoPuntos, char* nombreArchivoTuristas);


#endif // FUNCIONES_H
