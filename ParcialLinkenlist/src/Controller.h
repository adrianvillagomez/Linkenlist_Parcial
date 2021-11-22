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
int controller_addArcade(LinkedList* pArrayArcade);
int controller_asignarId(LinkedList* pArrayListArcade,int* numeroId);
int controller_listArcade(LinkedList* pArrayListArcade);
int controller_modificarArcade(LinkedList* pArrayListArcade);
int menuSeleccion();
int controller_imprimirJuegosSinRepetir(LinkedList* pArrayListArcades);
#endif /* CONTROLLER_H_ */
