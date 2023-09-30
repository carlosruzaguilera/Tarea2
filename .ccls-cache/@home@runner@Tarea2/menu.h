#ifndef MENU_H
#define MENU_H

#include "mapa.h"
#include "punto_interes.h"
#include "turista.h"

void registrarPuntoInteres(Mapa* mapa);
void mostrarDatosPuntoInteres(Mapa* mapa);
void eliminarPuntoInteres(Mapa* mapa);
void registrarTurista(Mapa* mapa);
void agregarLugarFavoritoTurista(Mapa* mapa);
void mostrarTuristasPorPais(Mapa* mapa);
void mostrarPuntosInteresTipo(Mapa* mapa);
void importarDesdeCSV(Mapa* mapaPuntos, Mapa* mapaTuristas);
void exportarACSV(Mapa* mapaPuntos, Mapa* mapaTuristas);



void leer_puntos_interes_csv(const char* nombre_archivo);
void leer_turistas_csv(const char* nombre_archivo);






#endif // MENU_H
