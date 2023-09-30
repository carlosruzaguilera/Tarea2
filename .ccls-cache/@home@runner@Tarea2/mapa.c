#include "mapa.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void inicializarMapa(Mapa* mapa) {
    mapa->cabeza = NULL;
}

void insertar(Mapa* mapa, char* clave, void* valor) {
    NodoMapa* nuevo = (NodoMapa*)malloc(sizeof(NodoMapa));
    strcpy(nuevo->clave, clave);
    nuevo->valor = valor;
    nuevo->siguiente = mapa->cabeza;
    mapa->cabeza = nuevo;
}

void* buscar(Mapa* mapa, char* clave) {
    NodoMapa* actual = mapa->cabeza;
    while (actual != NULL) {
        if (strcmp(actual->clave, clave) == 0) {
            return actual->valor;
        }
        actual = actual->siguiente;
    }
    return NULL;
}

void eliminar(Mapa* mapa, char* clave) {
    NodoMapa* actual = mapa->cabeza;
    NodoMapa* anterior = NULL;
    while (actual != NULL && strcmp(actual->clave, clave) != 0) {
        anterior = actual;
        actual = actual->siguiente;
    }
    if (actual == NULL) {
        return;
    }
    if (anterior == NULL) {
        mapa->cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }
    free(actual);
}

void mostrarMapa(Mapa* mapa) {
    NodoMapa* actual = mapa->cabeza;
    while (actual != NULL) {
        printf("Clave: %s\n", actual->clave);
        actual = actual->siguiente;
    }
}
