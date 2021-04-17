/*
 * utn.c
 *
 *      Author: ericka.diaz
 */
#include <stdio.h>
#include <stdlib.h>

int utn_getNumber(int* pResult, char* message, char* errorMessage, int minimum, int maximum, int retry){

	float bufferint;
	int returnAux = -1;


	if(pResult != NULL && message != NULL && errorMessage !=NULL && minimum <= maximum && retry >= 0)
	{
		do{
			printf("%s", message);
				scanf("%f", &bufferint);
				if(bufferint >= minimum && bufferint <= maximum){
					*pResult = bufferint;
					returnAux= 0;
					break;
				}else{
					printf("%s", errorMessage);
					retry--;
				}

		}while(retry > 0);
	}
	return returnAux;
}


float sum(float numberA,float numberB)

{
	float sumResult;

		sumResult = numberA + numberB;

	return sumResult;
}

float subtraction(float numberA, float numberB)
{
	float subtractionResult;

		subtractionResult = numberA - numberB;

	return subtractionResult;
}


float multiply(float numberA,float numberB)
{
	float multiplicationResult;

		multiplicationResult = numberA * numberB;

	return multiplicationResult;
}

float divide(float* pdivisionResult,float numberA, float numberB)

{
	float divisionResult;

	int returnAux  = -1;

	if(pdivisionResult != NULL && numberB != 0)
	{
		divisionResult = (float) numberA / numberB;

		*pdivisionResult = divisionResult;

			returnAux  = 0;
	}

	return returnAux ;
}

double factor(double numberFactorial)
{
	double factorial = 1;

	for (double i = numberFactorial ; i >= 1 ; i--)
	{
		factorial = factorial * i;
	}

	return factorial;
}
