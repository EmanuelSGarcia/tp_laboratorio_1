#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{
    int opcionSeleccionada;
    char salir ='n';
    float numeroA;
    float numeroB;
    int banderaNumeroFaltanteA=0;
    int banderaNumeroFaltanteB=0;
    int banderaErrorDivision=0;
    float numerosSumados;
    float numerosRestados;
    float numerosDivididos;
    float numerosMultiplicados;
    int banderaErrorFactorA=0;
    int banderaErrorFactorB=0;
    long numeroFactoreadoA;
    long numeroFactoreadoB;
    int banderaCalculosFaltantes=0;

    do
    {
        saludar();
        mostrarMenu(banderaNumeroFaltanteA,numeroA,banderaNumeroFaltanteB,numeroB,banderaCalculosFaltantes);
        opcionSeleccionada= opcionMenu();

        switch(opcionSeleccionada)
        {
            case 1:
                numeroA=pedirNumero();
                banderaNumeroFaltanteA=1;
            break;

            case 2:
                numeroB=pedirNumero();
                banderaNumeroFaltanteB=1;
            break;
            case 3:

            if(banderaNumeroFaltanteA==0||banderaNumeroFaltanteB==0)
            {
                printf("\nPara realizar los calculos es necesario ingresar 2 numeros a operar.\n");
                system("pause");
                break;
            }

            numerosSumados= calcularSuma(numeroA,numeroB);

            numerosRestados= calcularDiferencia(numeroA,numeroB);

            banderaErrorDivision=validarDivision(numeroB);
            numerosDivididos= calcularDivision(numeroA,numeroB);

            numerosMultiplicados= calcularMultiplicacion(numeroA,numeroB);

            banderaErrorFactorA=validacionNumeroAFactorear(numeroA);
            if(banderaErrorFactorA==0)
            {
                numeroFactoreadoA= factorizacionDeNumero(numeroA);
            }

            banderaErrorFactorB=validacionNumeroAFactorear(numeroB);
            if(banderaErrorFactorB==0)
            {
                numeroFactoreadoB= factorizacionDeNumero(numeroB);
            }

            banderaCalculosFaltantes=1;
            break;
            case 4:

                if(banderaCalculosFaltantes==0)
                {
                printf("\nPara mostrar los resultados es necesario realizar primero los calculos.\n");
                system("pause");
                break;
                }

                printf("El resultado de %f + %f es: %.2f\n",numeroA,numeroB,numerosSumados);

                printf("El resultado de %f - %f es: %.2f\n",numeroA,numeroB,numerosRestados);

                if(banderaErrorDivision==1)
                {
                    printf("No es posible dividir por cero.\n");
                }
                else
                {
                    printf("El resultado de %f / %f es: %.2f\n",numeroA,numeroB,numerosDivididos);
                }

                printf("El resultado de %f * %f es: %.2f\n",numeroA,numeroB,numerosMultiplicados);

                if(banderaErrorFactorA==0&&banderaErrorFactorB==0)
                {
                    printf("El factorial de %.2f es: %li y El factorial de %.2f es: %li\n",numeroA,numeroFactoreadoA,numeroB,numeroFactoreadoB);
                }
                else if(banderaErrorFactorA==1&&banderaErrorFactorB==0)
                {
                    printf("No se puede sacar el factorial de %.2f y El factorial de %.2f es: %li\n",numeroA,numeroB,numeroFactoreadoB);
                }
                else if(banderaErrorFactorA==0&&banderaErrorFactorB==1)
                {
                    printf("El factorial de %.2f es: %li y No se puede sacar el factorial de %.2f\n",numeroA,numeroFactoreadoA,numeroB);
                }
                else
                {
                    printf("No se puede sacar el factorial de %.2f y No se puede sacar el factorial de %.2f\n\n",numeroA,numeroB);
                }
                system("pause");
            break;
            case 5:
                salir=preguntaSalir();
            break;

            default:
            break;
        }
        system("cls");
   }while(salir=='n');
    return 0;
}
