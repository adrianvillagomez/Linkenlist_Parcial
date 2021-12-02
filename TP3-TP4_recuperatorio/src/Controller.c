#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Validaciones.h"
#include "parser.h"
#include "Controller.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	int rtn=-1;
	pArchivo=fopen(path,"r");
	if(pArchivo!=NULL && pArrayListEmployee!=NULL)
	{
		parser_EmployeeFromText(pArchivo, pArrayListEmployee);
		fclose(pArchivo);
		rtn=0;
	}

    return rtn;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	int rtn=-1;
	pArchivo=fopen(path,"rb");
	if(pArchivo!=NULL)
	{
		parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
		rtn=0;
		fclose(pArchivo);
	}

    return rtn;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int rtn=-1;
	Employee* auxEmpleado;
	char auxNombre[50];
	int auxSueldo;
	int auxHorasTrabajadas;
	int id;

	auxEmpleado=employee_new();
	if(pArrayListEmployee != NULL && auxEmpleado != NULL)
	{
		if(utn_getNombre(auxNombre, 50, "Ingrese Nombre\n","Error", 2)==0)
		{
			if(utn_getNumero(&auxSueldo, "Ingrese el sueldo\n", "Error dato invalido: 0-5000", 0, 5000, 2)==0)
			{
				if(utn_getNumero(&auxHorasTrabajadas, "Ingrese Horas Trabajadas\n","Error dato invalido: 0-120",0,120,2)==0)
				{
					controller_asignarId(pArrayListEmployee, &id);
					employee_setId(auxEmpleado,id);
					employee_setNombre(auxEmpleado, auxNombre);
					employee_setSueldo(auxEmpleado, auxSueldo);
					employee_setHorasTrabajadas(auxEmpleado, auxHorasTrabajadas);

					ll_add(pArrayListEmployee, auxEmpleado);

					rtn=0;
				}
			}
		}

	}

    return rtn;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int rtn=-1;
	Employee* pEmployee;
	int auxId;
	int posicionValida;
	int opcion;
	char nombre[50];
	int horasTrabajadas;
	int sueldo;
	if(pArrayListEmployee!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if(utn_getNumero(&auxId, "Ingrese el ID a modificar\n", "Error dato invalido",0,2000,2)==0)
		{
			posicionValida=employee_buscarPorId(pArrayListEmployee, auxId);
			if(posicionValida==-1)
			{
				printf("Error ID no econtrado\n");
			}else
			{
				pEmployee=ll_get(pArrayListEmployee, posicionValida);
				printf("[Menu de Modificacion]\n");
				do{
					utn_getNumero(&opcion, "\nSelecione 1.-Para editar el nombre\n"
															"Selecione 2.- Para editar Hs trabajadas\n"
															"Seleccione 3.- Para editar sueldo\n"
															"Seleccione 4.- Para salir\n", "Error Dato invalido", 1, 4, 2);
					switch(opcion)
					{
						case 1:
							if(utn_getNombre(nombre, 50, "Ingrese el Nuevo nombre : ", "Dato invalido", 2)==0)
							{
								employee_setNombre(pEmployee, nombre);
								printf("\n  Nombre actualizado con exito  \n");

							}
							break;
						case 2:
							if(utn_getNumero(&horasTrabajadas, "Ingrese las nuevas horas trabajadas", "Dato invalido: 0-120\n", 0, 120, 2)==0)
							{
								employee_setHorasTrabajadas(pEmployee, horasTrabajadas);
								printf("\n  Horas trabajadas actualizado con exito  \n");

							}
							break;
						case 3:
							if(utn_getNumero(&sueldo, "Ingrese el nuevo sueldo", "Dato invalido: 0-5000", 0, 5000, 2)==0)
							{
								employee_setSueldo(pEmployee, sueldo);
								printf("\n  Sueldo actualizado con exito  \n");
							}
							break;
						case 4:
							break;
					}
				}while(opcion!=4);

			}
		}
	}
	/*Pido el numero del ID
	Busco el ID
	Menu que campo quiere modificar.
	Setter
	Listo?
	y le hago un free?*/
    return rtn;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int rtn=-1;
	Employee* pEmployee;
	int auxId;
	int id;
	int posicionValida;
	int opcion;
	if(pArrayListEmployee!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if(utn_getNumero(&auxId,"\n Eliga el ID a Dar de baja  \n","\n Dato invalido  \n", 0, 2000,2)==0)
		{
			posicionValida=employee_buscarPorId(pArrayListEmployee, auxId);
			if(posicionValida==-1)
			{
				printf("El ID no existe\n");
			}else
			{
				pEmployee=ll_get(pArrayListEmployee, posicionValida);
				employee_getId(pEmployee,&id);
				if(id==auxId)
				{
					if(utn_getNumero(&opcion,"\n Menu de baja de Empleado \n"
											 "Seleccione 1.-Para dar de baja\n"
											 "Seleccione 2.-Para Salir\n","Dato invalido", 1, 2,2)==0)
					{
						switch(opcion){
						case 1:
						ll_remove(pArrayListEmployee, posicionValida);
						printf("\n  Baja de empleado con exito \n");
						rtn=0;
						break;
						case 2:
							rtn=1;
							break;
						}
					}
				}
			}
		}
	}
    return rtn;
}

