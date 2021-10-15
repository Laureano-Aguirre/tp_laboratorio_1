/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Aguirre.h"
#include "ArrayEmpleados.h"
#define TAM 1000

int main(void)
{
	setbuf(stdout, NULL);

	eEmpleados arrayEmpleados[TAM];
	int opcion;

	hardcodearEmpleados(arrayEmpleados, TAM);

	do
	    {
	        getInt(" \n  Menu de opciones: "
	               "\n 1. Alta  empleado"
	               "\n 2. Modificacion empleado"
	               "\n 3. Baja empleado"
	               "\n 4. Listado empleados"
	               "\n 5. Listado empleados ordenados"
	               "\n 6. Listar total y promedio de los salarios y cuantos empleados superan el salario promedio"
	               "\n 7. Salir"
	               "\n Ingresar la operacion que desea ejecutar: ", &opcion);

	        switch(opcion)
	        {
	        case 1:
	           altaEmpleado(arrayEmpleados, TAM);
	            break;
	        case 2:
	            modificarEmpleado(arrayEmpleados, TAM);
	            break;
	        case 3:
	            bajaEmpleado(arrayEmpleados, TAM);
	            break;
	        case 4:
	        	mostrarEmpleados(arrayEmpleados, TAM);
	            break;
	        case 5:
	            mostrarEmpleadosOrdenados(arrayEmpleados, TAM);
	            break;
	        case 6:
	            mostrarTotalSalariosYPromedio(arrayEmpleados, TAM);
	            break;
	        case 7:
	            puts("\n Vuelva prontos.");
	            break;
	        }

	        if(opcion<1 || opcion>7)
	        {
	        	puts("\n Operacion ingresada incorrecta");
	        }
	        fflush(stdin);
	        getchar();
	        system("cls");

	    }while(opcion !=7);


	return EXIT_SUCCESS;
}

