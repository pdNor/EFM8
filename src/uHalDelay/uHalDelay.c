/*
 * uHalDelay.c
 *
 *  Created on: 13 apr. 2018
 *      Author: Daniel Nordahl
 */
#include "uHalDelay.h"
#include "common.h"
extern void a_func (void);

/* Delay function using Timer 0 */
void uHalDelayUsecTimer( unsigned int us )
{
}

/* Delay function using nop instructions */
#if CPU_CLK == 9000000
void uHalDelayUsec( unsigned char us )
{
	/* Call delay function in assembly */
	a_func ();
}
#elif CPU_CLK == 3000000
void uHalDelayUsec( unsigned char us )
{
}
#endif
