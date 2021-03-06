/*
 * parser.h
 *
 *  Created on: 1 nov. 2021
 *      Author: Lau
 */

#ifndef PARSERH
#define PARSERH



#endif /* PARSERH */
#include "LinkedList.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_EmployeeFromTextW(FILE* pFile, LinkedList* pArrayListEmployee);

int parser_EmployeeFromBinaryW(FILE* pFile, LinkedList* pArrayListEmployee);
