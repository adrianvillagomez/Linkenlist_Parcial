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
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Alta de arcade
     3. Modificar datos arcade
     5. Baja de arcade
     6. Listar arcades
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data2.dat (modo binario).
    10. Salir
*****************************************************/
int main(void) {
	setbuf(stdout,NULL);
	LinkedList* listaArcades = ll_newLinkedList();
	int opcion;
	do{
		switch(opcion)
		{
			case 1:
				break;
			case 2:
				controller_addArcade(listaArcades);
				break;
			case 3:
				controller_listArcade(listaArcades);
				break;
			case 4:
				controller_modificarArcade(listaArcades);
				break;
			case 5:
				controller_imprimirJuegosSinRepetir(listaArcades);
				break;
		}
	utn_getNumero(&opcion, "Ingrese una opcion de l-10: ", "Dato invalido \n", 1, 10, 5);
	}while(opcion!=10);



	//salon no id --no abm-- campo salon como un campo entra de salone
	// ojo con el 6
	return EXIT_SUCCESS;
}
