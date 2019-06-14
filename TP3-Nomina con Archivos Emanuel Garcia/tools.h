#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED
#include "LinkedList.h"


/** \brief Bienvenida
 *
 * \return void
 *
 */
void saludar();
/** \brief Muestra un menu y pide una opcion
 *
 * \param message[] char
 * \param minimo int
 * \param maximo int
 * \return char
 *
 */
char menu(char message[],int minimo,int maximo);

/** \brief busca un empleado por id
 *
 * \param this LinkedList* el array list
 * \return void* la estructura del empleado
 *
 */
void* buscarEmpleadoId(LinkedList* this);
/** \brief valida que sea un nombre
 *
 * \param nombreStr char* el nombre
 * \return int codigo error
 *
 */
int validarNombre(char* nombreStr);
/** \brief valida que sea numeros
 *
 * \param horas int
 * \return int codigo error
 *
 */
int validarHorasTrabajadas(int horas);
/** \brief valida que sea numero
 *
 * \param sueldo int
 * \return int codigo error
 *
 */
int validarSueldo(int sueldo);

/** \brief muestra opciones para el ordenamiento de el sort
 *
 * \param void
 * \return int el tipo de orden
 *
 */
int criterioDeOrdenamiento(void);

/** \brief contador auto incremental
 *
 * \param this LinkedList*
 * \return int el contador
 *
 */
int IdAutoIncremental(LinkedList* this);

/** \brief limpia buffer
 *
 * \param void
 * \return void
 *
 */
void limpiarBuffer(void);
/** \brief limpia pantalla
 *
 * \param void
 * \return void
 *
 */
void limpiarPantalla(void);
/** \brief una pausa
 *
 * \param
 * \param
 * \return
 *
 */
void pausa(void);

#endif // TOOLS_H_INCLUDED
