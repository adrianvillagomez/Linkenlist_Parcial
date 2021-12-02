/*
 * UTN.h
 *
 *  Created on: 26 nov. 2021
 *      Author: adrian
 */

#ifndef UTN_H_
#define UTN_H_

/// @fn int sumar(int, int, int*)
/// @brief suma operando1 y operando2
/// @param int operando1,primer operando.
/// @param int operando2,segundo operando.
/// @param int* resultado, puntero al espacio de memoria donde se dejara  el valor obtenido.
/// @return (-1) Error / (0) Ok
int sumar(int operando1, int operando2, int* resultado);

/// @fn int restar(int, int, int*)
/// @brief resta operando1 y operando2
/// @param int operando1,primer operando.
/// @param int operando2,segundo operando.
/// @param int* resultado, puntero al espacio de memoria donde se dejara  el valor obtenido.
/// @return (-1) Error / (0) Ok
int restar(int operando1, int operando2, int* resultado);

/// @fn int multiplicar(int, int, int*)
/// @brief multiplica operando1 por operando2
/// @param int operando1, primer operando.
/// @param int operando2, segundo operando
/// @param int* resultado, puntero al espacio de memoria donde se dejara  el valor obtenido.
/// @return (-1) Error / (0) Ok
int multiplicar(int operando1, int operando2, int* resultado);

/// @fn int dividir(int, int, float*)
/// @brief divide operando1 con operando2
/// @param int operando1,primer operando.
/// @param int operando2,segundo operando.
/// @param float* resultado, puntero al espacio de memoria donde se dejara  el valor obtenido.
/// @return (-1) Error / (0) Ok
int dividir(int operando1, int operando2, float* resultado);

/// @fn int sacarFactorial(int, int*)
/// @brief saca el factorial de operando
/// @param int operando,operando del que sacamos el factorial.
/// @param int* resultado, puntero al espacio de memoria donde se dejara  el valor obtenido.
/// @return (-1) Error / (0) Ok
int sacarFactorial(int operando, int* resultado);
int Menu(int num1, int num2,int* rta);

#endif /* UTN_H_ */
