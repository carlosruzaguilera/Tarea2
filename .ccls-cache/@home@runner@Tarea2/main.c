#include "menu.h"

int main() {
    Mapa* mapaPuntos = crearMapa();
    Mapa* mapaTuristas = crearMapa();
    
    int opcion;
    do {
        printf("1. Registrar punto de interés\n");
        printf("2. Mostrar datos de punto de interés\n");
        // ... y así sucesivamente para cada opción del menú
        printf("9. Exportar puntos de interés y turistas a archivos CSV\n");
        printf("0. Salir\n");
        printf("Ingrese la opción deseada: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                registrarPuntoInteres(mapaPuntos);
                break;
            case 2:
                mostrarDatosPuntoInteres(mapaPuntos);
                break;
            // ... y así sucesivamente para cada caso
            case 9:
                exportarACSV(mapaPuntos, mapaTuristas);
                break;
        }
    } while(opcion != 0);
    
    liberarMapa(mapaPuntos);
    liberarMapa(mapaTuristas);
    return 0;
}
