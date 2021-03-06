/*
 ============================================================================
 Name        : ParcialLinkenlist.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Validaciones.h"
#include "Arcades.h"
#include "Controller.h"
/****************************************************
    Menu:
        Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     1. Alta de arcade
     2. Modificar datos arcade
     3. Baja de arcade
     4. IMPRIMIR ARCADES ordenados por nombre de juego
     5. Generar archivo con JUEGOS
     6. Generar un archivo con arcades “Multijugador” (mas de 1 jugador)
     7. Actualizar cantidad de fichas.
    10. Salir
*****************************************************/
int main(void) {
	setbuf(stdout,NULL);
	int flag='y';
	LinkedList* listaArcades = ll_newLinkedList();
	controller_loadFromText("arcades.csv", listaArcades);

	do{
		switch(menu())
		{
			case 1:
				if(controller_addArcade(listaArcades)==0)
				{
					controller_saveAsText("arcades.csv", listaArcades);
					printf("Alta con exito!Imprima la lista para ver los cambios.\n\n");
				}else
				{
					printf("Algo salio mal con el Alta \n");
				}

				break;
			case 2:
				if(controller_modificarArcade(listaArcades)==0)
				{
					controller_saveAsText("arcades.csv", listaArcades);
				}else
				{
					printf("Algo salio mal con la modificacion \n");
				}
				break;
			case 3:
				if(controller_removeArcade(listaArcades)==0)
				{
				controller_saveAsText("arcades.csv", listaArcades);
				}else
				{
					printf("Algo salio mal con la baja \n");
				}

				break;
			case 4:
				if(controller_sortEmployee(listaArcades)==0)
				{
					printf("[--Ordenamiento exitoso--]\n");
				}
				break;
			case 5:
				if(controller_loadFromTextJuegos("juegos.txt",listaArcades)==0)
				{
					printf("[---Archivo de texto con todos los juegos sin repetir creado exitosamente---]\n");
				}
				break;
			case 6:
				if(controller_filtrarArcades(listaArcades)==0)
				{
					printf("[---Se Generar un archivo con arcades “Multijugador” (mas de 1 jugador)exitosamente---]\n");
				}
				break;
			case 7:
				if(controller_actualizarCantidadFichas(listaArcades)==0)
				{
					printf("[---se duplico el valor de cantidad de fichas de todos los arcades.---]\n");
				}
				break;
			case 8:
				controller_listArcade(listaArcades);
				break;
			case 9:
				flag = 'n';
				printf("Fin del programa\n");
				break;
		}
	}while(flag=='y');

	return EXIT_SUCCESS;
}
