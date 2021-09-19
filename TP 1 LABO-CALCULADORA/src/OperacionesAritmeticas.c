/*
 * OperacionesAritmeticas.c
 *
 *  Created on: 15 sept. 2021
 *      Author: Lau
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "OperacionesAritmeticas.h"

float suma(float operandoA, float operandoB)
{
	float suma;

	suma=operandoA+operandoB;

	return suma;
}

float resta(float operandoA, float operandoB)
{
	float resta;

	resta=operandoA-operandoB;

	return resta;
}

float division(float operandoA, float operandoB)
{
	float division;

	division=operandoA/operandoB;

	return division;
}
float multiplicacion(float operandoA, float operandoB)
{
	float multiplicacion;

	multiplicacion=operandoA/operandoB;

	return multiplicacion;
}

float factorial(float numero)
{
	int i;
	long int resultadoFactorial;
	resultadoFactorial=1;
	i=numero;

	if(numero-i==0)
	{
		if(numero==0)
		{
			resultadoFactorial=1;// el factorial de 0 es igual a 1
		}
		else if(numero<0)
		{
			resultadoFactorial=0; //no se puede hacer el factorial de un numero negativo
		}
		else
		{
			for(;i>0;i--)
			{
				resultadoFactorial*=i;
			}
		}
		}
		else
		{
			resultadoFactorial=-1;//numero con coma
		}


	return resultadoFactorial;
}

void mostrarResultados(float suma, int validarS, float resta, int validarR, float multiplicacion, int validarM, float division, int validarD, float factorialA, int validarFA, float factorialB, int validarFB)
{
	if(validarS==1)
	{
		printf("\n El resultado de la suma da %.2f", suma);
	}
	else
	{
		printf("\n La suma no se ha podido realizar.");
	}
	if(validarR==1)
	{
		printf("\n El resultado de la resta da %.2f", resta);
	}
	else
	{
		printf("\n La resta no se ha podido realizar.");
	}
	if(validarM==1)
	{
		printf("\n El resultado de la multiplicacion da %.2f", multiplicacion);
	}
	else
	{
		printf("\n La multiplicacion no se ha podido realizar.");
	}
	if(validarD==1)
	{
		printf("\n El resultado de la division da %.2f", division);
	}
	else
	{
		printf("\n La division no se ha podido realizar.");
	}
	if(factorialA!=-1 && factorialA!=0)
	{
		if(validarFA==1)
		{
			printf("\n El resultado del factorial A da %.2f", factorialA);
		}
		else
		{
			printf("\n El factorial A no se ha podido realizar.");
		}
	}
	else
	{
		printf("\n El factorial A no se ha podido realizar.");
	}
	if(factorialB!=-1 && factorialB!=0)
	{
		if(validarFB==1)
		{
			printf("\n El resultado del factorial B da %.2f", factorialB);
		}
		else
		{
			printf("\n El factorial B no se ha podido realizar.");
		}
	}
	else
	{
		printf("\n El factorial B no se ha podido realizar.");
	}
}
