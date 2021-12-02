/*
 ============================================================================
 Name        : TP1_recuperatorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"
int main(void) {
	setbuf(stdout,NULL);
	char respuesta='n';
	int retornoMenu;
	int num1=0;
	int num2=0;
	int rta;
	int flag=0;
	int flag1=0;
	int flag2=0;
	int retornoSuma;
	int retornoResta;
	int retornoDivision;
	int retornoMultiplicacion;
	int retornoFactorialUno;
	int retornoFactorialDos;
	int resultadoSuma;
	int resultadoMultiplicacion;
	int resultadoRestar;
	float resultadoDivision;
	int resultadoFactorialUno;
	int resultadoFactorialDos;

	do
	{
		retornoMenu=Menu(num1, num2,&rta);
		if(retornoMenu==0)
		{
			switch(rta)
			{
			case 1:
				printf("Ingrese el primer numero: ");
				scanf("%d",&num1);
				flag=1;
				break;
			case 2:
				if(flag==1)
				{
					printf("Ingrese el segundo numero: ");
					scanf("%d",&num2);
					flag1=1;
				}else
				{
					printf("Error,ingrese el primer operando\n");
				}
				break;
			case 3:
				if(flag==1&&flag1==1)
				{
					retornoSuma=sumar(num1,num2,&resultadoSuma);
					retornoResta=restar(num1,num2,&resultadoRestar);
					retornoDivision=dividir(num1,num2,&resultadoDivision);
					retornoMultiplicacion=multiplicar(num1,num2,&resultadoMultiplicacion);
					retornoFactorialUno=sacarFactorial(num1,&resultadoFactorialUno);
					retornoFactorialDos=sacarFactorial(num2, &resultadoFactorialDos);
					flag2=1;
					printf("Operaciones calculadas con exito presione 4 para ver los resultados.\n");
				}else
				{
					printf("Error,ingrese Operandos\n");
				}
				break;
			case 4:
				if(flag == 1 && flag1 == 1 && flag2 == 1)
				{
					if(retornoSuma == 0)
					{
						printf("El resultado de %d + %d es : %d \n", num1, num2,resultadoSuma);
					}
					else
					{
						printf("No se pudo hacer la suma.\n ");
					}
					if(retornoResta == 0)
					{
						printf("El resultado de %d - %d es : %d \n", num1, num2,resultadoRestar);
					}
					else
					{
						printf("No se pudo hacer la resta\n");
					}
					if(retornoDivision == 0)
					{
						printf("El resultado de %d / %d es : %.2f \n", num1, num2,resultadoDivision);
					}
					else
					{
						printf("No es posible dividir por 0\n");
					}
					if(retornoMultiplicacion == 0)
					{
						printf("El resultado de %d * %d es : %d \n", num1, num2,resultadoMultiplicacion);
					}
					else
					{
						printf("No se pudo hacer la multiplicación\n");
					}
					if(retornoFactorialUno == 0)
					{
						printf("El factorial de %d es %d y ",num1,resultadoFactorialUno);
					}
					else
					{
						printf("No es posible calcular el factorial de numeros negativos.\n ");
					}
					if(retornoFactorialDos== 0)
					{
						printf("El factorial de %d es %d \n",num2,resultadoFactorialDos);
					}
					else
					{
						printf("No es posible calcular el factorial de numeros negativos.\n");
					}
				}
				else
				{
					printf("Error, falta la opcion [3]Calcular todas las operaciones.\n");
				}
				break;
			case 5:
				respuesta='y';
				printf("Fin del programa. \n");
				break;
			default:
				printf("Dato invalido ingrese una opcion entre [1-5]\n");
				respuesta='n';
				break;
			}

		}

	}while(respuesta=='n');


	return EXIT_SUCCESS;
}
