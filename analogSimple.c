/*
 * analogSimple.c
 *
 *  Created on: Nov 9, 2014
 *      Author: John Convertino
 *
 *		Sets up in single conversion mode to sample any analog input selected by getAnalog
 *
    Copyright (C) 2014 John Convertino

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

 *		Version: v0.1
 *		Nov 9, 2014 v0.1	initial setup for single conversion mode
 *
 *		TODO
 */

#include <avr/common.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "analogSimple.h"
#include "commonDefines.h"

void initAnalog()
{
	uint8_t tmpSREG = 0;

	tmpSREG = SREG;
	cli();

	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	ADMUX |= (1 << REFS0);

	SREG = tmpSREG;
}

uint16_t getAnalog(uint8_t channel)
{
	uint8_t tmpSREG = 0;
	//create buffer for analog input value
	uint16_t buffer = 0;

	tmpSREG = SREG;
	cli();

	//Selection of pin to read.
	ADMUX |= channel;
	ADMUX &= (MASK_8BIT_FF << 4) | channel;
	ADCSRA |= (1 << ADSC);
	//busy wait till conversion complete
	while(ADCSRA & (1 << ADSC));
	//read lower eight bits and assign to buffer
	buffer = ADCL;
	//than read high bits and shift to correct bit location.
	buffer |= ADCH << 8;

	SREG = tmpSREG;

	return buffer;
}
