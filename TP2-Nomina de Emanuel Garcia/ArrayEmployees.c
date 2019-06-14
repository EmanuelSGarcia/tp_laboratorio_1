#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define BORRADO -1
#define VACIO 1
#define OCUPADO 0

void saludar()
{
    printf("  UTN \t\t\t Nomina de Emanuel S Garcia\t\t\t  FRA\n\t\t\tProgramacion 1-TP 2, division B\n________________________________________________________________________________\n");
}
void mostrarMenu(int opcion)
{
    switch(opcion)
    {
        case 1:
            printf("1. ALTAS:\n");
            printf("2. MODIFICAR:\n");
            printf("3. BAJA:\n");
            printf("4. INFORMAR:\n");
            printf("5. SALIR\n");
        break;
        case 2:
            printf("\nSeleccione opcion a modificar:\n");
            printf("1. NOMBRE:\n");
            printf("2. APELLIDO:\n");
            printf("3. SALARIO:\n");
            printf("4. SECTOR:\n");
        break;
        case 3:
            printf("1. Listado por apellido y sector.\n");
            printf("2. Total y promedio de los salarios.\n");
        break;
    }
}

int opcionMenu(int minimo,int maximo)
{
    int respuesta;

    printf("Elija una opcion: ");
    limpiarBuffer();
    scanf("%d",&respuesta);
    while(respuesta<minimo||respuesta>maximo)
    {
        printf("\nOpcion incorrecta,seleccione nuevamente: [%d-%d]",minimo,maximo);
        limpiarBuffer();
        scanf("%d",&respuesta);
    }
    return respuesta;
}
void initEmployees(eEmployee empleados[], int tam)
{
    int i;

        for(i=0;i<tam;i++)
        {
            empleados[i].isEmpty=VACIO;
        }
}
int buscarLibre(eEmployee empleadoLibre[],int tam)
{
    int i;
    int libre=-1;

    for(i=0;i<tam;i++)
    {
        if(empleadoLibre[i].isEmpty!=OCUPADO)
        {
            libre = i;
            break;
        }
    }
    return libre;
}
int contadorIncrementalId(int contador)
{
    return ++contador;
}

int addEmployee(eEmployee empleados[],int contador,int tam)
{
    int lugarLibre=buscarLibre(empleados,tam);

    if(lugarLibre!=-1)
    {
        char nombre[50];

        printf("Ingrese nombre: ");
        limpiarBuffer();
        gets(nombre);
        while(validarPalabra(nombre)==0)
        {
            printf("Su nombre debe ser solo letras!\n");
            printf("Ingrese nombre de forma correcta: ");
            limpiarBuffer();
            gets(nombre);
        }
        strcpy(empleados[lugarLibre].name,nombre);

        char apellido[50];

        printf("Ingrese apellido: ");
        limpiarBuffer();
        gets(apellido);
        while(validarPalabra(apellido)==0)
        {
            printf("Su apellido debe ser solo letras!\n");
            printf("Ingrese apellido de forma correcta: ");
            limpiarBuffer();
            gets(apellido);
        }
        strcpy(empleados[lugarLibre].lastName,apellido);

        float salario;


        printf("Ingrese salario: ");
        limpiarBuffer();
        scanf("%f",&salario);
        empleados[lugarLibre].salary=salario;

        int auxsector;

        printf("Ingrese sector: ");
        limpiarBuffer();
        scanf("%d",&auxsector);
     /* while(isdigit(auxsector)==1)
        {
            printf("Su sector debe ser solo numeros!\n");
            printf("Ingrese sector de forma correcta: ");
            limpiarBuffer();
            scanf("%d",&auxsector);
        }*/
        empleados[lugarLibre].sector=auxsector;
        empleados[lugarLibre].isEmpty=OCUPADO;
        empleados[lugarLibre].id=contador;

    }
    else
    {
        printf("No quedan casillas disponibles!");
        pausa();
    }

    limpiarPantalla();
    return contador;
}

