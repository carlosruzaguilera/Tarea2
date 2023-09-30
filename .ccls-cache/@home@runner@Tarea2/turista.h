#ifndef TURISTA_H
#define TURISTA_H

typedef struct LugarFavorito {
    char nombre[100];
    struct LugarFavorito* siguiente;
} LugarFavorito;

typedef struct {
    char pasaporte[100];
    char nombre[100];
    char pais[100];
    LugarFavorito* lugares_favoritos;
} Turista;

#endif
