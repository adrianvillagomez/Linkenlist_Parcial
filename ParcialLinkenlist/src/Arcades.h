/*
 * Arcades.h
 *
 *  Created on: 20 nov. 2021
 *      Author: adrian
 */

#ifndef ARCADES_H_
#define ARCADES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

typedef struct
{
    int id;
    char nacionalidad[63];
    int tipoDeSonido;
    int cantidadJugadores;
    int capacidadMaximaFichas;
    char nombreDeSalonAlQuePertenece[63];
    char nombreDelJuegoQueContiene[63];
}Arcade;

Arcade* arcade_new(void);
Arcade* arcade_newParametros(char* id,char* nacionalidad,char* tipoDeSonido,char* cantidadJugadores,char* capacidadMaximaFichas,char* nombreDeSalonAlQuePertenece,char* nombreDelJuegoQueContiene);
int arcade_setId(Arcade* this,int id);
int arcade_getId(Arcade* this,int* id);
int arcade_setNacionalidad(Arcade* this,char* nombre);
int arcade_getNacionalidad(Arcade* this,char* nombre);
int arcade_setTipoDeSonido(Arcade* this,int TipoDeSonido);//..
int arcade_getTipoDeSonido(Arcade* this,int* TipoDeSonido);
int arcade_setCantidadJugadores(Arcade* this,int cantidadJugadores);
int arcade_getCantidadJugadores(Arcade* this,int* cantidadJugadores);
int arcade_setCapacidadMaximaFichas(Arcade* this,int capacidadMaximaFichas);
int arcade_getCapacidadMaximaFichas(Arcade* this,int* capacidadMaximaFichas);
int arcade_setNombreDeSalonAlQuePertenece(Arcade* this,char* nombreDeSalonAlQuePertenece);
int arcade_getNombreDeSalonAlQuePertenece(Arcade* this,char* nombreDeSalonAlQuePertenece);
int arcade_setNombreDelJuegoQueContiene(Arcade* this,char* nombreDelJuegoQueContiene);
int arcade_getNombreDelJuegoQueContiene(Arcade* this,char* nombreDelJuegoQueContiene);
int arcade_buscarPorId(LinkedList* pArrayListArcade,int id);
int arcade_setTipoSonidoStr(Arcade* this,char* tipoSonidostr);
int arcade_getTipoSonidostr(Arcade* this,char* tipoSonidoStr);
#endif /* ARCADES_H_ */
