/*
 * utn.c
 *
 *  Created on: Sep 5, 2020
 *      Author: ericka.diaz
 */
#include <stdio.h>
#include <stdlib.h>

int utn_getNumber(int* pResult, char* message, char* errorMessage, int minimum, int maximum, int retry){

	int bufferInt;
	int retorno = -1;
	int contadorIntentos = 0;

	if(pResult != NULL && message != NULL && errorMessage !=NULL && minimum <= maximum && retry >= 0)
	{
		do{
			printf("%s", message);
				scanf("%d", &bufferInt);
				if(bufferInt >= minimum && bufferInt <= maximum){
					*pResult = bufferInt;
					retorno = 0;
					break;
				}else{
					printf("%s", ErrorMessage);
					retry--;
				}

		}while(retry > 0);
	}
	return retorno;
}

