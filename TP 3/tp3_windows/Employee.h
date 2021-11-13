#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "Aguirre.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new(); //ok
Employee* employee_newParametrosString(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr); //ok
Employee* employee_newParametros(int idStr,char* nombreStr,int horasTrabajadasStr, int sueldoStr); //ok
void employee_delete();

int employee_setId(Employee* this,int id); //ok
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);  //ok
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);  //ok
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);  //ok
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED
