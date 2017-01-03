/**
 * @file:					user_LPC1114.h
 * @author:		
 * @purpose: 			deklaracje ustawien portu setrujacego dioda LED
 * @version:			v2.0
 * @date:					22 luty 2016
 * 
 * @Description:	dioda LED dolaczona do linii PIO0_7
*/

#define PORT_LED 					0			// numer portu dla diody LED
#define PIN_LED 					7			// linia portu sterujaca dioda LED

#define	PORT_MODE_IN			0			// wejsciowy tryb pracy linii 
#define PORT_MODE_OUT			1			// wyjsciowy tryb pracy linii 

#define LED_OFF 					0			// stan wylaczenia diody LED
#define LED_ON 						1			// stan wlaczenia diody LED

#define LED_CZAS_ON			 10			// czas wlaczenia diody LED w ms
#define LED_CZAS_OFF		  5			// czas wylaczenia diody LED w ms			
