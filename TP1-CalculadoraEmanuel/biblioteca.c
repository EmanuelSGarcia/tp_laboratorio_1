#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "biblioteca.h"

void saludar()
{
    printf("  UTN \t\t\tCalculadora de Emanuel S Garcia\t\t\t  FRA\n\t\t\tProgramacion 1-TP 1, division B\n________________________________________________________________________________\n");
}

void mostrarMenu(int banderaNumeroFaltanteA,float numeroA,int banderaNumeroFaltanteB,float numeroB,int banderaCalculosFaltantes)
{
    if(banderaNumeroFaltanteA==0)
    {
        printf(" 1.\tIngresar 1er operando: \n");
    }
    else
    {
        printf(" 1.\tIngresar 1er operando:                   Su 1er operando es: %f \n",numeroA);
    }
    if(banderaNumeroFaltanteB==0)
    {
        printf(" 2.\tIngresar 2do operando: \n");
    }
    else
    {
        printf(" 2.\tIngresar 2do operando:                   Su 2do operando es: %f \n",numeroB);
    }


    if(banderaCalculosFaltantes==0)
    {
        printf(" 3.\tCalcular todas las operaciones.\n");
    }
    else
    {
        printf(" 3.\tCalcular todas las operaciones.          HECHO\n");
    }
    printf(" 4.\tInformar resultados.\n");
    printf(" 5.\tSalir.\n\n");
}

int opcionMenu()
{
    int respuesta;

    printf("Elija una opcion: ");
    fflush(stdin);
    scanf("%d",&respuesta);
    while(respuesta<1||respuesta>5)
    {
        printf("\nOpcion incorrecta,seleccione nuevamente: [1-5]");
        fflush(stdin);
        scanf("%d",&respuesta);
    }
    return respuesta;
}

float pedirNumero()
{
    float numeroIngresado;

    printf("Ingrese su numero a operar: ");
    scanf("%f",&numeroIngresado);

    return numeroIngresado;
}

float calcularSuma(float numeroA,float numeroB)
{
    float resultado;
    resultado=numeroA+numeroB;
    return resultado;
}

float calcularDiferencia(float numeroA,float numeroB)
{
    float resultado;
    resultado=numeroA-numeroB;
    return resultado;
}

float validarDivision(float divisor)
{
    if(divisor==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

float calcularDivision(float numeroA,float numeroB)
{
    float resultado;
    resultado=numeroA/numeroB;
    return resultado;
}

float calcularMultiplicacion(float numeroA,float numeroB)
{
    float resultado;
    resultado=numeroA*numeroB;

    return resultado;
}

float validacionNumeroAFactorear(float numeroEvaluado)
{
    float pasajeAEntero;
    float validacionFactor;

    pasajeAEntero=(int)numeroEvaluado;
    validacionFactor=pasajeAEntero/numeroEvaluado;

    if(numeroEvaluado<0)
    {
      return 1;
    }
    else
    {
        if(validacionFactor==1||validacionFactor==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

long factorizacionDeNumero(float numeroAFactorear)
{
    if(numeroAFactorear==1||numeroAFactorear==0)
    {
        return 1;
    }
    else
    {
        return numeroAFactorear*factorizacionDeNumero(numeroAFactorear-1);
    }
}

char preguntaSalir()
{
    char respuesta;

    printf("\nSeguro desea salir?");
    fflush(stdin);
    scanf("%c",&respuesta);
    respuesta=tolower(respuesta);

    while(respuesta!='n'&&respuesta!='s')
    {
        printf("\nOpcion incorrecta, reintente con una valida [s/n] : ");
        fflush(stdin);
        scanf("%c",&respuesta);
        respuesta=tolower(respuesta);
    }
    return respuesta;
}
