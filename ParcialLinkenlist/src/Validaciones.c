/*
 * Validaciones.c
 *
 *  Created on: 4 nov. 2021
 *      Author: adrian
 */

#include <stdio.h> // windows
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Validaciones.h"

//		INPUT - VALIDACIONES

// MEJORA DEL FGETS
int myGets(char *string, int longitud) {
	int retorno=-1;
	char bufferString[4096];

	if (string != NULL && longitud > 0) {
		fflush(stdin); //Windows
		//__fpurge(stdin); // Linux
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL){
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud){
				strncpy(string, bufferString, longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

//PARA VALIDAR ENTEROS

/**
 * \brief Verifica si la string ingresada es numerica
 * \param string Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 */
int isNumber(char *string, int limite) {
	int retorno = 1;
	int i;
	for (i = 0; i < limite && string[i] != '\0'; i++) {
		if (i == 0 && (string[i] == '+' || string[i] == '-')) {
			continue;
		}
		if (string[i] > '9' || string[i] < '0') {
			retorno = 0;
			break;
		}
		//CONTINUE
	}
	//BREAK
	return retorno;
}

/**
 * \brief Obtiene un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int getInt(int* pResultado){
    int retorno=-1;
    char bufferString[50];
    if(	pResultado != NULL &&
    	getString(bufferString,sizeof(bufferString)) == 0 &&
    	isNumber(bufferString, sizeof(bufferString))) {
		retorno=0;
		*pResultado = atoi(bufferString) ;

	}
    return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError,
					int minimo, int maximo, int reintentos){
	int retorno = 1;
	int bufferInt;
	do{
		printf("%s",mensaje);
		if(	getInt(&bufferInt) == 0 &&
			bufferInt >= minimo &&
			bufferInt <= maximo){
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}

// PARA VALIDAR FLOTANTES

int esFlotante(char *string) {
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if (string != NULL && strlen(string) > 0) {
		for (i = 0; string[i] != '\0'; i++) {
			if (i == 0 && (string[i] == '-' || string[i] == '+')) {
				continue;
			}
			if (string[i] < '0' || string[i] > '9') {
				if (string[i] == '.' && contadorPuntos == 0) {
					contadorPuntos++;
				}
				else{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}
 int getFloat(float* pResultado){
	int retorno=-1;
	char buffer[64];

	if(pResultado != NULL){
		if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer)){
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError,
							float minimo, float maximo, int reintentos){
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0){
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0){
			if(bufferFloat >= minimo && bufferFloat <= maximo){
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

// PARA VALIDAR CADENAS

int getString(char *string, int longitud) {
	int retorno=-1;
	char bufferString[4096];

	if (string != NULL && longitud > 0) {
		fflush(stdin); //Windows
		//__fpurge(stdin); // Linux
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL){
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud){
				strncpy(string, bufferString, longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

 int getNombre(char* pResultado, int longitud){
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL){
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud){
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

int esNombre(char *string, int longitud) {
	int i=0;
	int retorno = 1;

	if (string != NULL && longitud > 0) {
		for (i = 0; string[i] != '\0' && i < longitud; i++) {
			if ((string[i] < 'A' || string[i] > 'Z')
					&& (string[i] < 'a' || string[i] > 'z')) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el array y -1 si no
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos){
	char bufferString[4096];
	int retorno = 1;
	while(reintentos>=0){
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 &&
				strnlen(bufferString,sizeof(bufferString)) < longitud ){
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}


/**
 * \brief Verifica si la cadena ingresada es una descripcion valida
 * \param string string de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 */
int esDescripcion(char *string, int longitud){
	int i=0;
	int retorno = 1;

	if (string != NULL && longitud > 0){
		for (i = 0; string[i] != '\0' && i < longitud; i++){
			if (string[i] != '.' && string[i] != ' '
					&& (string[i] < 'A' || string[i] > 'Z')
					&& (string[i] < 'a' || string[i] > 'z')
					&& (string[i] < '0' || string[i] > '9')){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Obtiene un string valido como descripcion
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 */
static int getDescripcion(char* pResultado, int longitud){
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL){
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esDescripcion(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud){
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Solicita una descripcion al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 */
int utn_getDescripcion(char* pResultado, int longitud,
						char* mensaje, char* mensajeError,
						int reintentos){
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0){
		reintentos--;
		printf("%s",mensaje);
		if(getDescripcion(bufferString,sizeof(bufferString)) == 0 &&
				strnlen(bufferString,sizeof(bufferString)) < longitud ){
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

void strMayuscula(char string[]) {
    int i=0;
	while (string[i] != '\0') {
		string[i] = toupper(string[i]);
        i++;
    }
}

void strMinuscula(char string[]) {
    int i=0;
	while (string[i] != '\0') {
		string[i] = tolower(string[i]);
        i++;
    }
}

void uppercaselInitial(char string[]){
	int quantity;
	int i;
	strMinuscula(string);
	string[0] = toupper(string[0]);
	quantity = strlen(string);
	for (i=0;i<quantity;i++){
		if (string[i]==' '){
			string[i+1] = toupper(string[i+1]);
		}
	}
	//puts(string);
}
void CargarTexto (char mensaje[], char texto[], int largo)
{
    printf("%s", mensaje);
    fflush(stdin);
    fgets(texto, largo, stdin);
    texto[strlen(texto)-1]='\0';
}
int utn_getText(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	int i;

	for(i=0; i<=reintentos; i++)
	{
		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
		{
			printf("%s",mensaje);
			fflush(stdin);
			if(myGetsUTN(pResultado, len)==0)
			{
				retorno = 0;
				break;
			}
			else
				printf("%s",mensajeError);
		}
	}
	return retorno;
}
int myGetsUTN(char pResultado[], int len)
{
    int retorno=-1;
    int indexFinal;
    fflush(stdin);
    if(fgets(pResultado,len,stdin)!=NULL)
    {
        // borro el \n del final
        indexFinal = strlen(pResultado)-1;
        if(pResultado[indexFinal] == '\n')
        {
            pResultado[indexFinal] = '\0';
        }
        retorno = 0;
    }
    return retorno;
}
