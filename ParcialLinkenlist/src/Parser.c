/*
 * Parser.c
 *
 *  Created on: 20 nov. 2021
 *      Author: adrian
 */

#include <stdio.h>
#include <stdlib.h>
#include "Parser.h"

int parser_arcadeFromText(FILE* pFile,LinkedList* pArrayListArcade)
{
	int rtn =-1;
	Arcade* pArcade;
	char auxId[150];
	char auxNacionalidad[200];
	char auxTipoDeSonido[200];
	char auxCantidadJugadores[200];
	char auxCapacidadMaximaFichas[200];
	char auxNombreDeSalonAlQuePertenece[200];
	char auxNombreDelJuegoQueContiene[200];
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
				//printf("Lei: %s %s %s %s %s %s %s \n",auxId,auxNacionalidad,auxTipoDeSonido,auxCantidadJugadores,auxCapacidadMaximaFichas,auxNombreDeSalonAlQuePertenece,auxNombreDelJuegoQueContiene);
				pArcade=arcade_newParametros(auxId, auxNacionalidad, auxTipoDeSonido, auxCantidadJugadores, auxCapacidadMaximaFichas, auxNombreDeSalonAlQuePertenece, auxNombreDelJuegoQueContiene);
				//printf("id:%d\n",pArcade->id);
				if(pArcade!=NULL)
				{
				ll_add(pArrayListArcade, pArcade);
				rtn=0;
				}
			}
		}
	}
	return rtn;
}
