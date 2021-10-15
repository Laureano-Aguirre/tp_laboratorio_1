/*
 * Aguirre.c
 *
 *  Created on: 14 may. 2021
 *      Author: Lau
 */

#include "Aguirre.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void getInt(char* mensaje, int* entero)
{
	printf(mensaje);
	scanf("%d", entero);
}
void getFloat(char* mensaje, float* flotante)
{
	printf(mensaje);
	scanf("%f", flotante);
}
void getString(char* mensaje, char* cadena)
{
	printf(mensaje);
	fflush(stdin);
	scanf("%[^\n]", cadena);
}
