/*

 * 7-segment.c
 *
 *  Created on: Dec 9, 2018
 *      Author: hosam
 */

#include "segment.h"


segment_print(unsigned char command,unsigned char data)
{
	PORTB&=~(1<<SS);  //initializing the packet by pull SS low
	SPDR=command;   //start transmission
	while(!(SPSR&(1<<SPIF)));  //wait for transfer finish
	SPDR=data;  //start transmission
	while(!(SPSR&(1<<SPIF)));  //wait for transfer finish
	PORTB|=(1<<SS);  //terminate the packet by pull SS high
}


segment_init(void)
{
	DDRB=(1<<MOSI)|(1<<SCK)|(1<<SS);  //MOSI,SCK and SS are output
	SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0);  //enable SPI,master mode,SCK=Fosc/16
	segment_print(0x0B,segments);  //number of 7-segments will be scanned
	segment_print(0x0C,0x01);  //turn on the chip
}


