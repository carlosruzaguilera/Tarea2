#include <stdio.h>
#include "funciones.h"
#include "hashmap.h"

int main() {
    HashMap* mapPuntos = createHashMap(100);
    HashMap* mapTuristas = createHashMap(100);
    
    int opcion;
    char nombre[101], tipo[101], direccion[101], horario[101], descripcion[101], pasaporte[101], pais[101], nombreLugar[101];
    char nombreArchivoPuntos[101], nombreArchivoTuristas[101];
    
    do {
        printf("1. Registrar punto de interés\n");
        printf("2. Mostrar datos de punto de interés\n");
        printf("3. Eliminar punto de interés\n");
        printf("4. Registrar turista\n");
        printf("5. Agregar lugar favorito a turista\n");
        printf("6. Mostrar turistas por país\n");
        printf("7. Mostrar todos los puntos de interés de un tipo\n");
        printf("8. Importar puntos de interés y turistas desde archivos CSV\n");
        printf("9. Exportar puntos de interés y turistas a archivos CSV\n");
        printf("0. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                // Llamar a la función registrarPuntoInteres
                printf("Ingrese nombre, tipo, dirección, horario, descripción: ");
                scanf("%100s %100s %100s %100s %100s", nombre, tipo, direccion, horario, descripcion);
                registrarPuntoInteres(mapPuntos, nombre, tipo, direccion, horario, descripcion);
                break;
            case 2:
                // Llamar a la función mostrarDatosPuntoInteres
                printf("Ingrese nombre: ");
                scanf("%100s", nombre);
                mostrarDatosPuntoInteres(mapPuntos, nombre);
                break;
            case 3:
                // Llamar a la función eliminarPuntoInteres
                printf("Ingrese nombre: ");
                scanf("%100s", nombre);
                eliminarPuntoInteres(mapPuntos, nombre);
                break;
            case 4:
                // Llamar a la función registrarTurista
                printf("Ingrese pasaporte, nombre, país: ");
                scanf("%100s %100s %100s", pasaporte, nombre, pais);
                registrarTurista(mapTuristas, pasaporte, nombre, pais);
                break;
            case 5:
                // Llamar a la función agregarLugarFavoritoTurista
                printf("Ingrese pasaporte, nombre del lugar: ");
                scanf("%100s %100s", pasaporte, nombreLugar);
                agregarLugarFavoritoTurista(mapTuristas, pasaporte, nombreLugar);
                break;
            case 6:
                // Llamar a la función mostrarTuristasPorPais
                printf("Ingrese país: ");
                scanf("%100s", pais);
                mostrarTuristasPorPais(mapTuristas, pais);
                break;
            case 7:
                // Llamar a la función mostrarPuntosInteresTipo
                printf("Ingrese tipo: ");
                scanf("%100s", tipo);
                mostrarPuntosInteresTipo(mapPuntos, tipo);
                break;
            case 8:
                // Llamar a la función importarCSV
                printf("Ingrese nombre de archivo de puntos y turistas: ");
                scanf("%100s %100s", nombreArchivoPuntos, nombreArchivoTuristas);
                importarCSV(mapPuntos, mapTuristas, nombreArchivoPuntos, nombreArchivoTuristas);
                break;
            case 9:
                // Llamar a la función exportarCSV
                printf("Ingrese nombre de archivo de puntos y turistas: ");
                scanf("%100s %100s", nombreArchivoPuntos, nombreArchivoTuristas);
                exportarCSV(mapPuntos, mapTuristas, nombreArchivoPuntos, nombreArchivoTuristas);
                break;
        }
    } while (opcion != 0);
    
    // Liberar la memoria utilizada por los hashmaps
    eraseMap(mapPuntos);
    eraseMap(mapTuristas);
    
    return 0;
}
