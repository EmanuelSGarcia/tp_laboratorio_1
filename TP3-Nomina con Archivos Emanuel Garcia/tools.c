#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include "tools.h"
#include "Employee.h"
#include "LinkedList.h"

void saludar()
{
    printf("  UTN \t\t\t Nomina de Emanuel S Garcia\t\t\t  FRA\n\t\t\tProgramacion 1-TP 3, division B\n________________________________________________________________________________\n");
}

char menu(char message[],int minimo,int maximo)
{
    int c;
    do
    {
        printf("%s",message);
        printf("\nElija una opcion: ");
        limpiarBuffer();
        scanf("%d",&c);
    }while(!(c>=minimo&&c<=maximo));

	return c;
}

int validarNombre(char* nombreStr)
{
    int i=0;

    if(nombreStr[i]=='\0')
    {
       return 1;
    }
    while(nombreStr[i]!='\0')
    {
        if(nombreStr[i]!=' ')
        {
            if(nombreStr[i]<'a'||nombreStr[i]>'z')
            {
                if(nombreStr[i]<'A'||nombreStr[i]>'Z')
                {
                    if(nombreStr[i]!='-')
                    {
                        return 1;
                    }
                }
            }
        }
        i++;
    }

    return 0;
}

int validarHorasTrabajadas(int horas)
{
    if(horas>0 && horas<10000)
    {
      return 0;
    }

    return 1;
}

int validarSueldo(int sueldo)
{
    if(sueldo>0 && sueldo<1000000)
    {
        return 0;
    }

    return 1;
}

int IdAutoIncremental(LinkedList* this)
{
    int i;
    Employee* auxEmpleado;
    int mayor=1000;

    for(i=0;i<ll_len(this);i++)
    {
        auxEmpleado = ll_get(this,i);
        if(auxEmpleado->id>mayor)
        {
            mayor = auxEmpleado->id;
        }
    }

    return ++mayor;
}

void* buscarEmpleadoId(LinkedList* this)
{
    int idBuscado;
    int idObtenido;
    int i;
    Employee* auxEmpleado;

    printf("\nIngresar ID: ");
    limpiarBuffer();
    scanf("%d",&idBuscado);
    while(idBuscado<=0)
    {
        printf("\nError, Ingresar ID valido: ");
        limpiarBuffer();
        scanf("%d",&idBuscado);
    }

    for(i=0;i<ll_len(this);i++)
    {
        auxEmpleado=ll_get(this,i);
        employee_getId(auxEmpleado,&idObtenido);

        if(idObtenido==idBuscado)
        {
            return auxEmpleado;
        }
    }
    printf("\nID: %d no encontrado\n",idBuscado);

    return NULL;
}

int criterioDeOrdenamiento(void)
{
    char criterio;
    int criterioInt;

    printf("\n1.Menor a mayor\n2.Mayor a menor\n");
    limpiarBuffer();
    criterio=getche();
    while(criterio!='1'&&criterio!='2')
    {
        printf("\n1.Menor a mayor\n2.Mayor a menor\n");
        limpiarBuffer();
        criterio=getche();
    }

    if(criterio=='2')
    {
        criterio='0';
    }
    criterioInt=atoi(&criterio);

    return criterioInt;

}

void limpiarPantalla(void)
{
    system("cls");
}

void limpiarBuffer(void)
{
    fflush(stdin);
}

void pausa(void)
{
    system("pause");
}
