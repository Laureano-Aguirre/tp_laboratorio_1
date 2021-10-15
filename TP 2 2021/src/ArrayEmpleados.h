/*
 * ArrayEmpleados.h
 *
 *  Created on: 14 may. 2021
 *      Author: Lau
 */

typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int isEmpty;
}eEmpleados;

int hardcodearEmpleados(eEmpleados arrayEmpleados[], int tam); //listo
void mostrarEmpleado(eEmpleados arrayEmpleados[], int pos); //listo
int mostrarEmpleados(eEmpleados arrayEmpleados[], int tam); //listo
int buscarLibre(eEmpleados arrayEmpleados [], int tam); //listo
int altaEmpleado(eEmpleados arrayEmpleados[], int tam); //listo
int modificarEmpleado(eEmpleados arrayEmpleados[], int tam); //listo
int bajaEmpleado(eEmpleados arrayEmpleados[], int tam); //listo
int asignarID(eEmpleados arrayEmpleados[], int tam); //listo
void mostrarEmpleadosOrdenados(eEmpleados arrayEmpleados[], int tam); //listo
int buscarEmpleadoID(eEmpleados arrayEmpleados[], int tam, int id); //listo
int addEmpleado(eEmpleados arrayEmpleados[], int pos, int id, char nombre[], char apellido[], float salario, int sector); //listo
int empleadosLen(eEmpleados arrayEmpleados[], int tam); //listo
void mostrarTotalSalariosYPromedio(eEmpleados arrayEmpleados[], int tam);
int empleadosSalariosMayoresPromedio(eEmpleados arrayEmpleados[], int tam, float promedio);




