// turismo.h
#ifndef TURISMO_H
#define TURISMO_H

// Estructuras

typedef struct {
    char pasaporte[100];
    char nombre[100];
    char pais[100];
    char lugaresFavoritos[500];
} Turista; 

typedef struct {
    char nombre[100];
    char tipo[100];
    char direccion[100];
    char horario[100];
    char descripcion[100];
} PuntoInteres;

void registrarPuntoInteres(PuntoInteres *puntosInteres, int *contadorPuntos);
void mostrarDatosPuntoInteres(PuntoInteres *puntosInteres, int contadorPuntos, char *nombre);
void eliminarPuntoInteres(PuntoInteres *puntosInteres, int *contadorPuntos, char *nombre);
void registrarTurista(Turista *turistas, int *contadorTuristas);
void agregarLugarFavorito(Turista *turistas, int contadorTuristas, char *pasaporte, char *nombreLugar);
void mostrarTuristasPorPais(Turista *turistas, int contadorTuristas, char *pais);
void mostrarPuntosInteresPorTipo(PuntoInteres *puntosInteres, int contadorPuntos, char *tipo);
void importarDesdeCSV(PuntoInteres *puntosInteres, int *contadorPuntos, char *nombreArchivo);
void exportarACSV(PuntoInteres *puntosInteres, int contadorPuntos, char *nombreArchivo);

#endif // TURISMO_H
