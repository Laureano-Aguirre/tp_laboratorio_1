#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Aguirre.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados-
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    int retornoCargaTexto=-1;
    int retornoCargaBinario=-1;
    int idEmp;
    int resp;

    Employee* empleado;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{

    	getInt(" \n  Menu de opciones: "
    			"\n 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
    			"\n 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
    			"\n 3. Alta de empleado."
    			"\n 4. Modificar datos de empleado."
    			"\n 5. Baja de empleado."
    			"\n 6. Listar empleados."
    			"\n 7. Ordenar empleados."
    			"\n 8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
    			"\n 9. Guardar los datos de los empleados en el archivo data.csv (modo binario)."
    			"\n 10. Salir."
    			"\n Ingresar la operacion que desea ejecutar: ", &option);

        switch(option)
        {
            case 1:
            	puts("\nUsted ha elegido la opcion cargar los datos de los empleados desde el archivo data.csv (en modo texto).");
                if(retornoCargaTexto==-1)
                {
                	if(retornoCargaBinario==-1)
                	{
                		if(controller_loadFromText("data.csv",listaEmpleados)==1)
                		{
                			retornoCargaTexto=1;
                			empleado=(Employee*)ll_get(listaEmpleados, ll_len(listaEmpleados)-1);
                			employee_getId(empleado, &idEmp);
                		}
                	}
                	else
                	{
                		getInt("Ya hay datos cargados. Desea sobreescribir los datos del sistema? 1.si 2.no: ", &resp);
                		while(resp!=1 && resp!=2)
                		{
                			getInt("Error, ya hay datos cargados. Desea sobreescribir los datos del sistema? 1.si 2.no: ", &resp);
                		}
                		if(resp==1)
                		{
                			ll_clear(listaEmpleados);
                			if(controller_loadFromText("data.csv",listaEmpleados)==1)
                			{
                				retornoCargaTexto=1;
                				empleado=(Employee*)ll_get(listaEmpleados, ll_len(listaEmpleados)-1);
                				employee_getId(empleado, &idEmp);
                			}
                		}
                		else
                		{
                			puts("\nOperacion cancelada.");
                		}
                	}
                }
                else
                {
                	getInt("Ya hay datos cargados. Desea sobreescribir los datos del sistema? 1.si 2.no: ", &resp);
                	while(resp!=1 && resp!=2)
                	{
                		getInt("Error, ya hay datos cargados. Desea sobreescribir los datos del sistema? 1.si 2.no: ", &resp);
                	}
                	if(resp==1)
                	{
                		ll_clear(listaEmpleados);
                		if(controller_loadFromText("data.csv",listaEmpleados)==1)
                		{
                			retornoCargaTexto=1;
                			empleado=(Employee*)ll_get(listaEmpleados, ll_len(listaEmpleados)-1);
                			employee_getId(empleado, &idEmp);
                		}
                	}
                	else
                	{
                		puts("\nOperacion cancelada.");
                	}
                }
                break;
            case 2:
            	puts("\nUsted ha elegido la opcion cargar los datos de los empleados desde el archivo data.csv (en modo binario).");
            	if(retornoCargaBinario==-1)
            	{
            		if(retornoCargaTexto==-1)
            		{
            			if(controller_loadFromBinary("data.bin", listaEmpleados)==1)
            			{
            				retornoCargaBinario=1;
            				empleado=(Employee*)ll_get(listaEmpleados, ll_len(listaEmpleados)-1);
            				employee_getId(empleado, &idEmp);
            			}
            		}
            		else
            		{
            			getInt("Ya hay datos cargados. Desea sobreescribir los datos del sistema? 1.si 2.no: ", &resp);
            			while(resp!=1 && resp!=2)
            			{
            				getInt("Error, ya hay datos cargados. Desea sobreescribir los datos del sistema? 1.si 2.no: ", &resp);
            			}
            			if(resp==1)
            			{
            				ll_clear(listaEmpleados);
            				if(controller_loadFromBinary("data.bin", listaEmpleados)==1)
            				{
            					retornoCargaBinario=1;
            					empleado=(Employee*)ll_get(listaEmpleados, ll_len(listaEmpleados)-1);
            					employee_getId(empleado, &idEmp);
            				}
            			}
            			else
            			{
            				puts("\nOperacion cancelada");
            			}
            		}
            	}
            	else
            	{
            		getInt("Ya hay datos cargados. Desea sobreescribir los datos del sistema? 1.si 2.no: ", &resp);
            		while(resp!=1 && resp!=2)
            		{
            			getInt("Error, ya hay datos cargados. Desea sobreescribir los datos del sistema? 1.si 2.no: ", &resp);
            		}
            		if(resp==1)
            		{
            			ll_clear(listaEmpleados);
            			if(controller_loadFromBinary("data.bin", listaEmpleados)==1)
            			{
            				retornoCargaBinario=1;
            				empleado=(Employee*)ll_get(listaEmpleados, ll_len(listaEmpleados)-1);
            				employee_getId(empleado, &idEmp);
            			}
            		}
            		else
            		{
            			puts("\nOperacion cancelada");
            		}
            	}
            	break;
            case 3:
            	puts("\nUsted ha seleccionado la opcion Alta empleado.");
            	if(retornoCargaTexto==1 || retornoCargaBinario==1)
            	{
            		if(controller_addEmployee(listaEmpleados, &idEmp)==1)
            		{
            			puts("\nEmpleado cargado correctamente.");
            		}
            		else
            		{
            			puts("\nNo se pudo cargar el empleado.");
            		}
            	}
            	else
            	{
            		puts("\nError, debe cargar los datos del archivo antes de dar de alta a un empleado.");
            	}

            	break;
            case 4:
            	puts("\nUsted ha elegido la opcion modificar datos de empleado.");
            	if(controller_editEmployee(listaEmpleados)==1)
            	{
            		puts("\nEmpleado modificado correctamente.");
            	}
            	else
            	{
            		puts("\nNo se pudo modificar el empleado.");
            	}
            	break;
            case 5:
            	puts("\nUsted ha seleccionado la opcion baja de empleado.");
            	if(controller_removeEmployee(listaEmpleados)==1)
            	{
            		puts("\nEmpleado borrado correctamente.");
            	}
            	else
            	{
            		puts("\nNo se pudo borrar el empleado.");
            	}
            	break;
            case 6:
            	puts("\nUsted ha seleccionado la opcion listar empleados.");
            	controller_ListEmployee(listaEmpleados);
            	break;
            case 7:
            	puts("\nUsted ha seleccionado la opcion ordenar empleados.");
            	controller_sortEmployee(listaEmpleados);
            	break;
            case 8:
            	puts("\nUsted ha seleccionado la opcion Guardar los datos de los empleados en el archivo data.csv (modo texto).");
            	controller_saveAsText("data.csv", listaEmpleados);
            	break;
            case 9:
            	puts("\nUsted ha seleccionado la opcion Guardar los datos de los empleados en el archivo data.csv (modo binario).");
            	controller_saveAsBinary("data.bin", listaEmpleados);
            	break;
            case 10:
            	puts("\nSaliendo del programa...");
            	break;
        }
        if(option<1 || option>10)
        {
        	puts("\nOpcion incorrecta, por favor, intente nuevamente.");
        }
        fflush(stdin);
        getchar();
    }while(option != 10);
    return 0;
}
