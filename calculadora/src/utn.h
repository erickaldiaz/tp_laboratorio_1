/*
 * utn.h
 *
 *      Author: ericka.diaz
 */

#ifndef UTN_H_
#define UTN_H_
/**
 * getNumber es una función que pide un numero y verifica para luego devolver un resultado
 * @param pResult puntero que guarda el resultado
 * @param message puntero muestra un mensaje
 * @param errorMessage muestra un mensaje de error
 * @param minimum rango minimo aceptado
 * @param maximum rango máximo aceptado
 * @param retry reintentos en caso de error
 * @return retorna -1 en caso de error y 0 de exito
 */

int utn_getNumber(int* pResult, char* message, char* errorMessage, int minimum, int maximum, int retry);
/**
 * función para sumar dos números enteros o con decimales
 * @param numberA  float primer número ingresado
 * @param numberB float segundo número ingresado
 * @return retorna el resultado
 */
float sum(float numberA,float numberB);
/**
 * función para restar dos números enteros o decimales
 * @param numberA float primer número ingresado
 * @param numberB float segundo número ingresado
 * @return retorna la variable del resultado
 */
float subtraction(float numberA,float numberB);
/**
 * función para multiplicar dos números enteros o decimales
 * @param numberA float del primer número ingresado
 * @param numberB float segundo número ingresado
 * @return retorna la variable del resultado
 */
float multiply(float numberA,float numberB);
/**
 * función para dividir dos números enteros o decimales
 * @param pResultDivision puntero que almacena el resultado
 * @param numberA float primer número ingresado
 * @param numberB float del segundo número ingresado por el cual se dividirá
 * @return resultado
 */
float divide (float* pResultDivision,float numberA, float numberB);
/**
 * función para sacar el factorial de un número entero.
 * @param numberFactorial double parametro.Número del cual se busca su factorial.
 * @return resultado del factorial
 */
double factor(double numberFactorial);


#endif
