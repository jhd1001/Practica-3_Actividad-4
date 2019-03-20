/* ###################################################################
**     Filename    : main.c
**     Project     : Practica 3_Actividad 4
**     Processor   : MK64FN1M0VLQ12
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-02-22, 20:11, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Pins1.h"
#include "SWITCH2.h"
#include "ExtIntLdd1.h"
#include "GI2C1.h"
#include "WAIT1.h"
#include "CI2C1.h"
#include "FX1.h"
#include "MCUC1.h"
#include "SWITCH3.h"
#include "ExtIntLdd2.h"
#include "TI1.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
#include "AS1.h"
#include "ASerialLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include "stdio.h"

// se inicializa en el eje W (previo al eje X)
char eje = 'W';
short muestreo = FALSE;
short periodico = FALSE;
uint16_t valor;
uint16_t x, y, z;


/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  FX1_Enable();
  TI1_Disable();

  /* For example: for(;;) { } */
  for (;;) {
	  if (muestreo) {
		  // si el eje es X, Y o Z
		  switch (eje) {
			  case 'X': valor = FX1_MeasureGetRawX(); break;
			  case 'Y': valor = FX1_MeasureGetRawY(); break;
			  case 'Z': valor = FX1_MeasureGetRawZ(); break;
		  }
		  UART_Write_Numero_Int(eje, valor*100/0xFFFF, TRUE);
		  muestreo = FALSE;
	  }
	  if (periodico) {
		  x = FX1_MeasureGetRawX();
		  y = FX1_MeasureGetRawY();
		  z = FX1_MeasureGetRawZ();
		  UART_Write_Numero_Int('X', x*100/0xFFFF, FALSE);
		  UART_Write_Numero_Int('Y', y*100/0xFFFF, FALSE);
		  UART_Write_Numero_Int('Z', z*100/0xFFFF, TRUE);
		  periodico = FALSE;
	  }
  }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
