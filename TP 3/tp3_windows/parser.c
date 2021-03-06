#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=0;
	int cantidad;
	char buffer1[1024];
	char buffer2[1024];
	char buffer3[1024];
	char buffer4[1024];
	Employee* nuevoEmpleado;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer1, buffer2, buffer3, buffer4);
		//printf("\n%s    %s    %s    %s",buffer1, buffer2, buffer3, buffer4); verificar que datos estoy poniendo

		while(!feof(pFile))//hasta q no lea la ultima linea, no sale del while
		{
			cantidad= fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer1, buffer2, buffer3, buffer4);
			if(cantidad<4)
			{
				break;
			}
			nuevoEmpleado=employee_newParametrosString(buffer1, buffer2, buffer3, buffer4);
			ll_add(pArrayListEmployee, nuevoEmpleado);
			retorno=1;
		}
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinaryW(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int cant=0;
	int cant2=0;
	int i;
	Employee* aux;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			aux=(Employee*)ll_get(pArrayListEmployee, i);
			cant=fwrite(aux, sizeof(Employee), 1, pFile);
			if(cant<1)
			{
				puts("\nError en la escritura binaria.");
				break;
			}
			cant2++;
		}
		if(cant2==ll_len(pArrayListEmployee))
		{
			retorno=1;
			puts("\nEscritura binaria realizada correctamente.");
		}

	}

	return retorno;
}

int parser_EmployeeFromTextW(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int id;
	int sueldo;
	int horasTrabajadas;
	char nombre[128];
	int i;
	Employee* aux;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			aux=ll_get(pArrayListEmployee, i);
			employee_getHorasTrabajadas(aux, &horasTrabajadas);
			employee_getSueldo(aux, &sueldo);
			employee_getNombre(aux, nombre);
			employee_getId(aux, &id);
			fprintf(pFile,"%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo); //escribe/guarda en el archivo.
			retorno=1;
		}
	}

	return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=0;
	int cantidad;
	Employee* nuevoEmpleadoBinario;
	Employee aux;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		while(!feof(pFile))//hasta q no lea la ultima linea, no sale del while
		{
			cantidad= fread(&aux, sizeof(Employee), 1, pFile);
			if(cantidad<1)
			{
				break;
			}
			nuevoEmpleadoBinario=employee_newParametros(aux.id, aux.nombre, aux.horasTrabajadas, aux.sueldo);
			ll_add(pArrayListEmployee, nuevoEmpleadoBinario);
			retorno=1;
		}
	}
	return retorno;
}
