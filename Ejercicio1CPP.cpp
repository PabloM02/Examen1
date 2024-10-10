#include <cstdio>
#include <iomanip>

int main() {
   // Declarar variables
    char nombre[100];
    int cedula, tipo, horasLaborales, precioHora;
    double salarioOrdinario, aumento, salarioBruto, deduccionCCSS, salarioNeto;
    char continuar;
    

    // Inicializar Variables Contadores
    int contadorOperarios = 0, contadorTecnicos = 0, contadorProfesionales = 0;
    double acumuladoNetoOperarios = 0, acumuladoNetoTecnicos = 0, acumuladoNetoProfesionales = 0;
  double promedioNetoOperarios, promedioNetoTecnicos, promedioNetoProfesionales;
    do {
        // Entrada de datos
     printf("Ingrese el numero de cedula del empleado: ");
        scanf("%d", &cedula);
        printf("Ingrese el nombre completo del empleado: ");
        scanf(" %[^\n]", nombre); 
        printf("Ingrese el tipo de empleado (1: Operario, 2: Tecnico, 3: Profesional): ");
        scanf("%d", &tipo);
        printf("Ingrese la cantidad de horas laboradas: ");
        scanf("%d", &horasLaborales);
        printf("Ingrese el precio por hora: ");
        scanf("%d", &precioHora);

        // Funciones
        salarioOrdinario = horasLaborales * precioHora;

       if (tipo == 1) { 
            aumento = salarioOrdinario * 0.15;
            contadorOperarios++;
            acumuladoNetoOperarios += (salarioOrdinario + aumento) - (salarioOrdinario + aumento) * 0.0917;
        } else if (tipo == 2) {
            aumento = salarioOrdinario * 0.10;
            contadorTecnicos++;
            acumuladoNetoTecnicos += (salarioOrdinario + aumento) - (salarioOrdinario + aumento) * 0.0917;
        } else if (tipo == 3) { 
            aumento = salarioOrdinario * 0.05;
            contadorProfesionales++;
            acumuladoNetoProfesionales += (salarioOrdinario + aumento) - (salarioOrdinario + aumento) * 0.0917;
        } else {
            printf("Tipo de empleado invalido.\n");
            continue; 
        }

        salarioBruto = salarioOrdinario + aumento;
        deduccionCCSS = salarioBruto * 0.0917;
        salarioNeto = salarioBruto - deduccionCCSS;

        // Salida de datos
        printf("\nCedula: %d\n", cedula);
        printf("Nombre del empleado: %s\n", nombre);
        printf("Tipo de empleado: %d\n", tipo);
        printf("Salario por hora: %.2lf\n", precioHora);
        printf("Cantidad de horas laboradas: %.2lf\n", horasLaborales);
        printf("Salario ordinario: %.2lf\n", salarioOrdinario);
        printf("Aumento: %.2lf\n", aumento);
        printf("Salario bruto: %.2lf\n", salarioBruto);
        printf("Deduccion CCSS: %.2lf\n", deduccionCCSS);
        printf("Salario neto: %.2lf\n", salarioNeto);

        if (tipo == 1) {
            acumuladoNetoOperarios += salarioNeto;
        } else if (tipo == 2) {
            acumuladoNetoTecnicos += salarioNeto;
        } else if (tipo == 3) {
            acumuladoNetoProfesionales += salarioNeto;
        }

        printf("¿Desea ingresar otro empleado? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    if (contadorOperarios > 0) {
        promedioNetoOperarios = acumuladoNetoOperarios / contadorOperarios;
    }
    if (contadorTecnicos > 0) {
        promedioNetoTecnicos = acumuladoNetoTecnicos / contadorTecnicos;
    }
    if (contadorProfesionales > 0) {
        promedioNetoProfesionales = acumuladoNetoProfesionales / contadorProfesionales;
    }

     printf("Analisis del total de empleados");
    printf("\nCantidad de empleados operarios: %d\n", contadorOperarios);
    printf("Cantidad de empleados tecnicos: %d\n", contadorTecnicos);
    printf("Cantidad de empleados profesionales: %d\n", contadorProfesionales);
    printf("Acumulado salario neto operarios: %.2lf\n", acumuladoNetoOperarios);
    printf("Acumulado salario neto tecnicos: %.2lf\n", acumuladoNetoTecnicos);
    printf("Acumulado salario neto profesionales: %.2lf\n", acumuladoNetoProfesionales);
    printf("Promedio salario neto operarios: %.2lf\n", promedioNetoOperarios);
    printf("Promedio salario neto tecnicos: %.2lf\n", promedioNetoTecnicos);
    printf("Promedio salario neto profesionales: %.2lf\n", promedioNetoProfesionales);

    return 0;
}

