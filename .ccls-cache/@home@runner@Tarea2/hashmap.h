#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para los nodos del hashmap
typedef struct Node {
    char* key;
    void* value;
    struct Node* next;
} Node;

// Estructura para el hashmap
typedef struct HashMap {
    Node** array;
    int size;
} HashMap;

// Funciones del hashmap
HashMap* createHashMap(int size);
void insert(HashMap* map, char* key, void* value);
void* get(HashMap* map, char* key);
void eraseMap(HashMap* map);
void eraseNode(HashMap* map, char* key);
void freeHashMap(HashMap* map);

#endif // HASHMAP_H
