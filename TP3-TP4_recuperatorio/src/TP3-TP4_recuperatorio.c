/*
 ============================================================================
 Name        : TP3-TP4_recuperatorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Validaciones.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data2.dat (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data2.dat (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);
	char respuesta='y';
	LinkedList* listaEmpleados = ll_newLinkedList();
	int flag =0;
	    do{
	        switch(menu())
	        {
	            case 1:
	                controller_loadFromText("data.csv",listaEmpleados);
	                printf("Carga desde archivo de texto realizada con exito.\n");
	                flag=1;
	                break;
	            case 2:
	            	controller_loadFromBinary("data.dat", listaEmpleados);
	            	printf("Carga desde archivo binario realizada con exito.\n");
	            	flag=1;
	            	break;
	            case 3:
	            	if(flag==1)
	            	{
	            		if(controller_addEmployee(listaEmpleados)==0)
	            		{
	            		printf("Alta exitosa.\n");
	            		}
	            	}else
	            	{
	            		printf("Opcion invalida primero realize la carga desde el archivo de texto.\n");
	            	}
	            	break;
	            case 4:
	            	if(flag==1)
	            	{
	            		if(controller_editEmployee(listaEmpleados)==0)
	            		{
	            			printf("Modificacion de datos exitosa.\n");
	            		}
	            	}else
	            	{
	            		printf("Opcion invalida primero realize la carga desde el archivo de texto.\n");
	            	}
	            	break;
	            case 5:
	            	if(flag==1)
	            	{
	            		if(controller_removeEmployee(listaEmpleados)==0)
	            		{
	            			printf("Baja exitosa.\n");
	            		}
	            	}else
	            	{
	            		printf("Opcion invalida primero realize la carga desde el archivo de texto.\n");
	            	}
	            	break;
	            case 6:
	            	if(flag==1)
	            	{
	            		controller_ListEmployee(listaEmpleados);
	            	}else
	            	{
	            		printf("Opcion invalida primero realize la carga desde el archivo de texto.\n");
	            	}
	            	break;
	            case 7:
	            	if(flag==1)
	            	{
	            		controller_sortEmployee(listaEmpleados);
	            	}else
	            	{
	            		printf("Opcion invalida primero realize la carga desde el archivo de texto.\n");
	            	}
	            	break;
	            case 8:
	            	if(flag==1)
	            	{
	            		if(controller_saveAsText("data.csv",listaEmpleados)==0)
	            		{
	            			printf("Datos guardados correctamente.\n");
	            		}
	            	}else
	            	{
	            		printf("Opcion invalida primero realize la carga desde el archivo de texto.\n");
	            	}
	            	break;
	            case 9:
	            	if(flag==1)
	            	{
	            		if(controller_saveAsBinary("data.dat", listaEmpleados)==0)
	            		{
	            			printf("Datos guardados correctamente.\n");
	            		}
	            	}else
	            	{
	            		printf("Opcion invalida primero realize la carga desde el archivo de texto.\n");
	            	}
	            	break;
	            case 10:
	            	respuesta='n';
	            	printf("Fin del programa.\n");
	            	break;
	            }
	    }while(respuesta=='y');

	return EXIT_SUCCESS;
}
