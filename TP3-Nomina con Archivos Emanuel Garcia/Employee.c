#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include "Employee.h"
#include "tools.h"


Employee* employee_new()
{
    Employee* nuevoEmpleado;

    nuevoEmpleado=(Employee*) malloc(sizeof(Employee));
    if(nuevoEmpleado==NULL)
    {
        printf("\nNo queda espacio en memoria para otro empleado.");
    }
    else
    {
        nuevoEmpleado->id=0;
        nuevoEmpleado->sueldo=0;
        nuevoEmpleado->horasTrabajadas=0;
        strcpy(nuevoEmpleado->nombre," ");
    }

    return nuevoEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* empleadoNuevo;
    empleadoNuevo=employee_new();
    int error=0;
    int id;
    int horasTrabajadas;
    int sueldo;

    id=atoi(idStr);
    horasTrabajadas=atoi(horasTrabajadasStr);
    sueldo=atoi(sueldoStr);

    error+=employee_setId(empleadoNuevo,id);
    error+=employee_setNombre(empleadoNuevo,nombreStr);
    error+=employee_setHorasTrabajadas(empleadoNuevo,horasTrabajadas);
    error+=employee_setSueldo(empleadoNuevo,sueldo);

    if(error>0)
    {
        printf("\nAl asignar datos hubo %d errores\n",error);
        free(empleadoNuevo);
        empleadoNuevo=NULL;
    }
    return empleadoNuevo;
}

int employee_setId(Employee* this,int id)
{
    int error=1;

    if(id>0)
    {
        this->id=id;
        error=0;
    }

    return error;
}
int employee_setNombre(Employee* this,char* nombre)
{
    int error=0;

    error=validarNombre(nombre);

    if(error==0)
    {
        strcpy(this->nombre,nombre);
    }

    return error;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int error=1;

    error=validarHorasTrabajadas(horasTrabajadas);

    if(error==0)
    {
        this->horasTrabajadas=horasTrabajadas;
    }
    return error;
}
int employee_setSueldo(Employee* this,int sueldo)
{
    int error=1;

    error=validarSueldo(sueldo);

    if(error==0)
    {
        this->sueldo=sueldo;
    }
    return error;
}

int employee_getId(Employee* this,int* id)
{
    int error=1;

    if(this!=NULL&&id!=NULL)
    {

        *id=this->id;
        error=0;
    }
    return error;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int error=1;

    if(this!=NULL&&horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        error=0;
    }
    return error;

}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int error=1;

    if(this!=NULL&&sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        error=0;
    }
    return error;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int error=1;

    if(this!=NULL&&nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        error=0;
    }
    return error;
}

int CompararId(void* empleado1 ,void* empleado2)
{
    int comparacion;

    if(empleado1==NULL||empleado2==NULL)
    {
        comparacion=-2;
    }
    else if(((Employee*)empleado1)->id<((Employee*)empleado2)->id)
    {
        comparacion =-1;
    }
    else if(((Employee*)empleado1)->id==((Employee*)empleado2)->id)
    {
        comparacion =0;
    }
    else if(((Employee*)empleado1)->id>((Employee*)empleado2)->id)
    {
        comparacion =1;
    }

    return comparacion;
}

int CompararNombre(void* empleado1 ,void* empleado2)
{
    int comparacion=-2;

    if(empleado1!=NULL&&empleado2!=NULL)
    {
        comparacion=strcmpi(((Employee*)empleado1)->nombre,((Employee*)empleado2)->nombre);
    }

    return comparacion;
}

int CompararSueldo(void* empleado1 ,void* empleado2)
{
    int comparacion;

    if(empleado1==NULL||empleado2==NULL)
    {
        comparacion=-2;
    }
    else if(((Employee*)empleado1)->sueldo<((Employee*)empleado2)->sueldo)
    {
        comparacion =-1;
    }
    else if(((Employee*)empleado1)->sueldo==((Employee*)empleado2)->sueldo)
    {
        comparacion =0;
    }
    else if(((Employee*)empleado1)->sueldo>((Employee*)empleado2)->sueldo)
    {
        comparacion =1;
    }

    return comparacion;
}

int CompararHorasTrabajadas(void* empleado1 ,void* empleado2)
{
    int comparacion;

    if(empleado1==NULL||empleado2==NULL)
    {
        comparacion=-2;
    }
    else if(((Employee*)empleado1)->horasTrabajadas<((Employee*)empleado2)->horasTrabajadas)
    {
        comparacion =-1;
    }
    else if(((Employee*)empleado1)->horasTrabajadas==((Employee*)empleado2)->horasTrabajadas)
    {
        comparacion =0;
    }
    else if(((Employee*)empleado1)->horasTrabajadas>((Employee*)empleado2)->horasTrabajadas)
    {
        comparacion =1;
    }

    return comparacion;
}







