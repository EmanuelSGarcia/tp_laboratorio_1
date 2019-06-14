#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "tools.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int banderaCarga=0;
    int error;
    LinkedList* listaEmpleados = ll_newLinkedList();


    int cantidad;
    do{
        limpiarPantalla();
        saludar();
        option=menu("1.CARGA ARCHIVO EMPLEADOS TEXTO\n2.CARGA ARCHIVO EMPLEADOS BINARIO\n3.ALTA EMPLEADO\n4.MODIFICAR EMPLEADO\n5.BORRAR EMPLEADO\n6.MOSTRAR LISTA EMPLEADOS\n7.ORDENAR EMPLEADOS\n8.GUARDAR ARCHIVO EMPLEADOS TEXTO.\n9.GUARDAR ARCHIVO EMPLEADOS BINARIO\n",1,10);

        switch(option)
        {
            case 1:
                if(banderaCarga==0)
                {
                    error=controller_loadFromText("data.csv",listaEmpleados);
                    if(error==0)
                    {
                        banderaCarga=1;
                        cantidad=ll_len(listaEmpleados);
                        printf("\n%d Empleados se encuentran cargados\n",cantidad);
                        pausa();
                    }
                }
                else
                {
                    printf("\nYa se cargaron los archivos\n");
                    pausa();
                }
                break;
            case 2:
                if(banderaCarga==0)
                {
                    error=controller_loadFromBinary("data.bin",listaEmpleados);
                    if(error==0)
                    {
                        cantidad=ll_len(listaEmpleados);
                        printf("\n%d Empleados se encuentran cargados\n",cantidad);
                        banderaCarga=1;
                        pausa();
                    }
                }
                else
                {
                    printf("\nYa se cargaron los archivos\n");
                    pausa();
                }
                break;
            case 3:
                limpiarPantalla();
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                limpiarPantalla();
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                limpiarPantalla();
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                limpiarPantalla();
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                limpiarPantalla();
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                limpiarPantalla();
                controller_saveAsText("data.csv",listaEmpleados);
                cantidad=ll_len(listaEmpleados);
                printf("\nSe guardaron %d empleados\n",cantidad);
                system("pause");
                break;
            case 9:
                limpiarPantalla();
                controller_saveAsBinary("data.bin",listaEmpleados);
                cantidad=ll_len(listaEmpleados);
                printf("\nSe guardaron %d empleados\n",cantidad);;
                system("pause");
                break;
            case 10:
                    printf("\nADIOS\n");
                break;
        }
    }while(option != 10);
    return 0;
}
