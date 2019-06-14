#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char id[25];
    char nombre[25];
    char sueldo[25];
    char horasTrabajadas[25];
    int contadorEmpleadosCargados=0;
    Employee* auxEmpleado;


    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
    while(!feof(pFile))
    {
        auxEmpleado=employee_new();
        if(auxEmpleado!=NULL)
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
            auxEmpleado=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
            ll_add(pArrayListEmployee,auxEmpleado);
            contadorEmpleadosCargados++;
        }
        else
        {
            printf("\nNo se pudo cargar mas de %d empleados\n",contadorEmpleadosCargados);
            break;
        }
    }
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int cantidad;

    while(!feof(pFile))
    {
        Employee* empleado=employee_new();
        cantidad=fread(empleado,sizeof(Employee),1,pFile);
        if(cantidad != 1)
        {
            if(feof(pFile))
            {
                break;
            }
        }
        ll_add(pArrayListEmployee, empleado);
    }
    cantidad=ll_len(pArrayListEmployee);

    return 1;
}
