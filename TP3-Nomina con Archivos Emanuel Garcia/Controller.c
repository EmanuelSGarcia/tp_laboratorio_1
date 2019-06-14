#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "tools.h"
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "tools.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* datosACargar;
    int error=1;

    datosACargar=fopen(path,"r");

    if(datosACargar==NULL)
    {
        printf("\nError al cargar datos. [TEXTO]\n");
        pausa();
    }
    else
	{
	    error=0;
        parser_EmployeeFromText(datosACargar,pArrayListEmployee);
	}
    fclose(datosACargar);

    return error;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* datosACargar;
    int error=1;

    datosACargar=fopen(path,"rb");

    if(datosACargar==NULL)
    {
        printf("\nError al cargar datos. [BINARIO]\n");
        pausa();
    }
    else
    {
        error=0;
        parser_EmployeeFromBinary(datosACargar,pArrayListEmployee);
    }
    fclose(datosACargar);

    return error;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleadoNuevo;
    char respuesta;
    int idInt;
    char id[25];
    char nombre[128];
    char horasTrabajas[25];
    char sueldo[25];

    do
    {
        idInt=IdAutoIncremental(pArrayListEmployee);
        sprintf(id,"%d",idInt);

        printf("\nIngresar nombre: ");
        limpiarBuffer();
        gets(nombre);

        printf("\nIngresar Horas Trabajadas: ");
        limpiarBuffer();
        gets(horasTrabajas);

        printf("\nIngresar sueldo: ");
        limpiarBuffer();
        gets(sueldo);

        empleadoNuevo=employee_newParametros(id,nombre,horasTrabajas,sueldo);
        if(empleadoNuevo==NULL)
        {
            printf("\nDesea reintentar? [S/N] ");
            respuesta=getche();
        }
        else
        {
            ll_add(pArrayListEmployee,empleadoNuevo);
            printf("\nEmpleado cargado correctamente,desea ingresar otro? [S/N] ");
            respuesta=getche();
        }
        limpiarPantalla();
    }while(respuesta!='n');


    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmpleado;
    char respuesta;
    char nombreNuevo[128];
    int nuevosValor;
    int error;

    do
    {
        auxEmpleado=buscarEmpleadoId(pArrayListEmployee);

        if(auxEmpleado==NULL)
        {
            printf("Desea reintentar? [S|N]\n");
            respuesta=getche();
        }
        else
        {
            printf("ID: %d     Empleado: %s\nSueldo: %d     Horas trabajadas: %d\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->sueldo,auxEmpleado->horasTrabajadas);
            printf("\nDesea modificar este empleado? [S|N]\n");
            respuesta=getche();
            if(respuesta=='s')
                break;
        }
    }while(respuesta=='s');

    while(respuesta=='s')
    {
        respuesta=menu("\n1.Nombre\n2.Sueldo\n3.Horas trabajadas\n",1,3);
        switch(respuesta)
        {
            case 1:
                do
                {
                    printf("\nIngrese nuevo nombre: \n");
                    limpiarBuffer();
                    gets(nombreNuevo);
                    error=employee_setNombre(auxEmpleado,nombreNuevo);
                    if(error!=0)
                    {
                        printf("Error");
                    }
                }while(error==1);
                break;
            case 2:
                do
                {
                    printf("\nIngrese nuevo sueldo: \n");
                    limpiarBuffer();
                    scanf("%d",&nuevosValor);
                    error=employee_setSueldo(auxEmpleado,nuevosValor);
                    if(error!=0)
                    {
                        printf("Error");
                    }
                }while(error==1);
                break;
            case 3:
                do
                {
                    printf("\nIngrese horas trabajadas: \n");
                    limpiarBuffer();
                    scanf("%d",&nuevosValor);
                    error=employee_setHorasTrabajadas(auxEmpleado,nuevosValor);
                    if(error!=0)
                    {
                        printf("Error");
                    }
                }while(error==1);
                break;
        }
        printf("\nDesea realizar mas modificaciones? [S|N] ");
        limpiarBuffer();
        respuesta=getche();
    }
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmpleado;
    char respuesta;

    do
    {
        auxEmpleado=buscarEmpleadoId(pArrayListEmployee);

        if(auxEmpleado==NULL)
        {
            printf("\nDesea reintentar? [S|N]\n");
            respuesta=getche();
        }
        else
        {
            printf("\nSe ELIMINARA a %s con el ID:%d\nSueldo de %d por unas %d horas trabajadas\nEsta Seguro?",auxEmpleado->nombre,auxEmpleado->id,auxEmpleado->sueldo,auxEmpleado->horasTrabajadas);
            respuesta=getche();
            if(respuesta=='s')
            {
                ll_remove(pArrayListEmployee,ll_indexOf(pArrayListEmployee,auxEmpleado));
                printf("\nBORRADO\n");
                pausa();
                break;
            }
        }
    }while(respuesta=='s');

    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i = 0;
    int stop=0;

    printf("\nID    |    Hrs TRABAJADAS    |    SUELDO    |    NOMBRE    |\n");
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        Employee* emp = ll_get(pArrayListEmployee, i);
        printf(" %04d    %10.d          %10.d          %s\n",emp->id,emp->horasTrabajadas,emp->sueldo,emp->nombre);
        stop++;
        if(stop==200)
        {
            stop=0;
            pausa();
            limpiarPantalla();
        }
    }
    pausa();
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int criterio;

    printf("\nCriterios de ordenamiento\n");
    opcion=menu("\n1.Ordenar por ID\n2.Ordenar por nombre\n3.Ordenar por sueldo\n4.Ordenar por horas trabajadas\n",1,4);

    switch(opcion)
    {
        case 1:
            criterio=criterioDeOrdenamiento();
            printf("\nMomentito...");
            ll_sort(pArrayListEmployee,CompararId,criterio);
            break;
        case 2:
            criterio=criterioDeOrdenamiento();
            printf("\nMomentito...");
            ll_sort(pArrayListEmployee,CompararNombre,criterio);
            break;
        case 3:
            criterio=criterioDeOrdenamiento();
            printf("\nMomentito...");
            ll_sort(pArrayListEmployee,CompararSueldo,criterio);
            break;
        case 4:
            criterio=criterioDeOrdenamiento();
            printf("\nMomentito...");
            ll_sort(pArrayListEmployee,CompararHorasTrabajadas,criterio);
            break;
    }

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE *datos;
    Employee* auxEmpleado;
    int cantidad;
    int i;

    datos=fopen(path, "w");
    if(datos==NULL)
    {
        printf("\nError al guardar datos. [TEXTO]\n");
        pausa();
	}

	cantidad=ll_len(pArrayListEmployee);
	fprintf(datos,"id,nombre,horasTrabajadas,sueldo\n");
    for(i=0;i<cantidad;i++)
    {
        auxEmpleado=ll_get(pArrayListEmployee,i);
        fprintf(datos,"%d,%s,%d,%d\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
    }
	fclose(datos);

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE *datos;
    Employee* auxEmpleado;
    int cantidad;
    int i;

    datos=fopen(path,"wb");
    if(datos==NULL)
    {
        printf("\nError al guardar datos. [BINARIO]\n");
        pausa();
	}

	cantidad=ll_len(pArrayListEmployee);
    for(i=0;i<cantidad;i++)
    {
        auxEmpleado=ll_get(pArrayListEmployee,i);
        fwrite(auxEmpleado,sizeof(Employee),1,datos);
    }
	fclose(datos);

    return 1;
}



