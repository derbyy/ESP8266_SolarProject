/***************************************************************************/
/*     File name	:	ESP8266_SolarProject_new.ino                       */
/*     Created date :	30/05/2019										   */
/*     Author		:   Martin Madliak									   */
/***************************************************************************/

/**************************** INCLUDES *************************************/
#include "ESP8266_Init.h"
#include <FS.h>
//#include <ArduinoJson.h>
/***************************************************************************/

time_t time_now;
bool bIsOpened = false;
char time_output[30];

void setup() 
{

	/* UART communication interface initialization */
	esp8266_init_vUartInitialization();

	SPIFFS.begin();
	bIsOpened = SPIFFS.exists("config.json");
	//SPIFFS.open("config.json", "r");

	if (bIsOpened)
	{
		Serial.println("Config file exists !!! ");
	}
	else
	{
		Serial.println("No config file !!! ");
	}

	/* Wifi module initialization */
	esp8266_init_vWifiInitialzation();

	/* Configure Time zone */
	configTime(0, 0, "pool.ntp.org", "time.nist.gov");
	setenv("TZ", "CET-1CEST,M3.5.0,M10.5.0/3", 1);
}


void loop() 
{
	time(&time_now);
	strftime(time_output, 30, "%a  %d-%m-%y %T", localtime(&time_now));

	Serial.println(time_output);
	delay(1000);
}
