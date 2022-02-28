#include <ModelTemplate.h>

int main (void ) {

	initClkInternal8MHz ();
	initGpio ();

	//NVIC_EnableIRQ (xx_IRQn);
	__enable_irq ();

	while (1) {
		//
	}
}
