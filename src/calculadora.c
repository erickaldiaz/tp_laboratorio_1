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
#include "utn.h"

int main(void) {
	setbuf (stdout,NULL);

	int option;
	int reply;
	int numberA;
	int numberB;
	int sumResult;
	int subtractionResult;
	int multiplicationResult;
	int divisionResult;
	int verifyDivision;
	int factorials;


	do{

		printf("*****Calculadora*****");
		printf("\nIngrese un numero");
//		reply = utn_getNumero(&option, "Seleccione una opción:\n1-Leer\n2-Mostrar\n3-Salir\n,""No es una opción\n", 1,3,2);
//			if(!reply){
//				switch(option){
//				case 1:
//					printf("Entre al caso 1\n");
//					break;
//				case 2:
//					printf("Entre al caso 2\n");
//					break;
//				}
//			}
	}while(option == "si");

	return EXIT_SUCCESS;
}
