/*
 * Parser.c
 *
 *  Created on: 20 nov. 2021
 *      Author: adrian
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Arcades.h"

int paser_arcadeFromText(FILE* pFile,LinkedList* pArrayListArcade)
{
	int rtn =-1;
	Arcade* pArcade;
	char auxId[100];
	char auxNacionalidad[100];
	char auxTipoDeSonido[100];
	char auxCantidadJugadores[100];
	char auxCapacidadMaximaFichas[100];
	char auxNombreDeSalonAlQuePertenece[100];
	char auxNombreDelJuegoQueContiene[100];
	int banderaDelPrimero=1;
	int auxScanf;
	if(pFile!=NULL)
	{
		while(!feof(pFile))
		{
			if(banderaDelPrimero)
			{
				fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNacionalidad,auxTipoDeSonido,auxCantidadJugadores,auxCapacidadMaximaFichas,auxNombreDeSalonAlQuePertenece,auxNombreDelJuegoQueContiene);
				banderaDelPrimero=0;
			}
			auxScanf=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNacionalidad,auxTipoDeSonido,auxCantidadJugadores,auxCapacidadMaximaFichas,auxNombreDeSalonAlQuePertenece,auxNombreDelJuegoQueContiene);
			if(auxScanf==7)
			{
				pArcade=arcade_newParametros(auxId, auxNacionalidad, auxTipoDeSonido, auxCantidadJugadores, auxCapacidadMaximaFichas, auxNombreDeSalonAlQuePertenece, auxNombreDelJuegoQueContiene);
				ll_add(pArrayListArcade, pArcade);
				rtn=0;
			}
		}
	}
	return rtn;
}