int findEmployeeById(eEmployee empleados[],int tam)
{
    int indice= -1;
    int i;
    int id;

    printf("Ingrese su ID a modificar: ");
    limpiarBuffer();
    scanf("%d",&id);

    for(i=0; i<tam; i++)
    {
        if(empleados[i].id==id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void modificarEmpleado(eEmployee empleado[],int tam)
{
    int opcionSeleccionada;
    int id;
    char aux[50];
    int auxsector;


    id=findEmployeeById(empleado,tam);
    limpiarPantalla();
    if(id!=-1)
    {
        mostrarMenu(2);
        opcionSeleccionada=opcionMenu(1,4);
        switch(opcionSeleccionada)
        {
            case 1:
                printf("Ingrese nuevo nombre: ");
                limpiarBuffer();
                gets(aux);
                while(validarPalabra(aux)==0)
                {
                    printf("Su nombre debe ser solo letras!\n");
                    printf("Ingrese nombre de forma correcta: ");
                    limpiarBuffer();
                    gets(aux);
                }
                strcpy(empleado[id].name,aux);

            break;
            case 2:
                printf("Ingrese nuevo apellido: ");
                limpiarBuffer();
                gets(aux);
                while(validarPalabra(aux)==0)
                {
                    printf("Su apellido debe ser solo letras!\n");
                    printf("Ingrese apellido de forma correcta: ");
                    limpiarBuffer();
                    gets(aux);
                }
                strcpy(empleado[id].lastName,aux);

            break;
            case 3:
                printf("Ingrese nuevo salario: ");
                limpiarBuffer();
                scanf("%f", &empleado[id].salary);
            break;
            case 4:
                printf("Ingrese nuevo sector: ");
                limpiarBuffer();
                scanf("%d",&auxsector);

                while(isdigit(auxsector)==0)
                {
                    printf("Su sector debe ser solo numeros!\n");
                    printf("Ingrese sector de forma correcta: ");
                    limpiarBuffer();
                    scanf("%d",&auxsector);
                }
                empleado[id].sector=auxsector;
            break;
        }
    }
    else
    {
        printf("Empleado no registrado.\n");
        pausa();
    }
    limpiarPantalla();
}

void bajaEmpleado(eEmployee empleado[],int tam)
{
    int id=findEmployeeById(empleado,tam);

    if(id!=-1)
    {
        empleado[id].isEmpty=BORRADO;

        printf("Empleado borrado con exito.\n");
        pausa();
    }
    else
    {
        printf("Empleado no registrado! \n");
        pausa();
    }
    limpiarPantalla();
}

void mostrarEmpleado(eEmployee empleado)
{
    printf("%10s %10d %10s %10f\n", empleado.lastName, empleado.sector, empleado.name, empleado.salary);
}

void mostrarListaOrdenada(eEmployee empleado[],int tam)
{
    int i;

    OrdenarEmpleados(empleado,tam);
    printf("Apellido:\tSector:\tNombre:\tSalario:\n");

    for(i=0;i<tam;i++)
    {
        if(empleado[i].isEmpty==OCUPADO)
        {
            mostrarEmpleado(empleado[i]);
        }
    }
}

void OrdenarEmpleados(eEmployee empleado[], int tam)
{
    int i;
    int j;
    eEmployee aux;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(empleado[i].isEmpty==OCUPADO)
            {
                if(strcmpi(empleado[i].lastName,empleado[j].lastName)==1)
                {
                    aux=empleado[i];
                    empleado[i]=empleado[j];
                    empleado[j]=aux;
                }
                else if (strcmpi(empleado[i].lastName,empleado[j].lastName)==0)
                {
                    if(empleado[i].sector>empleado[j].sector)
                    {
                        aux=empleado[i];
                        empleado[i]=empleado[j];
                        empleado[j]=aux;
                    }
                }
            }
        }
    }
}

void listarEmpleados(eEmployee empleados[], int tam)
{
    mostrarMenu(3);
    int opcion=opcionMenu(1,2);

    switch(opcion)
    {
        case 1:
            mostrarListaOrdenada(empleados,tam);
            pausa();
        break;
        case 2:
            mostrarListaTotalesYPromedio(empleados,tam);
            pausa();
        break;
    }
    limpiarPantalla();
}

void mostrarListaTotalesYPromedio(eEmployee empleados[],int tam)
{
    float promedios=sacarPromedio(empleados,tam);
    float totales=sacarTotales(empleados,tam);
    int empleadosPasanPromedio=cantidadSuperaPromedio(empleados,tam,promedios);

    printf("El salario total de empleados es: %.5f el promedio general es %.5f\n",totales,promedios);
    printf("               %d empleados superan el promedio\n", empleadosPasanPromedio);
}

int cantidadSuperaPromedio(eEmployee empleados[],int tam,int promedio)
{
    int i;
    int contador=0;

    for(i=0;i<tam;i++)
    {
        if(empleados[i].isEmpty==OCUPADO)
            if(empleados[i].salary>promedio)
                contador++;
    }

    return contador;
}
float sacarPromedio(eEmployee empleados[],int tam)
{
    int i;
    int contador=0;
    float acumulador=0;
    float promedio;


    for(i=0;i<tam;i++)
    {
        if(empleados[i].isEmpty==0)
        {
            if(empleados[i].salary>-1)
            {
                contador++;
                acumulador=acumulador+empleados[i].salary;
            }
        }
    }

    promedio= acumulador/contador;
    return promedio;
}

float sacarTotales(eEmployee empleados[],int tam)
{
    int i;
    float acumulador=0;

    for(i=0;i<tam;i++)
    {
        if(empleados[i].isEmpty==0)
        {
            if(empleados[i].salary>-1)
            {
                acumulador=acumulador+empleados[i].salary;
            }
        }
    }

    return acumulador;
}

int validarPalabra(char palabra[])
{
    int i=0;

    while (palabra[i]!='\0')
    {
        if((palabra[i]<'a'||palabra[i]>'z')&&(palabra[i]<'A'||palabra[i]>'Z'))
        {
            return 0;
        }
        i++;
    }

    return 1;
}

void limpiarBuffer()
{
    fflush(stdin);
}

void pausa()
{
    system("pause");
}

void limpiarPantalla()
{
    system("cls");
}
