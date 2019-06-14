#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Reserva memoria para un empleado vacio
 *
 * \return Employee* la posicion del empleado
 *
 */
Employee* employee_new();

/** \brief Carga un empleado nuevo con los parametros asignados
 *
 * \param idStr char* el id
 * \param nombreStr char* el nombre
 * \param horasTrabajadasStr char* la horas
 * \param sueldo char* el sueldo
 * \return Employee* el empleado cargado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
/** \brief borra un empleado
 *
 * \return void
 *
 */
void employee_delete();

/** \brief asigna id a un empleado
 *
 * \param this Employee* el empleado
 * \param id int la id
 * \return int codigo error
 *
 */
int employee_setId(Employee* this,int id);

/** \brief obtiene la id del empleado
 *
 * \param this Employee* el empleado
 * \param id int* donde se aloja id
 * \return int codigo error
 *
 */
int employee_getId(Employee* this,int* id);
/** \brief asigna nombre a un empleado
 *
 * \param this Employee* el empleado
 * \param char int el nombre
 * \return int codigo error
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief obtiene el nombre del empleado
 *
 * \param this Employee* el empleado
 * \param char int* donde se aloja nombre
 * \return int codigo error
 *
 */
int employee_getNombre(Employee* this,char* nombre);
/** \brief asigna horas trabajadas a un empleado
 *
 * \param this Employee* el empleado
 * \param horasTrabajadas int las horas
 * \return int codigo error
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief obtiene las horasTrabajadas del empleado
 *
 * \param this Employee* el empleado
 * \param int* horasTrabajadas donde se alojan las horas
 * \return int codigo error
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/** \brief asigna sueldo a un empleado
 *
 * \param this Employee* el empleado
 * \param sueldo int el sueldo
 * \return int codigo error
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief obtiene el sueldo del empleado
 *
 * \param this Employee* el empleado
 * \param int* sueldo donde se alojan las horas
 * \return int codigo error
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief compara id entre dos empleados
 *
 * \param empleado1 void*
 * \param empleado2 void*
 * \return int valor de comparacion
 *
 */
int CompararId(void* empleado1 ,void* empleado2);
/** \brief compara el nombre entre dos empleados
 *
 * \param empleado1 void*
 * \param empleado2 void*
 * \return int valor de comparacion
 *
 */
int CompararNombre(void* empleado1 ,void* empleado2);
/** \brief compara el sueldo entre dos empleados
 *
 * \param empleado1 void*
 * \param empleado2 void*
 * \return int valor de comparacion
 *
 */
int CompararSueldo(void* empleado1 ,void* empleado2);
/** \brief compara las horas trabajadas entre dos empleados
 *
 * \param empleado1 void*
 * \param empleado2 void*
 * \return int valor de comparacion
 *
 */
int CompararHorasTrabajadas(void* empleado1 ,void* empleado2);


#endif // employee_H_INCLUDED
