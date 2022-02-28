#include <ModelTemplate.h>

void SysTick_Handler (void ) {
	static uint16_t count = 0;
	static uint8_t s = 0;

	if (count < 1000) {
		count++;
	} else {
		count = 0;

		if (s) {
			PORT->Group[0].OUTCLR.reg = 1 << 15;
		} else {
			PORT->Group[0].OUTSET.reg = 1 << 15;
		}

		s ^= 1;
	}
}
