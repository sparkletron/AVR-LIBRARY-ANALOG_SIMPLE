/*******************************************************************************
 * @file    analogSimple.c
 * @author  Jay Convertino(electrobs@gmail.com)
 * @date    2014.11.09
 * @brief   defines
 * @details Collection defines
 * @version 0.0.1
 *
 * @TODO
 *  - Cleanup interface
 *
 * @license mit
 *
 * Copyright 2024 Johnathan Convertino
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 ******************************************************************************/

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
