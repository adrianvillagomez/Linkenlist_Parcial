/*
 * Arcades.c
 *
 *  Created on: 20 nov. 2021
 *      Author: adrian
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Validaciones.h"
#include "Arcades.h"

Arcade* arcade_new()
{
	Arcade* pArcade = malloc(sizeof(Arcade));
	return pArcade;
}
Arcade* arcade_newParametros(char* id,char* nacionalidad,char* tipoDeSonido,char* cantidadJugadores,char* capacidadMaximaFichas,char* nombreDeSalonAlQuePertenece,char* nombreDelJuegoQueContiene)
{
	Arcade* pArcade;
	pArcade=arcade_new();
	if(pArcade!=NULL &&id!=NULL&&nacionalidad!=NULL&&tipoDeSonido!=NULL&&cantidadJugadores!=NULL&&capacidadMaximaFichas!=NULL&&nombreDeSalonAlQuePertenece!=NULL&&nombreDelJuegoQueContiene!=NULL)
	{
		arcade_setId(pArcade, atoi(id));
		arcade_setNacionalidad(pArcade, nacionalidad);
		//arcade_setTipoDeSonido(pArcade,atoi(tipoDeSonido));
		arcade_setTipoSonidoStr(pArcade, tipoDeSonido);
		arcade_setCantidadJugadores(pArcade, atoi(cantidadJugadores));
		arcade_setCapacidadMaximaFichas(pArcade, atoi(capacidadMaximaFichas));
		arcade_setNombreDeSalonAlQuePertenece(pArcade, nombreDeSalonAlQuePertenece);
		arcade_setNombreDelJuegoQueContiene(pArcade, nombreDelJuegoQueContiene);
	}
	return pArcade;
}
int arcade_setTipoSonidoStr(Arcade* this,char* tipoSonidostr)
{
	int retorno = -1;
	    int tipo;
	    if(this != NULL && tipoSonidostr!=NULL)
	    {
	        if(strnicmp("MONO",tipoSonidostr,63)==0)
	        {
	           tipo=2;
	           this->tipoDeSonido=tipo;
	           retorno=0;
			}
			if(strnicmp("STEREO",tipoSonidostr,63)==0)
			{
				tipo=1;
			   this->tipoDeSonido=tipo;
			   retorno=0;
			}
	    }
	    return retorno;
}
int arcade_getTipoSonidostr(Arcade* this,char* tipoSonidoStr)
{
	int retorno=-1;
	if(this!=NULL && tipoSonidoStr!=NULL)
	{
		retorno=0;
		sprintf(tipoSonidoStr,"%d",this->tipoDeSonido);

	}

	return retorno;
}
void arcade_delete(Arcade* this)
{
	if(this!=NULL)
		{
			free(this);
		}
}
int arcade_setId(Arcade* this,int id)
{
	int rtn=-1;
		if(this!=NULL && id >=0)
		{
			this->id=id;//asignacion
			rtn=0;
		}
		return rtn;
}
int arcade_getId(Arcade* this,int* id)//para pedir el id
{
	int rtn =-1;
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;//lectura
		rtn=0;
	}
	return rtn;
}
int arcade_setNacionalidad(Arcade* this,char* nacionalidad)
{
	int rtn =-1;
	if(this!=NULL&& nacionalidad!=NULL)
	{
		strncpy(this->nacionalidad,nacionalidad,sizeof(this->nacionalidad));
		rtn=0;
	}
	return rtn;
}
int arcade_getNacionalidad(Arcade* this,char* nacionalidad)
{
	int rtn =-1;
	if(this !=NULL && nacionalidad!=NULL)
	{
		strncpy(nacionalidad,this->nacionalidad,63);
		rtn=0;
	}
	return rtn;
}
int arcade_setTipoDeSonido(Arcade* this,int TipoDeSonido)
{
	int rtn =-1;
		if(this!=NULL && TipoDeSonido>=0)
		{
			this->tipoDeSonido=TipoDeSonido;
			rtn=0;
		}
		return rtn;
}
int arcade_getTipoDeSonido(Arcade* this,int* TipoDeSonido)
{
	int rtn =-1;
		if(this!=NULL && TipoDeSonido!=NULL)
		{
			*TipoDeSonido=this->tipoDeSonido;
			rtn=0;

		}
		return rtn;
}
int arcade_setCantidadJugadores(Arcade* this,int cantidadJugadores)
{
	int rtn=-1;
	if(this!=NULL && cantidadJugadores>=0)
	{
		this->cantidadJugadores=cantidadJugadores;
		rtn=0;
	}
	return rtn;
}
int arcade_getCantidadJugadores(Arcade* this,int* cantidadJugadores)
{
	int rtn=-1;
	if(this!=NULL && cantidadJugadores>=0)
	{
		*cantidadJugadores=this->cantidadJugadores;
		rtn=0;
	}
	return rtn;
}
int arcade_setCapacidadMaximaFichas(Arcade* this,int capacidadMaximaFichas)
{
	int rtn=-1;
	if(this!=NULL && capacidadMaximaFichas>=0)
	{
		this->capacidadMaximaFichas=capacidadMaximaFichas;
		rtn=0;
	}
	return rtn;
}
int arcade_getCapacidadMaximaFichas(Arcade* this,int* capacidadMaximaFichas)
{
	int rtn=-1;
	if(this!=NULL && capacidadMaximaFichas>=0)
	{
		*capacidadMaximaFichas=this->capacidadMaximaFichas;
		rtn=0;
	}
	return rtn;
}
int arcade_setNombreDeSalonAlQuePertenece(Arcade* this,char* nombreDeSalonAlQuePertenece)
{
	int rtn =-1;
	if(this!=NULL&& nombreDeSalonAlQuePertenece!=NULL)
	{
		strncpy(this->nombreDeSalonAlQuePertenece,nombreDeSalonAlQuePertenece,sizeof(this->nombreDeSalonAlQuePertenece));
		rtn=0;
	}
	return rtn;
}
int arcade_getNombreDeSalonAlQuePertenece(Arcade* this,char* nombreDeSalonAlQuePertenece)
{
	int rtn =-1;
	if(this !=NULL && nombreDeSalonAlQuePertenece!=NULL)
	{
		strncpy(nombreDeSalonAlQuePertenece,this->nombreDeSalonAlQuePertenece,63);
		rtn=0;
	}
	return rtn;
}
int arcade_setNombreDelJuegoQueContiene(Arcade* this,char* nombreDelJuegoQueContiene)
{
	int rtn =-1;
	if(this!=NULL&& nombreDelJuegoQueContiene!=NULL)
	{
		strMinuscula(nombreDelJuegoQueContiene);
		strncpy(this->nombreDelJuegoQueContiene,nombreDelJuegoQueContiene,sizeof(this->nombreDelJuegoQueContiene));
		rtn=0;
	}
	return rtn;
}
int arcade_getNombreDelJuegoQueContiene(Arcade* this,char* nombreDelJuegoQueContiene)
{
	int rtn =-1;
	if(this !=NULL && nombreDelJuegoQueContiene!=NULL)
	{
		strncpy(nombreDelJuegoQueContiene,this->nombreDelJuegoQueContiene,63);
		rtn=0;
	}
	return rtn;
}
int arcade_buscarPorId(LinkedList* pArrayListArcade,int id)
{
	int rtn=-1;
	Arcade* pArcade;
	int i;
	int idAux;
	for(i=0;i<ll_len(pArrayListArcade);i++)
	{
		pArcade=ll_get(pArrayListArcade, i);
		if(arcade_getId(pArcade, &idAux)==0 && idAux==id)
		{
			rtn=i;
		}
	}

	return rtn ;
}
