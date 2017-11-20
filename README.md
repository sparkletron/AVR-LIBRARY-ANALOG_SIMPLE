# SIMPLE ANALOG INTERFACE

This is a simple analog interface. Which will allow you to read data from the ADC.

## Example

```c

#include <inttypes.h>
#include <avr/common.h>
#include <avr/io.h>
#include "analogSimple.h"


int main(void)
{
	initAnalog();
	
	for(;;)
	{
		uint16_t value = 0;
		
		//channel can be 0 to 5
		value = getAnalog(0);
	}
}
```
