/*
 ============================================================================
 Name        : calculadora.c
 Author      : ED
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


int main(void)
{
	setbuf(stdout,NULL);

	int option;
	int reply;
	float numberA = 0;
	float numberB = 0;
	float sumResult;
	float subtractionResult;
	float multiplicationResult;
	float divisionResult;
	int verifyDivision;
	double factorialsA;
	double factorialsB;

	int verifyOption3A = 0;
	int verifyOption3B = 0;

	char text1[45];
	char text2[45];
	char menu[300] = "";

	  do
	    {


		  snprintf(text1, 45, "1. Ingresar el primer número (A=%f)\n", numberA);
		  snprintf(text2, 45, "2. Ingresar segundo número (B=%f)\n", numberB);

		  strcpy(menu,"Bienvenid@ a la calculadora\n\n");
		  strcat(menu,"Seleccione una opción:\n\n");
		  strcat(menu,text1);
		  strcat(menu,text2);
		  strcat(menu,"3. Calcular todas las operaciones\n");
		  strcat(menu,"4. Informar resultados\n5. Salir\n");

		  reply = utn_getNumber(&option,menu,"No es una opción válida\n\n",1,5,2);

	    	if(reply==0)
	    	{
	    		switch(option)
	    		{
	    			case 1:
	    				verifyOption3A= 1;
	    				printf("Ingrese el primer número:\n");
	    				fflush(stdin);
	    				scanf("%f",&numberA);
	    				break;

	    			case 2:
	    				verifyOption3B = 1;
	    				printf("Ingrese el segundo número:\n");
	    				fflush(stdin);
	    				scanf("%f",&numberB);
	    				break;

	    			case 3:

	    				if(verifyOption3A== 1 && verifyOption3B == 1){

	    					sumResult = sum(numberA,numberB);
	    					subtractionResult = subtraction(numberA,numberB);
	    					multiplicationResult = multiply(numberA,numberB);
	    					verifyDivision = divide(&divisionResult,numberA,numberB);
	    					factorialsA = factor(numberA);
	    					factorialsB = factor(numberB);
	    					printf("Se calcularon las operaciones.\n\n");
	    				}
	    				else
	    				{
	    					printf("Error! No es posible ingresar a esta opción antes de pasar por la 1 y 2\n\n");
	    				}

	    				break;

	    			case 4:
	    				printf("El resultado del número 1 + número 2 es: %f\n", sumResult);
	    				printf("El resultado del número 1 - número 2 es: %f\n", subtractionResult);
	    				printf("El resultado del número 1 * número 2 es: %f\n", multiplicationResult);

	    				if(verifyDivision == 0)
	    				{
	    					printf("El resultado del número 1 / número 2 es: %f\n", divisionResult);
	    				}
	    				else
	    				{
	    					printf("No es posible dividir por cero\n\n");
	    				}

	    				printf("El factorial del número 1 es: %lf\n", factorialsA);
	    				printf("El factorial del número 2 es: %lf\n\n\n",factorialsB);

	    				break;
	    		}
	    	}
	    }while(option != 5);
	}
