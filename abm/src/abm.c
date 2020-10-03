/*
 ============================================================================
 Name        : abm.c
 Author      : ED
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define QTY_EMPLOYEES 1000

int main(void)
{
	setbuf (stdout,NULL);

	Employee arrayEmpleados[QTY_EMPLOYEES];

	int option;
	int idEmployee=0;
	int auxiliaryIndex;
	int auxiliaryId;
	int order;

	int verifyOptionA = 0;


	if(initEmployees(arrayEmpleados,QTY_EMPLOYEES) == 0)
	{
		printf("Bienvenidos a la App de empleados. \n");
	}

    do
    {

    	if(!utn_getNumber(	&option,
    								"\n\n1.ALTA de empleados"
    								"\n2.MODIFICAR empleado"
    								"\n3.BAJA de empleados"
    								"\n4.INFORMAR"
    								"\n5.SALIR\n\n","\nError option inválida",1,5,3) )
    	{
    		switch(option)
    		{
    			case 1:
    				verifyOptionA= 1;
    				auxiliaryIndex = emp_getEmptyIndex(arrayEmpleados,QTY_EMPLOYEES);
    				if(auxiliaryIndex >= 0)
    				{
    					if(addEmployee(arrayEmpleados,QTY_EMPLOYEES,auxiliaryIndex,&idEmployee) == 0)
    					{
    						printf("\nEmpleado cargado con exito\n");
    					}
    					else
    					{
    						printf("\nNo se pueden cargar más empleados (Máximo: 1000 empleados)\n");
    					}
    				}
    				break;

    			case 2:
    				if(verifyOptionA== 1)
    				{
    					printEmployees(arrayEmpleados,QTY_EMPLOYEES);
    					if(utn_getNumber(&auxiliaryId,"\nIndique el ID del empleado a modificar:\n","\nID inválido\n",0,idEmployee,2) == 0)
    					{
    						auxiliaryIndex = findEmployeeById(arrayEmpleados,QTY_EMPLOYEES,auxiliaryId);
    						if(	auxiliaryIndex >= 0 && modEmployee(arrayEmpleados,QTY_EMPLOYEES,auxiliaryIndex) == 0)
    						{
    							printf("\nSe ha realizado la modifcación con éxito\n");
    						}
    					}
    				}
    				else
    				{
    					printf("Error! No es posible ingresar a esta opción antes de pasar por la 1\n\n");
    				}
    				break;

    			case 3:
    				if(verifyOptionA == 1)
    				{
    					printEmployees(arrayEmpleados,QTY_EMPLOYEES);
    					if(utn_getNumber(&auxiliaryId,"\nIndique el ID del empleado a dar de baja:\n","\nID inválido\n",0,idEmployee,2) == 0)
    					{
    						auxiliaryIndex = findEmployeeById(arrayEmpleados,QTY_EMPLOYEES,auxiliaryId);
    						if(	auxiliaryIndex >= 0 && removeEmployee(arrayEmpleados,QTY_EMPLOYEES,auxiliaryIndex) == 0)
    						{
    							printf("\nSe ha realizado la baja con exito\n");
    						}
    					}
    				}
    				else
    				{
    					printf("Error! No es posible ingresar a esta opción antes de pasar por la 1\n\n");
    				}
    				break;

    			case 4:
    				if(verifyOptionA== 1)
    				{
    					if(utn_getNumber(&order,"\nInformar de manera Ascendente opción (1), o Descendente opción (0)?\n","\nNumero inválido\n",0,1,2)==0)
    					{
    						if(sortEmployees(arrayEmpleados,QTY_EMPLOYEES,order) == 0)
    						{
    							printEmployees(arrayEmpleados,QTY_EMPLOYEES);
    							totalPromedioEmpleados(arrayEmpleados,QTY_EMPLOYEES);
    						}
    					}
    				}
    				else
    				{
    				    printf("Error! No es posible ingresar a esta opción antes de pasar por la 1\n\n");
    				}
    				break;

    			case 5:
    				printf("\n\n\n\n\n\n\n\n\n\n\n\n\nFIN DEL PROGRAMA\n\n\n\n\n");
    				break;

    		}
    	}
    }while(option!=5);

	return EXIT_SUCCESS;
}

