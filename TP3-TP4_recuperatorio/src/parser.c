#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"



/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* archivo
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;
	int rtn=-1;
	char auxId[100];
	char auxNombre[100];
	char auxHorasTrabajadas[100];
	char auxSalario[100];
	int banderaPrimerElemento = 1;
	int auxscanf;
	if(pFile != NULL)
	{
		while(!feof(pFile))
		{
			if(banderaPrimerElemento)
			{
				fscanf(pFile,"%[^,],%[^,],%[^,]%[^\n]\n",auxId,auxNombre,auxHorasTrabajadas,auxSalario);
				banderaPrimerElemento=0;
			}
			auxscanf=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHorasTrabajadas,auxSalario);
			if(auxscanf==4)
			{
				pEmployee=employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSalario);
				ll_add(pArrayListEmployee, pEmployee);
				rtn=0;
			}
		}
	}
    return rtn;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;
	int rtn=-1;
	if(pFile!=NULL && pArrayListEmployee != NULL)
	{
		while(!feof(pFile))
		{
			pEmployee=employee_new();
			if(fread(pEmployee,sizeof(Employee),1,pFile)==1)
			{
				ll_add(pArrayListEmployee, pEmployee);
			}

		}
		rtn=0;
	}

    return rtn;
}
