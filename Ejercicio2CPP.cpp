#include <stdio.h>
#include <string.h>

int main() {
    // Declarar variables
    int numeroFactura, cedula, cantidadEntradas, localidad;
    char nombreComprador[100];
    double precioEntrada, subtotal, cargosServicios, totalPagar;
    char continuar;
    int contadorEntradasSol = 0, contadorEntradasSombra = 0, contadorEntradasPreferencial = 0;
    double acumuladoSol = 0, acumuladoSombra = 0, acumuladoPreferencial = 0;

 
    do {
        // Entrada de datos
        printf("Ingrese el numero de factura: ");
        scanf("%d", &numeroFactura);
        printf("Ingrese la cedula del comprador: ");
        scanf("%d", &cedula);
        printf("Ingrese el nombre del comprador: ");
        scanf(" %[^\n]%*c", nombreComprador); 

        printf("Seleccione la localidad (1: Sol Norte/Sur, 2: Sombra Este/Oeste, 3: Preferencial): ");
        scanf("%d", &localidad);

        // Validar local
        if (localidad < 1 || localidad > 3) {
            printf("Localidad invalida.\n");
            continue; 
        }

        printf("Ingrese la cantidad de entradas (maximo 4): ");
        scanf("%d", &cantidadEntradas);

        // Validar cantidad de entradas
        if (cantidadEntradas < 1 || cantidadEntradas > 4) {
            printf("Cantidad de entradas invalida.\n");
            continue; 
        }

        // Funciones
         if (localidad == 1) { 
            precioEntrada = 10500;
                contadorEntradasSol += cantidadEntradas;
                acumuladoSol += (precioEntrada * cantidadEntradas);
        } else if (localidad == 2) {
           precioEntrada = 20500;
                contadorEntradasSombra += cantidadEntradas;
                acumuladoSombra += (precioEntrada * cantidadEntradas);
        } else if (localidad == 3) { 
             precioEntrada = 25500;
                contadorEntradasPreferencial += cantidadEntradas;
                acumuladoPreferencial += (precioEntrada * cantidadEntradas);
        } else {
            printf("Localidad invalida.\n");
            continue; 
        }
        subtotal = cantidadEntradas * precioEntrada;
        cargosServicios = 1000 * cantidadEntradas;
        totalPagar = subtotal + cargosServicios;
        // Salida de Datos
        printf("Numero de factura: %d\n", numeroFactura);
        printf("Cedula: %d\n", cedula);
        printf("Nombre del comprador: %s\n", nombreComprador);
        printf("Localidad: %d\n", localidad);
        printf("Cantidad de entradas: %d\n", cantidadEntradas);
        printf("Subtotal: %.2f\n", subtotal);
        printf("Cargos por servicios: %.2f\n", cargosServicios);
        printf("Total a pagar: %.2f\n", totalPagar);
        printf("¿Desea continuar? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 's');
    
    printf("Estadisticas del Total de ventas de entradas");
    printf("Estadisticas finales:\n");
    printf("Cantidad de entradas en Sol Norte/Sur: %d\n", contadorEntradasSol);
    printf("Acumulado de dinero en Sol Norte/Sur: %.2f\n", acumuladoSol);
    printf("Cantidad de entradas en Sombra Este/Oeste: %d\n", contadorEntradasSombra);
    printf("Acumulado de dinero en Sombra Este/Oeste: %.2f\n", acumuladoSombra);
    printf("Cantidad de entradas en Preferencial: %d\n", contadorEntradasPreferencial);
    printf("Acumulado de dinero en Preferencial: %.2f\n", acumuladoPreferencial);

    return 0;
}

