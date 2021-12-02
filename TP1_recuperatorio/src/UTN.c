/*
 * UTN.c
 *
 *  Created on: 26 nov. 2021
 *      Author: adrian
 */

#include <stdio.h>
#include <stdlib.h>


int sumar(int operando1 , int operando2, int* resultado)
{
	int retorno = -1;
	*resultado = operando1 + operando2;
	retorno = 0;
	return retorno;
}

int restar (int operando1 , int operando2, int* resultado)
{
	int retorno = -1;
	*resultado = operando1 - operando2;
	retorno = 0;
	return retorno;
}
int multiplicar (int operando1 , int operando2, int* resultado)
{
	int retorno = -1;
	*resultado = operando1 * operando2;
	retorno = 0;
	return retorno;
}
int dividir  (int operando1 , int operando2, float* resultado)
{
	int retorno;
	retorno = -1;
	if(operando2 != 0)
	{
		*resultado = (float)operando1 / operando2;
		retorno = 0;
	}
	return retorno;
}
int sacarFactorial(int operando, int* resultado)
{
	int acumulador;
	int retorno;
	retorno = -1;
	acumulador = 1;
	if(operando==0)
	{
		*resultado=1;
		 retorno = 0;
	}else
	{
		if(operando>=1)
		{
		for(int i = 1;i <= operando;i++)
			{
				acumulador = acumulador * i;
				*resultado = acumulador;
			}
			retorno = 0;
		}
	}
	return retorno;
}
int Menu(int num1, int num2,int* rta)
{
	int retorno;
	retorno = -1;
	printf("\nCalculadora:  \n");
	printf("1. Ingresar 1er operando (A = %d) \n",num1);
	printf("2. Ingresar 2do operando (B = %d) \n",num2);
	printf("3. Calcular todas las operaciones \n");
	printf("4. Informar resultados \n");
	printf("5. Salir \n");
	scanf("%d", &(*rta));
	retorno = 0;
	return retorno;
}
