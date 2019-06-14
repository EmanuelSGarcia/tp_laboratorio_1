#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

/** \brief Nombre del alumno, curso y division.
 *
 */
void saludar();

/** \brief Muestra el menu pricipal y se modifica con las futuras funciones ingresadas.
 *
 * \param banderaNumeroFaltanteA int = Si falta (1)A no mostrara resultado.
 * \param numeroA float
 * \param banderaNumeroFaltanteB int = Si falta (1) B no mostrara resultado.
 * \param numeroB float
 * \param banderaCalculosFaltantes int = Si faltan (1) los calculos no mostrara confirmacion.
 *
 */
void mostrarMenu(int banderaNumeroFaltanteA,float numeroA,int banderaNumeroFaltanteB,float numeroB,int banderaCalculosFaltantes);

/** \brief solicita al usuario que ingrese un numero de opcion de el menu principal.
 *
 * \return la opcion del menu ya validada.
 *
 */
int opcionMenu();

/** \brief solicita al usuario que ingrese un numero a operar.
 *
 * \return el numero en float.
 *
 */
float pedirNumero();

/** \brief suma de el numero A y B
 *
 * \param numeroA float
 * \param numeroB float
 * \return La suma en numeros float.
 *
 */
float calcularSuma(float numeroA,float numeroB);

/** \brief resta de el numero A y B
 *
 * \param numeroA float
 * \param numeroB float
 * \return la resta en numeros float
 *
 */
float calcularDiferencia(float numeroA,float numeroB);

/** \brief verifica que el numero B no sea 0.
 *
 * \param divisor float
 * \return bandera 1(es 0) o 0(es diferente a 0)
 *
 */
float validarDivision(float divisor);

/** \brief division de el numero A por B.
 *
 * \param numeroA float
 * \param numeroB float
 * \return la division en float
 *
 */
float calcularDivision(float numeroA,float numeroB);

/** \brief multiplicacion de el numero A por B
 *
 * \param numeroA float
 * \param numeroB float
 * \return la multiplicacion en float
 *
 */
float calcularMultiplicacion(float numeroA,float numeroB);

/** \brief verifica que el numero no sea negativo y que no sea numero con parte.
 *
 * \param numeroEvaluado float
 * \return el numero en float sin parte decimal.
 *
 */
float validacionNumeroAFactorear(float numeroEvaluado);

/** \brief realiza el factor de un numero
 *
 * \param numeroAFactorear float
 * \return el numero factoreado en long
 *
 */
long factorizacionDeNumero(float numeroAFactorear);

/** \brief pregunta si el usuario desea salir.
 *
 * \return respuesta del usuario "s" o "n".
 *
 */
char preguntaSalir();

#endif // BIBLIOTECA_H_INCLUDED
