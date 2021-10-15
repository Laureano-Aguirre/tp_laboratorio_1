/*
 * ArrayEmpleados.c
 *
 *  Created on: 14 may. 2021
 *      Author: Lau
 */

#include "ArrayEmpleados.h"
#include "Aguirre.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define VACIO 1
#define OCUPADO 0

int hardcodearEmpleados(eEmpleados arrayEmpleados[], int tam)
{
	int i;
	int retorno;

	retorno=-1;

	for(i=0;i<tam;i++)
	{
		arrayEmpleados[i].isEmpty=VACIO;
		retorno=1;
	}
	return retorno;
}

void mostrarEmpleado(eEmpleados arrayEmpleados[], int pos)
{

	printf("\n id: %d nombre: %s apellido: %s salario: %.2f sector: %d", arrayEmpleados[pos].id,
					   	   	   arrayEmpleados[pos].nombre,
							   arrayEmpleados[pos].apellido,
							   arrayEmpleados[pos].salario,
							   arrayEmpleados[pos].sector);
}

int mostrarEmpleados(eEmpleados arrayEmpleados[], int tam)
{
	int i;
	int retorno;
	int len;

	retorno=-1;

	len=empleadosLen(arrayEmpleados, tam);
	if(len>0)
	{
		puts("\n Listando empleados...");
		for(i=0;i<tam;i++)
		{
			if(arrayEmpleados[i].isEmpty==OCUPADO)
			{
				mostrarEmpleado(arrayEmpleados, i);
				retorno=1;
			}
		}
	}
	else
	{
		puts("\n No se pueden mostrar los empleados ya que no hay empleados cargados.");
	}

	return retorno;
}

int buscarLibre(eEmpleados arrayEmpleados [], int tam)
{
	int i;
	int pos;

	pos=-1;

	for(i=0;i<tam;i++)
	{
		if(arrayEmpleados[i].isEmpty==VACIO)
		{
			pos=i;
			break;
		}
	}
	return pos;
}

int altaEmpleado(eEmpleados arrayEmpleados[], int tam)
{
	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int retorno;
	int pos;

	retorno=-1;

	pos=buscarLibre(arrayEmpleados, tam);
	if(pos!=-1)
	{
		puts("\n Lugar libre encontrado");
		getString("\n Ingresar nombre del empleado: ", nombre);
		getString("\n Ingresar apellido del empleado: ", apellido);
		getFloat("\n Ingresar el salario del empleado: ", &salario);
		getInt("\n Ingresar sector del empleado: ", &sector);
		id=asignarID(arrayEmpleados, tam);
		printf("\nEl ID de su empleado es: %d", id);
		retorno=addEmpleado(arrayEmpleados, pos, id, nombre, apellido, salario, sector);

		if(retorno==1)
		{
			puts("\n Se agrego al empleado exitosamente.");
			retorno=1;
		}
		else
		{
			puts("\n Hubo un error cargando el empleado");
			retorno=0;
			arrayEmpleados[pos].isEmpty=VACIO;
		}
	}
	else
	{
		puts("\n No hay espacio para cargar empleados.");
		retorno=0;
	}

	return retorno;
}

