#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TAM 1000

int main()
{
    int contador=0;
    char respuesta='s';
    int opcionSeleccionada;
    int banderaOpcion1=0;
    eEmployee arrayEmpleados[TAM];

    initEmployees(arrayEmpleados,TAM);
    do
    {
        saludar();
        mostrarMenu(1);
        opcionSeleccionada=opcionMenu(1,5);

        switch(opcionSeleccionada)
        {
            case 1:
                contador=addEmployee(arrayEmpleados,contadorIncrementalId(contador),TAM);
                banderaOpcion1=1;
            break;
            case 2:
                if(banderaOpcion1==1)
                {
                    modificarEmpleado(arrayEmpleados,TAM);
                }
                else
                {
                    printf("Primero se debe dar de alta algun usuario!\n");
                    pausa();
                }
            break;
            case 3:
                 if(banderaOpcion1==1)
                {
                    bajaEmpleado(arrayEmpleados,TAM);
                }
                else
                {
                    printf("Primero se debe dar de alta a algun usuario!\n");
                    pausa();
                }

            break;
            case 4:
                 if(banderaOpcion1==1)
                {
                    listarEmpleados(arrayEmpleados, TAM);
                }
                else
                {
                    printf("Primero se debe dar de alta algun usuario!\n");
                    pausa();
                }
            break;
            case 5:
                respuesta='n';
                break;
        }
    }while(respuesta=='s');
    return 0;
}
