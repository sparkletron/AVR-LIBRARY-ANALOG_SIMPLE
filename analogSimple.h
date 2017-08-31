/*
 * analogSimple.h
 *
 *  Created on: Nov 9, 2014
 *      Author: John Convertino
 *		
 *		Sets up in single conversion mode to sample any analog input selected by getAnalog.
 *
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
 *
 */

#ifndef ANALOGSIMPLE_H_
#define ANALOGSIMPLE_H_

#include <inttypes.h>

void initializeAnalog();

uint16_t getAnalog(uint8_t);

#endif /* ANALOGSIMPLE_H_ */
