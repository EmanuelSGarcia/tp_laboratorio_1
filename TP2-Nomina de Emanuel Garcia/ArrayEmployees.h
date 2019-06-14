#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED


typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}eEmployee;


/** \brief Muestra datos del alumno
 * \return void
 */
void saludar();

/** \brief Muestra uno de los menus cargados
 * \param int la opcion del menu a mostrar
 * \return void
 */
void mostrarMenu(int);


/** \brief Devuelve un entero
 *
 * \param int numero minimo habil
 * \param int numero maximo habil
 * \return int la opcion seleccionada validada
 */
int opcionMenu(int,int);

/** \brief inicializa los empleados
 *
 * \param empleados[] eEmployee
 * \param tam int tamaño del array
 * \return void
 *
 */
void initEmployees(eEmployee empleados[], int tam);


/** \brief busca una pocicion libre en el array de empleados
 *
 * \param empleadoLibre[] eEmployee
 * \param tam int tamaño del array
 * \return int la posicion disponible
 *
 */
int buscarLibre(eEmployee empleadoLibre[],int tam);

/** \brief Añade un empleado nuevo
 *
 * \param empleados[] eEmployee
 * \param contador int el contador autoincremental que se reemplaza con el ID
 * \param tam int tamaño del array
 * \return int el autoincremental
 *
 */
int addEmployee(eEmployee empleados[],int contador,int tam);

/** \brief guarda el contador utilizado
 * \param contador int
 * \return int devuelve el contador modificado
 *
 */
int contadorIncrementalId(int contador);

/** \brief Pide un id al usuario y lo valida
 *
 * \return int el ID
 */
int pedirId();

/** \brief busca a un empleado por ID y verifica que exista
 *
 * \param empleados[] eEmployee
 * \param tam int tamaño del array
 * \return int la posicion del array del empleado.
 *
 */
int findEmployeeById(eEmployee empleados[],int tam);

/** \brief modifica un empleado existente
 *
 * \param empleado[] eEmployee
 * \param id int el id del empleado verificado
 * \return void
 */
void modificarEmpleado(eEmployee empleado[],int id);
/** \brief da de baja a un empleado
 *
 * \param empleado[] eEmployee
 * \param tam int tamaño del array
 * \return void
 *
 */
void bajaEmpleado(eEmployee empleado[],int tam);

/** \brief saca el promedio de los empleados que estan cargados
 *
 * \param empleados[] eEmployee
 * \param tam int tamaño del array
 * \return float el promedio
 *
 */
float sacarPromedio(eEmployee empleados[],int tam);
/** \brief saca el total de los sueldos de los empleados que estan cargados
 *
 * \param empleados[] eEmployee
 * \param tam int tamaño del array
 * \return float el total
 *
 */
float sacarTotales(eEmployee empleados[],int tam);
/** \brief muestra los totales y el promedio de los sueldos de los empleados
 *
 * \param empleados[] eEmployee
 * \param tam int tamaño del array
 * \return void
 *
 */
void mostrarListaTotalesYPromedio(eEmployee empleados[],int tam);

/** \brief calcula la cantidad de empleados que superan el promedio
 *
 * \param empleados[] eEmployee
 * \param tam int tamaño del array
 * \param promedio int el promedio de los totales
 * \return int la cantidad que superan
 *
 */
int cantidadSuperaPromedio(eEmployee empleados[],int tam,int promedio);
/** \brief Llama al menu que da con las opciones de listar
 *
 * \param empleados[] eEmployee
 * \param tam int tamaño del array
 * \return void
 *
 */
void listarEmpleados(eEmployee empleados[], int tam);
/** \brief ordena empleados por apellido y sector
 *
 * \param empleado[] eEmployee
 * \param tam int tamaño del array
 * \return void
 *
 */
void OrdenarEmpleados(eEmployee empleado[], int tam);
/** \brief muestra la lista de empleados
 *
 * \return void
 *
 */
void mostrarLista();
/** \brief muestra un empleado
 *
 * \param empleado eEmployee
 * \return void
 *
 */
void mostrarEmpleado(eEmployee empleado);
/** \brief muestra la lista con los empleados habiles
 *
 * \param empleado[] eEmployee
 * \param tam int tamaño del array
 * \return void
 *
 */
void mostrarListaOrdenada(eEmployee empleado[],int tam);

/** \brief valida que sea solo letras
 *
 * \param palabra[] char
 * \return int true (1) o false (0)
 *
 */
int validarPalabra(char palabra[]);



/** \brief Limpia la pantalla
 *
 * \return void
 *
 */
void limpiarPantalla();
/** \brief Establece una pausa
 *
 * \return void
 *
 */
void pausa();
/** \brief Limpia el buffer
 *
 * \return void
 *
 */
void limpiarBuffer();
#endif // BIBLIOTECA_H_INCLUDED
