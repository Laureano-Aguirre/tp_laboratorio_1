/*
 Aguirre Laureano
 1 J
 */

#include <stdio.h>
#include <stdlib.h>
#include "OperacionesAritmeticas.h"

int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	float operandoA;
	float operandoB;
	int validarOperandoA;
	int validarOperandoB;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	float resultadoFactorialA;
	float resultadoFactorialB;
	int validarS;
	int validarR;
	int validarD;
	int validarM;
	int validarF1;
	int validarF2;

	validarOperandoA=0;
	validarOperandoB=0;
	resultadoSuma=0;
	resultadoDivision=0;
	resultadoMultiplicacion=0;
	resultadoResta=0;
	validarS=0;
	validarR=0;
	validarD=0;
	validarM=0;
	validarF1=0;
	validarF2=0;


	do
	{
		printf("\n CALCULADORA"
				"\n El valor del operando A es %.2f y del operando B es %.2f \n"
				"\n 1.ingresar operandoA"
				"\n 2.ingresar operandoB"
				"\n 3.realizar todas las operaciones "
				"\n 4.mostrar resultados "
				"\n 5.salir ", operandoA, operandoB);
		printf("\n Toque el numero de la operacion que desea ralizar: ");
		scanf("%d", &opcion);
		switch (opcion)
		{
		case 1:
			printf("\nIngrese el primer operando: ");
			scanf("%f", &operandoA);
			validarOperandoA=1;

			break;
		case 2:
			printf("\nIngrese el segundo operando: ");
			scanf("%f", &operandoB);
			validarOperandoB=1;
			break;
		case 3:
			if(validarOperandoA==1 && validarOperandoB==1)
			{
				resultadoSuma=suma(operandoA, operandoB);
				puts("\nSe ha realizado la suma satisfactoriamente.");
				validarS=1;
				resultadoResta=resta(operandoA, operandoB);
				puts("\nSe ha realizado la resta satisfactoriamente.");
				validarR=1;
				if(operandoB==0)
				{
					puts("\nNo se ha podido realizar la division, ya que no se puede dividir por 0.");
				}
				else
				{
					resultadoDivision=division(operandoA, operandoB);
					puts("\nSe ha realizado la division satisfactoriamente.");
					validarD=1;
				}
				resultadoMultiplicacion=multiplicacion(operandoA, operandoB);
				puts("\nSe ha realizado la multiplicacion satisfactoriamente.");
				validarM=1;
				if(operandoA==0)
				{
					puts("\nNo se puede ralizar el factorial de 0");
				}
				else
				{
					resultadoFactorialA=factorial(operandoA);
					puts("\nSe ha realizado el factorial del operando A satisfactoriamente.");
					validarF1=1;
				}
				if(operandoB==0)
				{
					puts("\nNo se puede ralizar el factorial de 0");
				}
				else
				{
					resultadoFactorialB=factorial(operandoB);
					puts("\nSe ha realizado el factorial del operando B satisfactoriamente.");
					validarF2=1;
				}
			}
			else
			{
				puts("\nNo ingreso los dos operando, por favor, ingrese el operando que falta.");
			}
			break;
		case 4:
			mostrarResultados(resultadoSuma, validarS, resultadoResta, validarR, resultadoMultiplicacion, validarM, resultadoDivision, validarD, resultadoFactorialA, validarF1, resultadoFactorialB, validarF2);
		}
		if(opcion>5 || opcion<1)
		{
			printf("Error, reingrese el numero de la operacion que desea realizar.");
		}
		fflush(stdin);
		getchar();
		system("cls");

	}while(opcion!=5);


	return EXIT_SUCCESS;
}
