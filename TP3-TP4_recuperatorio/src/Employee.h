#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include"LinkedList.h"//agregado 01.15am
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Prueba;
Employee* employee_new(void);//esto devuelve un puntero empleado
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);// un puntero a empleado con sus campos creados
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int employee_buscarPorId(LinkedList* pArrayListEmployee,int id);
int sort_salario(void* salarioUno,void* salarioDos);
int sort_id(void* idUno,void* idDos);
int sort_nombre(void* nombreUno,void* nombreDos);
int sort_horasDeTrabajo(void* horasUno, void* horasDos);
//alta empleado
//modificar empleado
//buscar por id


#endif // employee_H_INCLUDED
