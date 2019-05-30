/***************************************************************************/
/*     File name	:	ESP8266_Init.h				                       */
/*     Created date :	30/05/2019										   */
/*     Author		:   Martin Madliak									   */
/***************************************************************************/

#ifndef _ESP8266_INIT_h
#define _ESP8266_INIT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

/**************************** INCLUDES *************************************/
#include <ESP8266WiFi.h>
#include <time.h>
/***************************************************************************/

/**************************** DEFINES  *************************************/
/* Definition for UART Baud rate */
#define BAUD_RATE_D												(115200u)
/***************************************************************************/

/*********************** FUNCTION PROTOTYPES *******************************/
/* Funtion used to initialize UART communication interface */
extern void esp8266_init_vUartInitialization(void);

/* Funtion used to initialize Wifi module */
extern void esp8266_init_vWifiInitialzation(void);
/***************************************************************************/

#endif