int modificarEmpleado(eEmpleados arrayEmpleados[], int tam)
{
	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int retorno;
	int pos;
	int len;
	int respuesta;

	retorno=-1;

	len=empleadosLen(arrayEmpleados, tam);
	if(len>0)
	{
		mostrarEmpleados(arrayEmpleados, tam);
		getInt("\n Ingresar ID del empleado a modificar: ", &id);
		pos=buscarEmpleadoID(arrayEmpleados, tam, id);
		if(pos!=-1)
		{
			id=arrayEmpleados[pos].id;
			strcpy(nombre, arrayEmpleados[pos].nombre);
			strcpy(apellido, arrayEmpleados[pos].apellido);
			salario=arrayEmpleados[pos].salario;
			sector=arrayEmpleados[pos].sector;
			getInt("\n Desea modificar el nombre? 1 para si 2 para no: ", &respuesta);
			while(respuesta!=1 && respuesta!=2)
			{
				getInt("\n Incorrecto, desea modificar el nombre? 1 para si 2 para no: ", &respuesta);
			}
			if(respuesta==1)
			{
				getString("\n Ingresar nombre del empleado: ", nombre);
			}
			getInt("\n Desea modificar el apellido? 1 para si 2 para no: ", &respuesta);
			while(respuesta!=1 && respuesta!=2)
			{
				getInt("\n Incorrecto, desea modificar el apellido? 1 para si 2 para no: ", &respuesta);
			}
			if(respuesta==1)
			{
				getString("\n Ingresar apellido del empleado: ", apellido);
			}
			getInt("\n Desea modificar el salario? 1 para si 2 para no: ", &respuesta);
			while(respuesta!=1 && respuesta!=2)
			{
				getInt("\n Incorrecto, desea modificar el salario? 1 para si 2 para no: ", &respuesta);
			}
			if(respuesta==1)
			{
				getFloat("\n Ingresar el salario del empleado: ", &salario);
			}
			getInt("\n Desea modificar el sector? 1 para si 2 para no: ", &respuesta);
			while(respuesta!=1 && respuesta!=2)
			{
				getInt("\n Incorrecto, desea modificar el sector? 1 para si 2 para no: ", &respuesta);
			}
			if(respuesta==1)
			{
				getInt("\n Ingresar sector del empleado: ", &sector);
			}
			retorno= addEmpleado(arrayEmpleados, pos, id, nombre, apellido, salario, sector);

			if(retorno==1)
			{
				puts("\n Se agrego al empleado exitosamente.");
				retorno=1;
			}
			else
			{
			puts("\n Hubo un error cargando el empleado");
			retorno=0;
			arrayEmpleados[pos].isEmpty=VACIO;
			}
		}
		else
		{
			puts("\n No se encontro el  empleado.");
			retorno=0;
		}
	}
	else
	{
		puts("\n No hay empleados disponibles para modificar.");
	}

	return retorno;
}

int bajaEmpleado(eEmpleados arrayEmpleados[], int tam)
{
	int len;
	int retorno;
	int id;
	int respuesta;

	retorno=-1;

	len=empleadosLen(arrayEmpleados, tam);
	if(len>0)
	{
		mostrarEmpleados(arrayEmpleados, tam);
		getInt("\nIngrese el ID del empleado a borrar.", &id);
		retorno=buscarEmpleadoID(arrayEmpleados, tam, id);
		if(retorno!=-1)
		{
			mostrarEmpleado(arrayEmpleados, retorno);
			getInt("\n Desea borrar este empleado? 1 por si y 2 por no: ", &respuesta);
			while(respuesta!=1 && respuesta!=2)
			{
				getInt("\n Error, desea borrar este empleado? 1 por si y 2 por no: ", &respuesta);
			}
			if(respuesta==1)
			{
				arrayEmpleados[retorno].isEmpty=VACIO;
				puts("\n Usuario borrado.");
			}
			else
			{
				puts("\n Operacion cancelada.");
			}
		}
	}
	else
	{
		puts("\n No hay empleados disponibles para borrar.");
	}
	return retorno;
}

int asignarID(eEmpleados arrayEmpleados[], int tam)
{
	int id;
	int i;
	int max;

	max=-1;

	for(i=0;i<tam;i++)
	{
		if(arrayEmpleados[i].id>max)
		{
			max=arrayEmpleados[i].id;
		}
	}
	id=max+1;

	return id;
}

