#ifndef MAPA_H
#define MAPA_H

#include "punto_interes.h"
#include "turista.h"

typedef struct NodoMapa {
    char clave[100];
    void* valor;
    struct NodoMapa* siguiente;
} NodoMapa;

typedef struct {
    NodoMapa* cabeza;
} Mapa;

void inicializarMapa(Mapa* mapa);
void insertar(Mapa* mapa, char* clave, void* valor);
void* buscar(Mapa* mapa, char* clave);
void eliminar(Mapa* mapa, char* clave);
void mostrarMapa(Mapa* mapa);

#endif
