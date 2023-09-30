#include "hashmap.h"

// Función hash simple
unsigned int hash(char* key, int size) {
    unsigned int hashValue = 0;
    while (*key) {
        hashValue = (hashValue << 5) + *key++;
    }
    return hashValue % size;
}

// Crear un nuevo hashmap
HashMap* createHashMap(int size) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->size = size;
    map->array = (Node**)malloc(sizeof(Node*) * size);
    for (int i = 0; i < size; i++) {
        map->array[i] = NULL;
    }
    return map;
}

// Insertar un nuevo par clave-valor en el hashmap
void insert(HashMap* map, char* key, void* value) {
    unsigned int index = hash(key, map->size);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = map->array[index];
    map->array[index] = newNode;
}

// Obtener el valor asociado a una clave en el hashmap
void* get(HashMap* map, char* key) {
    unsigned int index = hash(key, map->size);
    Node* current = map->array[index];
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

// Eliminar un par clave-valor del hashmap por su clave
void eraseMap(HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        Node* current = map->array[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(map->array);
    free(map);
}

void eraseNode(HashMap* map, char* key) {
    unsigned int index = hash(key, map->size);
    Node* current = map->array[index];
    Node* prev = NULL;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                map->array[index] = current->next;
            }
            free(current->key);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}


// Liberar la memoria utilizada por el hashmap
void freeHashMap(HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        Node* current = map->array[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(map->array);
    free(map);
}


// Implementación de insertMap
void insertMap(HashMap* map, char* key, void* value) {
    unsigned int index = hash(key, map->size);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = map->array[index];
    map->array[index] = newNode;
}

// Implementación de get_all
void get_all(HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        Node* current = map->array[i];
        while (current) {
            printf("Clave: %s, Valor: %p\n", current->key, current->value);
            current = current->next;
        }
    }
}