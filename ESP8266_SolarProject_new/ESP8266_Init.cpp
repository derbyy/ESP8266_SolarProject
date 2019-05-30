/***************************************************************************/
/*     File name	:	ESP8266_Init.cpp			                       */
/*     Created date :	30/05/2019										   */
/*     Author		:   Martin Madliak									   */
/***************************************************************************/

/**************************** INCLUDES *************************************/
#include "ESP8266_Init.h"
/***************************************************************************/

/************************ STATIC VARIABLES *********************************/
static bool esp8266_init_bDebug = true;
/***************************************************************************/


/***************************************************************************/
/*     Function name	:	esp8266_init_vUartInitialization			   */
/*     Parameters	    :	void										   */
/*     Return type		:   void										   */
/*     Author			:   Martin Madliak                                 */		
/***************************************************************************/
void esp8266_init_vUartInitialization(void)
{
	/* Initialize GPIO15 pin and set it as OUTPUT */
	pinMode(D8, OUTPUT);

	/* Initialize UART communication interface */
	Serial.begin(BAUD_RATE_D);

	/* TODO: Swap to alternative pins(GPIO13 = Rx, GPIO15 = Tx) */
	//Serial.swap( D8 );

	while (!Serial)
	{
		;  /* Wait for serial port to initialize */
	}
	if (esp8266_init_bDebug)
	{
		Serial.println("Serial ready");
	}
}

/***************************************************************************/
/*     Function name	:	esp8266_init_vUartInitialization			   */
/*     Parameters	    :	void										   */
/*     Return type		:   void										   */
/*     Author			:   Martin Madliak                                 */
/***************************************************************************/
void esp8266_init_vWifiInitialzation(void)
{
	/* Set Wifi module mode */
	WiFi.mode(WIFI_STA);

	/* Connect to local Wifi */
	WiFi.begin("FRIPI", "Vypalen52");

	/* Wait for Wifi connection */
	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		if (esp8266_init_bDebug)
		{
			Serial.print(".");
		}
	}
	if (esp8266_init_bDebug)
	{
		Serial.println("");
		Serial.println("WiFi connected");
		Serial.print("IP address: ");
		Serial.println(WiFi.localIP());
	}
}

