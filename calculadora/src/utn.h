/*
 * utn.h
 *
 *      Author: ericka.diaz
 */

#ifndef UTN_H_
#define UTN_H_
/**
 * getNumber es una funci�n que pide un numero y verifica para luego devolver un resultado
 * @param pResult puntero que guarda el resultado
 * @param message puntero muestra un mensaje
 * @param errorMessage muestra un mensaje de error
 * @param minimum rango minimo aceptado
 * @param maximum rango m�ximo aceptado
 * @param retry reintentos en caso de error
 * @return retorna -1 en caso de error y 0 de exito
 */

int utn_getNumber(int* pResult, char* message, char* errorMessage, int minimum, int maximum, int retry);
/**
 * funci�n para sumar dos n�meros enteros o con decimales
 * @param numberA  float primer n�mero ingresado
 * @param numberB float segundo n�mero ingresado
 * @return retorna el resultado
 */
float sum(float numberA,float numberB);
/**
 * funci�n para restar dos n�meros enteros o decimales
 * @param numberA float primer n�mero ingresado
 * @param numberB float segundo n�mero ingresado
 * @return retorna la variable del resultado
 */
float subtraction(float numberA,float numberB);
/**
 * funci�n para multiplicar dos n�meros enteros o decimales
 * @param numberA float del primer n�mero ingresado
 * @param numberB float segundo n�mero ingresado
 * @return retorna la variable del resultado
 */
float multiply(float numberA,float numberB);
/**
 * funci�n para dividir dos n�meros enteros o decimales
 * @param pResultDivision puntero que almacena el resultado
 * @param numberA float primer n�mero ingresado
 * @param numberB float del segundo n�mero ingresado por el cual se dividir�
 * @return resultado
 */
float divide (float* pResultDivision,float numberA, float numberB);
/**
 * funci�n para sacar el factorial de un n�mero entero.
 * @param numberFactorial double parametro.N�mero del cual se busca su factorial.
 * @return resultado del factorial
 */
double factor(double numberFactorial);


#endif
