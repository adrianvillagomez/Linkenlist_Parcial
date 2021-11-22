/*
 * Controller.c
 *
 *  Created on: 20 nov. 2021
 *      Author: adrian
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"

int controller_addArcade(LinkedList* pArrayArcade)
{
	int rtn = -1;
	Arcade* pArcade;
	char auxNacionalidad[63];
	int auxTipoDeSonido;
	int auxCantidadJugadores;
	int auxCapacidadMaximaFichas;
	char auxNombreDeSalonAlQuePertenece[63];
	char auxNombreDelJuegoQueContiene[63];
	int auxId;
	pArcade=arcade_new();
	if(pArcade!=NULL && pArrayArcade!=NULL && auxNacionalidad!=NULL && auxNombreDeSalonAlQuePertenece!=NULL && auxNombreDelJuegoQueContiene!=NULL)
	{
		if(utn_getNombre(auxNacionalidad, 63, "Ingrese un nacionalidad: \n","Dato incorrecto\n",5)==0)
		{
			if(utn_getNumero(&auxTipoDeSonido, "Ingrese el tipo de Sonido: [1]Para Stereo [2]Para Mono \n", "Tipo de Sonido incorrecto \n", 1, 2, 5)==0)
			{
				if(utn_getNumero(&auxCantidadJugadores, "Ingrese Cantidad de Jugadores\n", "Dato invalido\n", 1, 50, 5)==0)
				{
					if(utn_getNumero(&auxCapacidadMaximaFichas, "Ingrese capacidad maxima de fichas\n", "Dato invalido\n", 1, 50, 5)==0)
					{
						if(utn_getText(auxNombreDeSalonAlQuePertenece, 63,"Ingrese nombre de salon al que pertenece:\n", "Dato invalido\n",5)==0)
						{
							if(utn_getText(auxNombreDelJuegoQueContiene, 63, "Ingrese nombre del juego:\n", "Dato invalido\n", 5)==0)
							{
								controller_asignarId(pArrayArcade,&auxId);
								arcade_setId(pArcade, auxId);
								arcade_setNacionalidad(pArcade, auxNacionalidad);
								arcade_setTipoDeSonido(pArcade, auxTipoDeSonido);
								arcade_setCantidadJugadores(pArcade, auxCantidadJugadores);
								arcade_setCapacidadMaximaFichas(pArcade, auxCapacidadMaximaFichas);
								arcade_setNombreDeSalonAlQuePertenece(pArcade, auxNombreDeSalonAlQuePertenece);
								arcade_setNombreDelJuegoQueContiene(pArcade, auxNombreDelJuegoQueContiene);
								ll_add(pArrayArcade,pArcade);
								rtn=0;
							}
						}
					}
				}
			}
		}
	}


	return rtn;
}
int controller_asignarId(LinkedList* pArrayListArcade,int* numeroId)
{
	int rtn=-1;
	Arcade* pArcade;
	int i;
	int idAux;
	if(pArrayListArcade!=NULL)
	{
		if(ll_len(pArrayListArcade)==0)
		{
			*numeroId=501;
		}else
		{
			for(i=0;i<ll_len(pArrayListArcade);i++)
			{
				pArcade=ll_get(pArrayListArcade, i);
				arcade_getId(pArcade, &idAux);
				if(i==0||*numeroId<idAux)
				{
					*numeroId=idAux;
				}
			}
			*numeroId+=1;
			rtn=0;
		}
	}
	return rtn;
}
int controller_listArcade(LinkedList* pArrayListArcade)
{
		Arcade *pArcade;
		int rtn = -1;
		char auxNacionalidad[63];
		int auxTipoDeSonido;
		int auxCantidadJugadores;
		int auxCapacidadMaximaFichas;
		char auxNombreDeSalonAlQuePertenece[63];
		char auxNombreDelJuegoQueContiene[63];
		int auxId;

		if (pArrayListArcade == NULL)
		{
			printf("\n No hay empleados para listar.\n");
		} else
		{
			printf("    _______________________________________________________________________________________________________________________________________________________________________        \n"
				   "      ID     Nacionalidad       Tipo de Sonido	  Cantidad jugadores   Capacidad Maxima de fichas   Nombre de salon al que pertence   Nombre del juego que contiene         \n"
				   "    _______________________________________________________________________________________________________________________________________________________________________        \n");
			rtn = 0;

			for (int i = 0; i < ll_len(pArrayListArcade); i++) {
				pArcade= ll_get(pArrayListArcade, i);
				arcade_getNacionalidad(pArcade, auxNacionalidad);
				arcade_getTipoDeSonido(pArcade, &auxTipoDeSonido);
				arcade_getCantidadJugadores(pArcade, &auxCantidadJugadores);
				arcade_getCapacidadMaximaFichas(pArcade, &auxCapacidadMaximaFichas);
				arcade_getNombreDeSalonAlQuePertenece(pArcade, auxNombreDeSalonAlQuePertenece);
				arcade_getNombreDelJuegoQueContiene(pArcade, auxNombreDelJuegoQueContiene);
				arcade_getId(pArcade,&auxId);
				switch(auxTipoDeSonido)
				{
				case 1:
					printf("    [%4d] [%10s]             [STEREO]        [%10d]         [%10d]                [%10s]                      [%10s]\n",auxId,auxNacionalidad,auxCantidadJugadores,auxCapacidadMaximaFichas,auxNombreDeSalonAlQuePertenece,auxNombreDelJuegoQueContiene);
					break;
				case 2:
					printf("    [%4d] [%10s]             [MONO]        [%10d]         [%10d]                  [%10s]                        [%10s]\n",auxId,auxNacionalidad,auxCantidadJugadores,auxCapacidadMaximaFichas,auxNombreDeSalonAlQuePertenece,auxNombreDelJuegoQueContiene);
					break;
				}

				//printf("    [%4d] [%10s]             [%10d]        [%10d]         [%10d]                [%10s]                   [%10s]\n",auxId,auxNacionalidad,auxTipoDeSonido,auxCantidadJugadores,auxCapacidadMaximaFichas,auxNombreDeSalonAlQuePertenece,auxNombreDelJuegoQueContiene);
			}
		}
		return rtn;
}
int controller_modificarArcade(LinkedList* pArrayListArcade)
{
	int rtn =-1;
	Arcade* pArcade;
	int auxId;
	int idEncontrado;
	char opcionFlag = 'y';
	int auxCantidadJugadores;
	char auxJuegoQueContiene[63];
	if(pArrayListArcade!=NULL)
	{
		controller_listArcade(pArrayListArcade);
		if(utn_getNumero(&auxId,"\nIngrese el ID a modificar: ","ID invalido \n", 0,1000,5)==0)
		{
			idEncontrado=arcade_buscarPorId(pArrayListArcade, auxId);
			if(idEncontrado==-1)
			{
				printf("Error ID no encontrado.\n\n");
			}else
			{
				pArcade=ll_get(pArrayListArcade, idEncontrado);
				do{
					switch(menuSeleccion())
					{
					case 1:
						if(utn_getNumero(&auxCantidadJugadores,"Ingrese nueva cantidad de jugadores:  ", "Dato invalido\n", 1, 50,5)==0)
						{
							arcade_setCantidadJugadores(pArcade, auxCantidadJugadores);
							printf("Cantidad de jugadores actualizado con exito!!.Imprima la lista para ver los cambios\n");
							rtn=0;
							opcionFlag='n';
						}
						break;
					case 2:
							printf("Listado de Todos los juegos cargados en el sistema sin repetir\n");
							controller_imprimirJuegosSinRepetir(pArrayListArcade);
							if(utn_getNombre(auxJuegoQueContiene,63,"Ingrese un nuevo juego o eliga uno ya existente: ","Dato invalido\n",5)==0)
							{
								arcade_setNombreDelJuegoQueContiene(pArcade, auxJuegoQueContiene);
								printf("Juego actualizado con exito!!.Imprima la lista para ver los cambios\n");
								rtn=0;
								opcionFlag='n';
							}
						break;
					case 3:
						printf("\n Operacion cancelada\n");
						opcionFlag='n';
						rtn=0;
						break;
					}

				}while(opcionFlag=='y');
			}
		}
	}

	return rtn;
}
int controller_imprimirJuegosSinRepetir(LinkedList* pArrayListArcades)
{
	int rtn=-1;
	Arcade* pArcade;
	Arcade* pArcadej;
	int i;
	int j;
	int flag;
	char auxi[63];
	char auxj[63];
	if(pArrayListArcades!=NULL)
	{
		for(i=0;i<ll_len(pArrayListArcades);i++)
		{
			//flag=0;
			pArcade=ll_get(pArrayListArcades, i);
			arcade_getNombreDelJuegoQueContiene(pArcade, auxi);
			flag=0;
			for(j=i+1; j<ll_len(pArrayListArcades);j++)
			{
				pArcadej=ll_get(pArrayListArcades, j);
				arcade_getNombreDelJuegoQueContiene(pArcadej, auxj);
				if(strcmp(auxi,auxj)==0)
				{
					flag=1;
				}
			}
			if(flag==0)
			{
				printf("%s \n",auxi);
			}
		}
	}

	return rtn;
}
int menuSeleccion()
{
	int opcionElegida;
	printf( "\n    [Menu de Modificacion] :"
			"\n    [1] Modificar Cantidad de jugadores."
			"\n    [2] Modificar Juegos que contiene."
			"\n    [3] Cancelar.\n");
	utn_getNumero(&opcionElegida, " Eliga la opcion a operar [1-3]: ",
			"Error, opcion incorrecta.", 1, 3, 5);
	return opcionElegida;
}