/** \brief Listar empleados recorre la lista y llama a ll_get
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
		Employee *pEmployee;
		int rtn = 0;
		int salario;
		int horasTrabajadas;
		char nombre[128];
		int id;

		if (pArrayListEmployee == NULL)
		{
			printf("\n No hay empleados para listar.\n");
		} else
		{
			printf("    ____________________________________\n"
				   "      ID     Nombre       Horas  Sueldo \n"
				   "    ____________________________________\n");
			rtn = 1;

			for (int i = 0; i < ll_len(pArrayListEmployee); i++) {
				pEmployee = ll_get(pArrayListEmployee, i);
				//employee_getID(pEmployee, &id);
				employee_getNombre(pEmployee, nombre);
				employee_getSueldo(pEmployee, &salario);
				employee_getHorasTrabajadas(pEmployee, &horasTrabajadas);
				employee_getId(pEmployee, &id);
				printf("    [%4d] [%10s] [%5d] [$%d] \n",id,nombre, horasTrabajadas,salario);
			}
		}
		return rtn;

}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int rtn =-1;
	int opcion;
	if (pArrayListEmployee != NULL)
	{
		if(utn_getNumero(&opcion,"Menu de Ordenamiento\n"
								 "\nSeleccione 1.-Ordenar lista por sueldo\n"
								 "\nSeleccione 2.-Ordenar lista por nombre \n"
								 "\nSeleccione 3.-Ordenar lista por horas Trabajadas\n"
								 "\nSeleccione 4.-Ordenar lista por ID.\n"
								 "\nSeleccione 5.-Para salir.\n","Dato invalido ingrese [1-5]\n", 1, 5, 2)==0)
		{
			switch(opcion)
			{
				case 1 :
					printf("Aguarde un momento mientras carga el ordenamiento.\n");
					ll_sort(pArrayListEmployee, sort_salario,1);
					printf("\nSalarios ordenados con exito.Imprima para ver los resultados.\n");
					break;
				case 2:
					printf("Aguarde un momento mientras carga el ordenamiento.\n");
					ll_sort(pArrayListEmployee, sort_nombre,1);
					printf("\nNombres ordenados con exito.Imprima para ver los resultados.\n");
					break;
				case 3:
					printf("Aguarde un momento mientras carga el ordenamiento.\n");
					ll_sort(pArrayListEmployee, sort_horasDeTrabajo, 1);
					printf("\nHoras de trabajo ordenadas con exito.Imprima para ver los resultados.\n");
					break;
				case 4:
					printf("Aguarde un momento mientras carga el ordenamiento.\n");
					ll_sort(pArrayListEmployee, sort_id,1);
					printf("\nIds ordenados con exito.Imprima para ver los resultados.\n");
					break;
				case 5:
					break;
			}
		}
	}
    return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	FILE* pArchivo;
	Employee* pEmployee;
	int i;
	int idAux;
	int sueldoAux;
	int horasTrabajadasAux;
	char nombre [250];
	pArchivo=fopen(path,"w");
	if(pArrayListEmployee!=NULL && pArchivo !=NULL)
	{
		fprintf(pArchivo,"id,nombre,horas traabajadas,sueldo\n");
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			pEmployee=ll_get(pArrayListEmployee, i);

			employee_getId(pEmployee, &idAux);
			employee_getNombre(pEmployee, nombre);
			employee_getHorasTrabajadas(pEmployee, &horasTrabajadasAux);
			employee_getSueldo(pEmployee, &sueldoAux);

			fprintf(pArchivo,"%d,%s,%d,%d\n",idAux,nombre,horasTrabajadasAux,sueldoAux);
		}
		fclose(pArchivo);
		rtn=0;
	}
    return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int rtn=-1;
	FILE* pArchivo;
	Employee* pEmployee;
	int i;
	int aux;
	int contador=0;
	if(pArrayListEmployee!=NULL && path!=NULL)
	{
		pArchivo=fopen(path,"wb");
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			pEmployee=ll_get(pArrayListEmployee, i);
			aux=fwrite(pEmployee,sizeof(Employee),1,pArchivo);
			if(aux==1)
			{
				contador++;
			}

		}
		printf("elementos guardados: %d \n",contador);
		fclose(pArchivo);
		rtn=0;
	}
    return rtn;
}
int controller_asignarId(LinkedList* pArrayListEmployee,int* numeroId)
{
	int rtn=-1;
	Employee* pEmployee;
	int i;
	int idAux;
	if(pArrayListEmployee!=NULL)
	{
		if(ll_len(pArrayListEmployee)==0)
		{
			*numeroId=1001;
		}else
		{
			for(i=0;i<ll_len(pArrayListEmployee);i++)
			{
				pEmployee=ll_get(pArrayListEmployee, i);
				employee_getId(pEmployee,&idAux);
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
