#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "Aguirre.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=0;
	FILE *auxP;

	auxP=fopen(path,"r");
	if(auxP!=NULL)
	{
		if(parser_EmployeeFromText(auxP, pArrayListEmployee)==1)
		{
			retorno=1;
		}
	}
	else
	{
		puts("\nError, no se puede leer el archivo.");
	}
	fclose(auxP);
    return retorno;
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
	int retorno=-1;

	if((pArchivo=fopen(path,"r+b"))==NULL)
	{
		puts("\nError al abrir el archivo.");
	}
	else
	{
		parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
		puts("\nDatos cargados correctamente.");
		retorno=1;
	}
    return retorno;
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
	int retorno=0;
	int idEmpleado;
	int horasTrabajadas;
	char nombre[128];
	int sueldo;
	Employee* nuevoEmpleado=NULL;

	if(pArrayListEmployee!=NULL)
	{
		idEmpleado=ll_len(pArrayListEmployee);
		idEmpleado++;
		printf("\nEl ID del empleado que va a cargar, es: %d", idEmpleado);
		getString("\nIngrese el nombre del empleado que desea cargar: ", nombre);
		getInt("\nIngrese las horas trabajadas que desea cargar: ", &horasTrabajadas);
		getInt("\nIngrese el sueldo del empleado que desea cargar: ", &sueldo);
		nuevoEmpleado=employee_newParametros(idEmpleado, nombre, horasTrabajadas, sueldo);
		if(nuevoEmpleado!=NULL)
		{
			ll_add(pArrayListEmployee, nuevoEmpleado);
			retorno=1;
		}
	}

    return retorno;
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
	int retorno=0;
	int idEmpleado;
	int pos;
	int len;
	int opcion;
	int auxSueldo, auxHorasTrabajadas;
	char auxNombre[128];
	Employee* pEmpleado;

	if(pArrayListEmployee!=NULL)
	{
		len=ll_len(pArrayListEmployee);
		if(len>0)
		{
			controller_ListEmployee(pArrayListEmployee);
			getInt("\nPor favor, ingrese el empleado que desea modificar: ", &idEmpleado);
			pos=buscarIndice(pArrayListEmployee, idEmpleado);
			pEmpleado=ll_get(pArrayListEmployee, pos);
			if(pos!=0)
			{
				mostrarEmpleado(pArrayListEmployee, pos);
				getInt("\nQue desea modificar del empleado? 1. nombre 2.sueldo 3.horas trabajadas: ", &opcion);
				while(opcion!=1 && opcion !=2 && opcion!=3)
				{
					getInt("\nError, que desea modificar del empleado? 1. nombre 2.sueldo 3.horas trabajadas: ", &opcion);
				}
				switch(opcion)
				{
					case 1:
						getString("\nIngrese el nombre nuevo: ", auxNombre);
						employee_setNombre(pEmpleado, auxNombre);
						break;
					case 2:
						getInt("\nIngrese el nuevo sueldo: ", &auxSueldo);
						employee_setSueldo(pEmpleado, auxSueldo);
						break;
					case 3:
						getInt("\nIngrese las nuevas horas de trabajo: ", &auxHorasTrabajadas);
						employee_setHorasTrabajadas(pEmpleado, auxHorasTrabajadas);
						break;
				}
			}
			else
			{
				puts("\nNo se ha encontrado ningun empleado con ese ID.");
			}
		}
		else
		{
			puts("\nNo hay empleados cargados para modificar.");
		}

	}
    return retorno;
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
	int len;
	int pos;
	int retorno=-1;
	int id;
	int opcion;
	Employee* pEmpleado;

	if(pArrayListEmployee!=NULL)
	{
		len=ll_len(pArrayListEmployee);
		if(len>0)
		{
			puts("\nListando empleados...");
			controller_ListEmployee(pArrayListEmployee);
			getInt("\nIngrese el ID del empleado que desea eliminar: ", &id);
			pos=buscarIndice(pArrayListEmployee, id);
			if(pos!=-1)
			{
				puts("\nEmpleado encontrado...");
				pEmpleado=(Employee*)ll_get(pArrayListEmployee, pos);
				mostrarEmpleado(pArrayListEmployee, pos);
				getInt("\nDesea eliminar este empleado? 1.si 2.no: ", &opcion);
				while(opcion!=1 && opcion!=2)
				{
					getInt("\nError, desea eliminar este empleado? 1.si 2.no: ", &opcion);
				}
				if(opcion==1)
				{
					free(pEmpleado);
					puts("\nEmpleado borrado exitosamente!");
					retorno=1;
				}
				else
				{
					puts("\nOperacion cancelada.");
				}
			}
		}
		else
		{
			puts("\nNo hay empleados cargados.");
		}
	}
	else
	{
		puts("\nError, no hay nada cargado en la lista.");
	}
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	int retorno=-1;

	if(pArrayListEmployee!=NULL)
	{
		if(ll_len(pArrayListEmployee)>0)
		{
			for(i=0;i<ll_len(pArrayListEmployee);i++)
			{
				mostrarEmpleado(pArrayListEmployee, i);
				retorno=1;
			}
		}
		else
		{
			puts("\nNo hay empleados disponibles para listar.");
		}

	}
    return retorno;
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
	int retorno=-1;
	int opcion;

	if(pArrayListEmployee!=NULL)
	{
		if(ll_len(pArrayListEmployee)>0)
		{
			getInt("\nIngrese que desea ordenar (1.nombre 2.sueldo 3.horas trabajadas, entero): ", &opcion);
			while(opcion!=1 && opcion !=2 && opcion!=3)
			{
				getInt("\nError, ingrese que desea ordenar (1.nombre 2.sueldo 3.horas trabajadas, entero): ", &opcion);
			}
			switch(opcion)
			{
				case 1:
					if(ll_sort(pArrayListEmployee, OrdenamientoPorNombre, 1)==0)	//le paso a la funcion sort, encargada de hacer el swapeo, la lista, la funcion retornando
					{
						retorno=1;
					}
					break;													//el valor de la comparacion, y el tipo de ordenamiento (1 descendente)
				case 2:
					if(ll_sort(pArrayListEmployee, OrdenamientoPorSueldo, 1)==0)
					{
						retorno=1;
					}
					break;
				case 3:
					if(ll_sort(pArrayListEmployee, OrdenamientoPorHsTrabajadas, 1)==0)
					{
						retorno=1;
					}
					break;
			}
		}
		else
		{
			puts("\nNo hay empleados disponibles para ordenar.");
		}
	}
	else
	{
		puts("\nError, no hay nada cargado en la lista.");
	}
    return retorno;
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
	FILE* pArchivo;
	int retorno=-1;

	pArchivo=fopen(path,"r");
	if(pArchivo==NULL)
	{
		pArchivo=fopen(path,"w");
	}
	parser_EmployeeFromTextW(pArchivo, pArrayListEmployee);
	fclose(pArchivo);
	retorno=1;

    return retorno;
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
	int retorno=-1;
	FILE* pArchivo;

	pArchivo=fopen(path,"wb");
	if(pArchivo==NULL)
	{
		puts("\nError al abir el archivo");
	}
	else
	{
		if(parser_EmployeeFromBinaryW(pArchivo, pArrayListEmployee)!=-1)
		{
			puts("\nSe escribieron los datos en el archivo binario exitosamente.");
			retorno=1;
		}
		fclose(pArchivo);
	}

    return retorno;
}

