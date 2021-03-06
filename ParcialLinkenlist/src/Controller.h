/*
 * Controller.h
 *
 *  Created on: 20 nov. 2021
 *      Author: adrian
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Arcades.h"
#include "Validaciones.h"
#define STEREO 1
#define MONO 2
int controller_loadFromText(char* path , LinkedList* pArrayListArcade);
int controller_addArcade(LinkedList* pArrayArcade);
int controller_asignarId(LinkedList* pArrayListArcade,int* numeroId);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_listArcade(LinkedList* pArrayListArcade);
int controller_modificarArcade(LinkedList* pArrayListArcade);
int menuSeleccion();
int controller_imprimirJuegosSinRepetir(LinkedList* pArrayListArcades);
int controller_removeArcade(LinkedList* pArrayListArcade);
int controller_loadFromTextJuegos(char* path , LinkedList* pArrayListArcade);
int controller_sortEmployee(LinkedList* pArrayListArcade);
int OrdenamientoPorNombre(void* juegoZ, void* juegoX);
int controller_filtrarArcades(LinkedList* pArrayalistArcade);
int archivo_Multijugador(void* pArrayalistArcade);
int controller_actualizarCantidadFichas(LinkedList* pArraylistaArcade);
void fichasDuplicadas(void* pArrayalistArcade);
int menu();
#endif /* CONTROLLER_H_ */
