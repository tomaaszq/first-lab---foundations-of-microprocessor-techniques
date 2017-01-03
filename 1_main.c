/**
 * @file:					1_main.c
 * @author:		
 * @purpose: 			przyklad uzycia GPIO w procesorze LPC1114/302 firmy NXP
 * @version:			v2.0
 * @date:					22 luty 2016
 * 
 * @Description:	- czestotliwosc taktowania mikrokontrolera:
**									XTAL = 12 MHz (wartosc domyslna)
**								- program	wlacza / wylacza diode LED (linia PIO0_7)
*/

// dolaczenie deklaracji nazw, typow i adresów rejestrów procesora
#include <LPC11xx.h>	

// dolaczenie nazw i prototypow funkcji obslugo GPIO
#include "gpio.h"

#include "user_LPC1114.h"
 

/**
 * @procedure:		Opoznienie
 * @author:		
 * @purpose: 			procedura opoznienia
 * @version:			v2.0
 * @date:					22 luty 2016
 * 
 * @Description:	- parametrem wejsciowym procedury jest opoznienie w ms
 *								- pojedyczy obieg petli trwa 1 ms
*/

// deklaracja pomocniczej 32-bitowej zmiennej k
uint32_t k;		

void Opoznienie(unsigned int czas_ms) {
	
	for (k = 0; k < czas_ms * 6000; k++);	 
}

/**
 * @author:		
 * @purpose: 			petla glowna main
 * @version:			v2.0
 * @date:					22 luty 2016
 * 
 * @Description:	petla glowna programu:
 *								- funkcja SystemInit() wywolywana w pliku StartUp_LPC11xx.s:		
 *								- czestotliwosc generatora taktujacego mikrokontroler:
 *									rezonator kwarcowy XTAL = 12 MHz
 *								- czestotliwosc wejsciowa petli PLL (Phase-Locked Loop):
 *									sys_pllclkin = XTAL = 12 MHz
 *								- mnoznik petli PLL = 4  
 *								- czestotliwosc wyjsciowa petli PLL: 
 *									MCLK (Main Clock)= 4 * XTAL = 48 MHz
 *								- dzielnik czestotliwosci taktujacej rdzen:
 *									SYSAHBCLKDIV (System AHB Clock Divider) = 1
 *								- czestotliwosc taktowania rdzenia:
 *									CCLK (Core Clock) = 4 * XTAL / SYSAHBCLKDIV = 48 MHz
 *								- odblokowanie taktowania GPIO (General Purpose I/O):
 *									LPC_SYSCON->SYSAHBCLKCTRL = (1<<6);	(wartosc domyslna)
*/

int main (void) {

/* ustalenie kierunku pracy linii PIO0_7 jako wyjsciowa
	 plik gpio.c:
		 GPIOSetDir(port num=0, bit position=7, direction=1 [1 out, 0 input])
		 Descriptions:	Set the direction in a specific bit position
										in GPIO portX(X is the port number)							 			*/
	GPIOSetDir(PORT_LED, PIN_LED, PORT_MODE_OUT);					
										
/* ustalenie stanu linii PIO0_7, linia w stanie LOW = dioda LED wylaczona
	 plik gpio.c:
		 GPIOSetValue(port num=0, bit position=7, bit value=0)
		 Descriptions:	Set/clear a bitvalue in a specific bit position
										in GPIO portX(X is the port number)							 			*/
	GPIOSetValue(PORT_LED, PIN_LED, LED_OFF);				
	
	while(1) {
	// wlaczenie diody LED, linia PIO0_7 w stanie ON (=1)
		GPIOSetValue(PORT_LED, PIN_LED, LED_ON);	
	
	// czas wlaczenia diody LED, procedura Opoznienie(LED_CZAS_ON)		
		Opoznienie(LED_CZAS_ON);					
		
	// wylaczenie diody LED, linia PIO0_7 w stanie OFF (=0)
		GPIOSetValue(PORT_LED, PIN_LED, LED_OFF);			

	// czas wylaczenia diody LED, procedura Opoznienie(LED_CZAS_OFF)				
		Opoznienie(LED_CZAS_OFF);
	}
}
