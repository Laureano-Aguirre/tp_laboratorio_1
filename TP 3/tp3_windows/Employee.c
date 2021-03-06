#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new()
{
	Employee* nuevoEmpleado;
	nuevoEmpleado=(Employee*) malloc(sizeof(Employee));

	if(nuevoEmpleado!=NULL)
	{
		nuevoEmpleado->id=0;
		strcpy(nuevoEmpleado->nombre, " ");
		nuevoEmpleado->horasTrabajadas=0;
		nuevoEmpleado->sueldo=0;
	}

	return nuevoEmpleado;
}

Employee* employee_newParametrosString(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* nuevoEmpleado=employee_new();


	if(nuevoEmpleado!=NULL)
	{
		if(employee_setId(nuevoEmpleado, atoi(idStr))==-1 ||
			employee_setNombre(nuevoEmpleado, nombreStr)==-1 ||
			employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr))==-1 ||
			employee_setSueldo(nuevoEmpleado, atoi(sueldoStr))==-1)
		{
			free(nuevoEmpleado);
			nuevoEmpleado=NULL;
		}
	}
	return nuevoEmpleado;
}

Employee* employee_newParametros(int idStr,char* nombreStr,int horasTrabajadasStr, int sueldoStr)
{
	Employee* nuevoEmpleado=NULL;
	nuevoEmpleado=(Employee*)malloc(sizeof(Employee));

	if(nuevoEmpleado!=NULL)
	{
		nuevoEmpleado->id=idStr;
		strcpy(nuevoEmpleado->nombre, nombreStr);
		nuevoEmpleado->horasTrabajadas=horasTrabajadasStr;
		nuevoEmpleado->sueldo=sueldoStr;
	}

	return nuevoEmpleado;
}

int employee_setId(Employee* this,int id)
{
	int retorno=-1;

	if(this!=NULL && id>0)
	{
		this->id=id;
		retorno=1;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno=-1;

	if(this!=NULL && nombre!=NULL && strlen(nombre)<128 && strlen(nombre)>0)
	{
		strcpy(this->nombre, nombre);
		retorno=1;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno=-1;

	if(this!=NULL && horasTrabajadas>0)
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno=1;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno=-1;

	if(this!=NULL && sueldo>0)
	{
		this->sueldo=sueldo;
		retorno=1;
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno=0;

	if(this !=NULL && id!=NULL)
	{
		*id=this->id;
		retorno=1;
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=0;

	if(this!=NULL && nombre!=NULL && strlen(nombre)<128 && strlen(nombre)>=0)
	{
		strcpy(nombre, this->nombre);
		retorno=1;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno=0;

	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno=1;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno=0;

	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		retorno=1;
	}
	return retorno;
}


