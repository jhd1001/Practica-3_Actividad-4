/*
 * UART.c
 *
 *  Created on: 17/12/2014
 *      Author: Alejandro
 */
#include "AS1.h"
#include "UART.h"

char mensaje[][5] = {"  X: ", "  Y: ", "  Z: "};
word env;

void UART_Write_Numero_Int(char eje, unsigned int numero, short conSalto)
{
	while(AS1_SendBlock(&mensaje[eje-'X'], sizeof(mensaje[eje-'X']), &env)!= ERR_OK) {}
	while(AS1_SendChar((char)(48+(numero/10000)))!= ERR_OK) {};
	while(AS1_SendChar((char)(48+(numero%10000)/1000))!= ERR_OK) {};
	while(AS1_SendChar((char)(48+(numero%1000)/100))!= ERR_OK) {};
	while(AS1_SendChar((char)(48+(numero%100)/10))!= ERR_OK) {};
	while(AS1_SendChar((char)(48+(numero%10)))!= ERR_OK) {};
	if (conSalto) {
		while(AS1_SendChar((char)10)!= ERR_OK) {};
		while(AS1_SendChar((char)13)!= ERR_OK) {};
	}
}

