#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployees.h"
#include "utn.h"


/**
 * \brief Inicializa el array poniendo en todas las posiciones a isEmpty en 1
 * \param list Array de empleados a ser actualizado
 * \param len limite del array de empleados
 * \return Retorna 0  exito y -1 error
 *
 */
int initEmployees(Employee* list, int len)
{
	int reply=-1;
	int i;

	if(list != NULL && len > 0)
	{
		reply=0;
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = 1;
		}
	}

return reply;
}


/**
 * \brief Buscar primer posicion vacia
 * \param list Array de empleados
 * \param len Limite del array de empleados
 * \return Retorna el indice de la posicion vacia y -1 error
 *
 */
int emp_getEmptyIndex(Employee* list,int len)
{
	int reply = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i = 0; i < len ; i++)
		{
			if(list[i].isEmpty == 1)
			{
				reply = i;
				break;
			}
		}
	}
	return reply;
}

/**
 * \brief Da de alta un empleado en una posicion del array
 * \param list Array de empleados a ser actualizado
 * \param len limite del array de empleados
 * \param indice posicion a ser actualizada
 * \param id identificador a ser asignado al empleado
 * \return Retorna 0  exito y -1 error
 *
 */
int addEmployee(Employee* list, int len, int indice, int* id)
{
	int reply = -1;
	Employee bufferEmpleado;

	if(list != NULL && len > 0 && indice < len && indice >= 0 && id != NULL)
	{
		if(	utn_getName(bufferEmpleado.name,NAME_LEN,"\nNombre del empleado?\n","\nERROR\n",2) == 0 &&
			utn_getName(bufferEmpleado.lastName,LAST_NAME_LEN,"\nApellido del empleado?\n","\nERROR\n",2) == 0 &&
			utn_getNumberFloat(&bufferEmpleado.salary,"\nSalario del empleado?\n","\nERROR\n",0,100000,2) == 0 &&
			utn_getNumber(&bufferEmpleado.sector,"\nEn que sector se encuentra?\n\n1-RRHH\n2-DISEÑO\n3-TECNOLOGÍA","\nERROR\n",1,3,2) == 0)
		{
			reply = 0;
			bufferEmpleado.id = *id;
			bufferEmpleado.isEmpty = 0;
			list[indice] = bufferEmpleado;
			(*id)++;
		}
	}
	return reply;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param list Array de empleados
* \param len Limite del array de empleados
* \param id Puntero a la posicion del array donde se encuentra el valor buscado
*/
int findEmployeeById(Employee* list, int len,int id)
{
	int reply = -1;
	int i;

	if(list != NULL && len > 0 && id >= 0)
	{
		for(i = 0;i < len; i++)
		{
			if(list[i].id == id)
			{
				reply = i;
				break;
			}
		}
	}
	return reply;
}


/**
 * \brief Actualiza los datos de un empleado en una posicion del array
 * \param list Array de empleados a ser actualizado
 * \param len Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \return Retorna 0  exito y -1 error
 *
 */
int modEmployee(Employee* list, int len, int indice)
{
	int reply=-1;
	int opcion;
	Employee arrayAuxiliary;

	if(list != NULL && len > 0 && indice < len && indice >= 0 && list[indice].isEmpty == 0)
	{
		if(utn_getNumber(&opcion,"\n\nIngrese el numero de lo que desea modificar: \n1-Nombre \n2-Apellido"
					"\n3-Salario \n4-Sector\n\n","\nError opción inválida",1,5,2)==0)
		{
			switch(opcion)
			{
				case 1:
					if(utn_getName(arrayAuxiliary.name,NAME_LEN,"\nIngrese el nuevo nombre:\n","\nNombre inválido\n",2) ==0)
					{
						strncpy(list[indice].name,arrayAuxiliary.name,NAME_LEN);
					}
					break;

			    case 2:
					if(utn_getName(arrayAuxiliary.lastName,LAST_NAME_LEN,"\nIngrese el nuevo apellido:\n","\nApellido inválido\n",2) == 0)
					{
						strncpy(list[indice].lastName,arrayAuxiliary.lastName,LAST_NAME_LEN);
					}
			    	break;

			    case 3:
					if(utn_getNumberFloat(&arrayAuxiliary.salary,"\nIngrese el nuevo salario:\n","\nSalario inválido\n",0,100000,2) == 0)
					{
						list[indice].salary = arrayAuxiliary.salary;
					}
			    	break;

			    case 4:
					if(utn_getNumber(&arrayAuxiliary.sector,"\nIngrese el nuevo sector:\n\n1-RRHH\n2-DISEÑO\n3-TECNOLOGÍA","\nSector inválido\n",1,3,2) ==0)
					{
						list[indice].sector = arrayAuxiliary.sector;
					}
			    	break;
			 }
			reply = 0;
		}
	}
	return reply;
}

/**
 * \brief Elimina lo cargado en una posicion del array
 * \param list Array de empleados a ser actualizado
 * \param len Limite del array de empleados
 * \param id Posicion a ser actualizada
 * \return retorna 0  exito y -1 error
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
	int reply = -1;
	if(list != NULL && len > 0 && id < len && id >= 0 && list[id].isEmpty == 0)
	{
		list[id].isEmpty = 1;
		reply = 0;
	}
	return reply;
}


/** \brief Sortea los elementos en el Array de empleados de menor a moayor
 * o viceversa
* \param list Array de empleados a ser actualizado
* \param len Limite del array de empleados
* \param order [1] ascendente - [0] descendente
*/
int sortEmployees(Employee* list, int len, int order)
{
	int reply=-1;
	Employee arrayAuxiliary;

    switch(order)
    {
        case 1:
            for(int i = 0; i < len ;i++)
            {
                for(int j = i+1 ;j < len; j++)
                {
                    if(list[i].sector > list[j].sector)
                    {
                    	arrayAuxiliary = list[i];
                        list[i] = list[j];
                        list[j] = arrayAuxiliary;
                        reply = 0;
                    }
                    else if(list[i].sector == list[j].sector && strcmp(list[i].lastName,list[j].lastName))
                    {
                    	arrayAuxiliary = list[i];
                    	list[i] = list[j];
                    	list[j] = arrayAuxiliary;
                        reply = 0;
                    }
                }
            }
            break;

        case 0:
            for(int i = 0; i<len; i++)
            {
                for(int j = i+1; j<len; j++)
                {
                    if(list[i].sector < list[j].sector)
                    {
                    	arrayAuxiliary = list[i];
                        list[i] = list[j];
                        list[j] = arrayAuxiliary;
                        reply= 0;
                    }
                    else if(list[i].sector == list[j].sector && strcmp(list[i].lastName,list[j].lastName))
                    {
                        arrayAuxiliary = list[i];
                        list[i] = list[j];
                        list[j] = arrayAuxiliary;
                        reply= 0;
                    }
                }
            }
            break;
    }

	return reply;
}
/**
 * \brief Imprime los datos de un empleado
 * \param list Puntero al empleado que se busca imprimir
 * \return Retorna 0  exito y -1 error
 *
 */
int emp_imprimir(Employee* list)
{
	int reply=-1;
	if(list != NULL && list->isEmpty == 0)
	{
		reply=0;
		printf("\nID del Empleado: %d \nNombre: %s \nApellido: %s \nSalario: %0.2f \nSector: %d\n",list->id,list->name,list->lastName,list->salary,list->sector);
	}
	return reply;
}

/**
 * \brief Imprime la lista de empleados
 * \param list Array de empleados a imprimir
 * \return Retorna 0  exito y -1 error
 *
 */
int printEmployees(Employee* list, int length)
{
	int reply = -1;
	int i;
	if(list != NULL && length > 0)
	{
		reply = 0;
		for(i = 0;i < length; i++)
		{
			emp_imprimir(&list[i]);
		}
	}
	return reply;
}
/** \brief Total del salario de empleados, el promedio de todos los salarios
 * y que salario excede el promedio
* \param list Array de empleados a calcular
* \param length Limite del array de empleados
*/
void totalPromedioEmpleados(Employee* list, int len)
{
	float totalSalario;
	float promedioSalario;
	int contador = 0;
	int empMasPromedio = 0;
	int i;

	for(i = 0; i < len ; i++)
	{
        if(list[i].isEmpty == 0){
            totalSalario = list[i].salary + totalSalario;
            contador++;
        }
	}

	promedioSalario = totalSalario/contador;

    for(i = 0; i < len; i++){
        if(list[i].salary > promedioSalario && list[i].isEmpty == 0){
        	empMasPromedio++;
        }
    }

    printf("\n\nEl total de los salarios es de: $%.2f \n",totalSalario);
    printf("El promedio de los salarios es de: $%.2f \n",promedioSalario);
    printf("La cantidad de empleados que superan el promedio es de: %d \n",empMasPromedio);

}
