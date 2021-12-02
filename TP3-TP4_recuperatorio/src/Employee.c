
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "Validaciones.h"
#include"LinkedList.h"

Employee* employee_new()
{
	Employee* pAuxEmployee=malloc(sizeof(Employee));
	return pAuxEmployee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* auxEmpleado;
	auxEmpleado=employee_new();
	if(auxEmpleado != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		employee_setId(auxEmpleado, atoi(idStr));
		employee_setNombre(auxEmpleado, nombreStr);
		employee_setHorasTrabajadas(auxEmpleado, atoi(horasTrabajadasStr));
		employee_setSueldo(auxEmpleado, atoi(sueldoStr));

	}
	return auxEmpleado;
}
void employee_delete(Employee* this)
{
	if(this!=NULL)
		{
		free(this);
		}
}
int employee_setId(Employee* this,int id)
{
	int rtn=-1;
		if(this!=NULL && id >=0)
		{
			this->id=id;
			rtn=0;
		}
	return rtn;
}
int employee_getId(Employee* this,int* id)
{
	int rtn =-1;
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		rtn=0;
	}
	return rtn;
}
int employee_setNombre(Employee* this,char* nombre)
{
	int rtn =-1;
	if(this!=NULL&& nombre!=NULL)
	{
		strncpy(this->nombre,nombre,sizeof(this->nombre));
		rtn=0;
	}
	return rtn;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int rtn =-1;
	if(this !=NULL && nombre!=NULL)
	{
		strncpy(nombre,this->nombre,128);
		rtn=0;
	}
	return rtn;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int rtn =-1;
		if(this!=NULL && horasTrabajadas>=0)
		{
			this->horasTrabajadas=horasTrabajadas;
			rtn=0;
		}else
		{
			printf("error\n");
		}
		return rtn;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int rtn =-1;
		if(this!=NULL && horasTrabajadas!=NULL)
		{
			*horasTrabajadas=this->horasTrabajadas;
			rtn=0;

		}
		return rtn;
}
int employee_setSueldo(Employee* this,int sueldo)
{
	int rtn=-1;
	if(this!=NULL && sueldo >=0)
	{
		this->sueldo=sueldo;
		rtn=0;
	}
	return rtn;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int rtn=-1;
	if(this!=NULL && sueldo >=0)
	{
		*sueldo=this->sueldo;
		rtn=0;
	}
	return rtn;
}
int employee_buscarPorId(LinkedList* pArrayListEmployee,int id)
{
	int rtn=-1;
	Employee* pEmployee;
	int i;
	int idAux;
	for(i=0;i<ll_len(pArrayListEmployee);i++)
	{
		pEmployee=ll_get(pArrayListEmployee, i);
		if(employee_getId(pEmployee, &idAux)==0 && idAux==id)
		{
			rtn=i;
		}
	}

	return rtn ;
}
int sort_salario(void* salarioUno,void* salarioDos)
{
	int rtn =0;
	int auxSalarioUno;
	int auxSalarioDos;
	employee_getSueldo(salarioUno,&auxSalarioUno);
	employee_getSueldo(salarioDos, &auxSalarioDos);
	if(auxSalarioUno > auxSalarioDos)
	{
		rtn=1;
	}else
	{
		if(auxSalarioUno < auxSalarioDos)
		{
			rtn = -1;
		}
	}
	return rtn;
}
int sort_id(void* idUno,void* idDos)
{
	int rtn=0;
	int auxIdUno;
	int auxIdDos;
	employee_getId(idUno, &auxIdUno);
	employee_getId(idDos, &auxIdDos);
	if(auxIdUno > auxIdDos)
	{
		rtn=1;
	}else{
		if(auxIdUno < auxIdDos)
		{
			rtn =-1;
		}
	}
	return rtn;
}
int sort_nombre(void* nombreUno,void* nombreDos)
{
	int rtn = 0;
		char eFirstNombre[128];
		char eSecondNombre[128];
		Employee* eFirts = (Employee*) nombreUno;
		Employee* eSecond = (Employee*) nombreDos;

		if(employee_getNombre(eFirts, eFirstNombre) !=-1 && employee_getNombre(eSecond, eSecondNombre) !=-1)
		{
			rtn = stricmp(eFirstNombre, eSecondNombre);
		}

		return rtn;
}
int sort_horasDeTrabajo(void* horasUno, void* horasDos)
{
	int rtn=0;
	int auxHorasUno;
	int auxHorasDos;
	employee_getHorasTrabajadas(horasUno, &auxHorasUno);
	employee_getHorasTrabajadas(horasDos, &auxHorasDos);
	if(auxHorasUno > auxHorasDos)
	{
		rtn = 1;
	}else
	{
		if(auxHorasUno < auxHorasDos)
		{
			rtn=-1;
		}
	}
	return rtn;
}
