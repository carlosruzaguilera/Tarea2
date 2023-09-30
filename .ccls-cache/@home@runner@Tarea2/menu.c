#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

void registrar_punto_interes(char *nombre, char *tipo, char *direccion,
                             char *horario, char *descripcion) {
  if (strlen(nombre) > 100 || strlen(tipo) > 100 || strlen(direccion) > 100 ||
      strlen(horario) > 100 || strlen(descripcion) > 100) {
    printf("Error: Los campos no deben exceder los 100 caracteres.\n");
    return;
  }
  PuntoInteres *punto =
      crear_punto_interes(nombre, tipo, direccion, horario, descripcion);
  agregar_punto_interes(punto);
}

void mostrar_datos_punto_interes(char *nombre) {
  PuntoInteres *punto = buscar_punto_interes(nombre);
  if (punto != NULL) {
    imprimir_punto_interes(punto);
  } else {
    printf("Error: Punto de interés no encontrado.\n");
  }
}

void eliminar_punto_interes(char *nombre) {
  int resultado = eliminar_punto_interes_del_mapa(nombre);
  if (resultado == 0) {
    printf("Punto de interés eliminado exitosamente.\n");
  } else {
    printf("Error al eliminar el punto de interés.\n");
  }
}

void registrar_turista(char *pasaporte, char *nombre, char *pais) {
  Turista *turista = crear_turista(pasaporte, nombre, pais);
  agregar_turista(turista);
}

void agregar_lugar_favorito_a_turista(char *pasaporte, char *nombre_lugar) {
  Turista *turista = buscar_turista(pasaporte);
  if (turista != NULL) {
    agregar_lugar_favorito(turista, nombre_lugar);
  } else {
    printf("Error: Turista no encontrado.\n");
  }
}

void mostrar_turistas_por_pais(char *pais) {
  ListaTuristas *lista = obtener_turistas_por_pais(pais);
  imprimir_lista_turistas(lista);
}

void mostrar_puntos_interes_tipo(char *tipo) {
  ListaPuntos *lista = obtener_puntos_por_tipo(tipo);
  imprimir_lista_puntos(lista);
}

void exportar_puntos_interes_turistas_csv(char *nombre_archivo_puntos,
                                          char *nombre_archivo_turistas) {
  exportar_puntos_interes(nombre_archivo_puntos);
  exportar_turistas(nombre_archivo_turistas);
}

// Función para leer puntos de interés desde un archivo CSV
void leer_puntos_interes_csv(const char *nombre_archivo) {
  FILE *archivo = fopen(nombre_archivo, "r");
  if (archivo == NULL) {
    perror("Error al abrir el archivo");
    return;
  }

  char linea[1024];
  while (fgets(linea, sizeof(linea), archivo)) {
    char *nombre = strtok(linea, ",");
    char *tipo = strtok(NULL, ",");
    char *direccion = strtok(NULL, ",");
    char *horario = strtok(NULL, ",");
    char *descripcion = strtok(NULL, ",");
    descripcion[strcspn(descripcion, "\n")] =
        '\0'; // Eliminar el salto de línea al final

    // Aquí puedes llamar a la función para agregar el punto de interés al mapa
    agregar_punto_interes(nombre, tipo, direccion, horario, descripcion);
  }

  fclose(archivo);
}

// Función para leer turistas desde un archivo CSV
void leer_turistas_csv(const char *nombre_archivo) {
  FILE *archivo = fopen(nombre_archivo, "r");
  if (archivo == NULL) {
    perror("Error al abrir el archivo");
    return;
  }

  char linea[1024];
  while (fgets(linea, sizeof(linea), archivo)) {
    char *pasaporte = strtok(linea, ",");
    char *nombre = strtok(NULL, ",");
    char *pais = strtok(NULL, ",");
    char *lugares_favoritos = strtok(NULL, ",");
    lugares_favoritos[strcspn(lugares_favoritos, "\n")] =
        '\0'; // Eliminar el salto de línea al final

    // Aquí puedes llamar a la función para agregar el turista al mapa
    agregar_turista(pasaporte, nombre, pais, lugares_favoritos);
  }

  fclose(archivo);
}