int buscarIndice(LinkedList* pArrayListEmployee, int id)
{
	int retorno=-1;
	int i;
	int idEmp;
	Employee* empleado;


	if(pArrayListEmployee!=NULL && id>=0)
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			empleado=(Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(empleado, &idEmp);
			if(id==idEmp)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

void mostrarEmpleado(LinkedList* pArrayListEmployee, int index)
{
	Employee* empleado;
	int horasTrabajadas;
	int sueldo;
	int id;
	//char nombre[128];

	empleado=(Employee*)ll_get(pArrayListEmployee, index);
	employee_getHorasTrabajadas(empleado, &horasTrabajadas);
	employee_getSueldo(empleado, &sueldo);
	//employee_getNombre(empleado, nombre);
	employee_getId(empleado, &id);

	printf("\nID: %d  ----  nombre: %s  ----  sueldo: %d  ----  horas trabajadas: %d", id, empleado->nombre, sueldo, horasTrabajadas);

}

int OrdenamientoPorNombre(void* empleadoA, void* empleadoB)
{
	int retorno=0;

	retorno=strcmp(((Employee*)empleadoA)->nombre, ((Employee*)empleadoB)->nombre);		//declaro y casteo las variables de tipo empleado, luego las comparo

	return retorno;
}

int OrdenamientoPorHsTrabajadas(void* empleadoA, void* empleadoB)
{
	int retorno=0;

	if(((Employee*)empleadoA)->horasTrabajadas > ((Employee*)empleadoB)->horasTrabajadas) //compara si el empleado A tiene mas horas trabajadas que el empleado B
	{
		retorno=1;
	}
	else if(((Employee*)empleadoA)->horasTrabajadas < ((Employee*)empleadoB)->horasTrabajadas)	///compara si el empleado B tiene mas horas trabajadas que el empleado A
	{
		retorno=-1;
	}
	else
	{
		retorno=0;		//ambos empleados trabajaron las mismas horas
	}
	return retorno;
}

int OrdenamientoPorSueldo(void* empleadoA, void* empleadoB)
{
	int retorno=0;

	if(((Employee*)empleadoA)->sueldo > ((Employee*)empleadoB)->sueldo)		//compara el sueldo del empleado A con el sueldo del empleado B, si gana mas, retorna 1
	{
		retorno=1;
	}
	else if(((Employee*)empleadoA)->sueldo < ((Employee*)empleadoB)->sueldo)		//compara el sueldo del empleado B con el del empleado A, si gana mas, retorna -1
	{
		retorno=-1;
	}
	else
	{
		retorno=0;		//retorna 0 en caso de que ganen lo mismo
	}
	return retorno;
}

