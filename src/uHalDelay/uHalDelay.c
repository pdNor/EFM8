/*
 * uHalDelay.c
 *
 *  Created on: 13 apr. 2018
 *      Author: Daniel Nordahl
 */
#include "uHalDelay.h"
#include "common.h"
#include <SI_EFM8LB1_Register_Enums.h>

extern void delayUs (void);

/* Delay function using Timer 0 */
void uHalDelayUsecTimer( unsigned short int us )
{
	us = (us<<1)^0xFFFF;
	TL0 = (unsigned char)(us & 0xFF);
	TH0 = (unsigned char)(us >> 8);
	TCON |= (1<<4);
	while( (TCON & (1<<5)) == 0 )
	{
		//wait for timer to ovrf
	}
	TCON &=0xCF;
}

/* Delay function using nop instructions */
#if CPU_CLK == 9000000
void uHalDelayUsec( unsigned char us )
{
	/* Call delay function in assembly */
	delayUs();
}
#elif CPU_CLK == 3000000
void uHalDelayUsec( unsigned char us )
{
}
#endif