void mostrarEmpleadosOrdenados(eEmpleados arrayEmpleados[], int tam)
{
	int respuesta;
	int i;
	int j;
	eEmpleados aux;
	int retorno;
	int len;

	len=empleadosLen(arrayEmpleados, tam);
	if(len>0)
	{
		getInt("\n Como desea ordenar a los empleados? 1 por apellido y 2 por sector: ", &respuesta);
		while(respuesta!=1 && respuesta!=2)
		{
			getInt("\n Error, como desea ordenar a los empleados? 1 por apellido y 2 por sector: ", &respuesta);
		}
		switch (respuesta)
		{
		case 1:
			getInt("\n Desea hacerlo en caso ascendente o descendente? 1 ascendendente y 2 descendente.", &respuesta);
			while(respuesta!=1 && respuesta!=2)
			{
				getInt("\n Error, desea hacerlo en caso ascendente o descendente? 1 ascendendente y 2 descendente: ", &respuesta);
			}
			if(respuesta==1)
			{
				for(i=0;i<tam-1;i++)
				{
					for(j=i+1;j<tam;j++)
					{
						retorno=strcmp(arrayEmpleados[i].apellido, arrayEmpleados[j].apellido);
						if(retorno==1)
						{
							aux=arrayEmpleados[i];
							arrayEmpleados[i]=arrayEmpleados[j];
							arrayEmpleados[j]=aux;
						}
					}
				}
			}
			else
			{
				for(i=0;i<tam-1;i++)
				{
					for(j=i+1;j<tam;j++)
					{
						retorno=strcmp(arrayEmpleados[i].apellido, arrayEmpleados[j].apellido);
						if(retorno==-1)
						{
							aux=arrayEmpleados[j];
							arrayEmpleados[j]=arrayEmpleados[i];
							arrayEmpleados[i]=aux;
						}
					}
				}
			}
			break;
		case 2:
			getInt("\n Desea hacerlo en caso ascendente o descendente? 1 ascendendente y 2 descendente.", &respuesta);
			while(respuesta!=1 && respuesta!=2)
			{
				getInt("\n Error, desea hacerlo en caso ascendente o descendente? 1 ascendendente y 2 descendente: ", &respuesta);
			}
			if(respuesta==1)
			{
				for(i=0;i<tam-1;i++)
				{
					for(j=i+1;j<tam;j++)
					{
						if(arrayEmpleados[i].sector>arrayEmpleados[j].sector)
						{
							aux=arrayEmpleados[i];
							arrayEmpleados[i]=arrayEmpleados[j];
							arrayEmpleados[j]=aux;
						}
					}
				}
			}
			else
			{
				for(i=0;i<tam-1;i++)
				{
					for(j=i+1;j<tam;j++)
					{
						if(arrayEmpleados[i].sector<arrayEmpleados[j].sector)
						{
							aux=arrayEmpleados[j];
							arrayEmpleados[j]=arrayEmpleados[i];
							arrayEmpleados[i]=aux;
						}
					}
				}
			}
			break;
		}
		mostrarEmpleados(arrayEmpleados, tam);
	}
	else
	{
		puts("\n No se pudo ordenar correctamente, ya que no hay empleados cargados.");
	}
}

int buscarEmpleadoID(eEmpleados arrayEmpleados[], int tam, int id)
{
	int i;
	int retorno;

	retorno=-1;

	for(i=0;i<tam;i++)
	{
		if(arrayEmpleados[i].isEmpty==OCUPADO)
		{
			if(id==arrayEmpleados[i].id)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int addEmpleado(eEmpleados arrayEmpleados[], int pos, int id, char nombre[], char apellido[], float salario, int sector)
{
	int retorno=-1;
	arrayEmpleados[pos].id=id;
	strcpy(arrayEmpleados[pos].nombre, nombre);
	strcpy(arrayEmpleados[pos].apellido, apellido);
	arrayEmpleados[pos].salario=salario;
	arrayEmpleados[pos].sector=sector;
	arrayEmpleados[pos].isEmpty=OCUPADO;

	retorno=1;

	return retorno;
}

int empleadosLen(eEmpleados arrayEmpleados[], int tam)
{
	int retorno;
	int i;

	retorno=0;

	for(i=0;i<tam;i++)
	{
		if(arrayEmpleados[i].isEmpty==OCUPADO)
		{
			retorno++;
		}
	}

	return retorno;
}

void mostrarTotalSalariosYPromedio(eEmpleados arrayEmpleados[], int tam)
{
	int contadorSalarios;
	float acumuladorSalarios;
	int i;
	float promedio;
	int len;
	int empleadosSalariosMayorPromedio;
	acumuladorSalarios=0;
	contadorSalarios=0;

	len=empleadosLen(arrayEmpleados, tam);

	if(len>0)
	{
		for(i=0;i<tam;i++)
		{
			if(arrayEmpleados[i].isEmpty==OCUPADO)
			{
				acumuladorSalarios+=arrayEmpleados[i].salario;
				contadorSalarios++;
			}
		}
		promedio=acumuladorSalarios/contadorSalarios;
		empleadosSalariosMayorPromedio=empleadosSalariosMayoresPromedio(arrayEmpleados, tam, promedio);
		printf("\n La suma total de salarios es de %.2f."
				"\n El promedio da %.2f."
				"\n La cantidad de personas que tienen un salario mayor al salario promedio es de %d", acumuladorSalarios, promedio, empleadosSalariosMayorPromedio);
	}
	else
	{
		puts("\n No hay empleados para realizar el promedio y para calcular el salario total.");
	}
}

int empleadosSalariosMayoresPromedio(eEmpleados arrayEmpleados[], int tam, float promedio)
{
	int contador;
	int i;

	contador=0;

	for(i=0;i<tam;i++)
	{
		if(arrayEmpleados[i].isEmpty==OCUPADO)
		{
			if(arrayEmpleados[i].salario>promedio)
			{
				contador++;
			}
		}
	}
	return contador;
}


