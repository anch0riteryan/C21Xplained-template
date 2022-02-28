#include <ModelTemplate.h>

void initClkInternal8MHz () {
	while (!OSCCTRL->STATUS.bit.OSC48MRDY);
	//OSCCTRL->OSC48MDIV.bit.DIV = 0; //48MHz
	//OSCCTRL->OSC48MDIV.bit.DIV = 1; //24MHz
	//OSCCTRL->OSC48MDIV.bit.DIV = 2; //16MHz
	OSCCTRL->OSC48MDIV.bit.DIV = 5; //8MHz
	//OSCCTRL->OSC48MDIV.bit.DIV = 11; //4MHz (default)

	while (GCLK->SYNCBUSY.bit.SWRST);
	GCLK->GENCTRL[0].bit.SRC = 6; //SOURCE=OSC48M
	GCLK->GENCTRL[0].bit.IDC = 1;

	SysTick_Config (7999);
}

void initClkXtal8MHz () {
	//Enable external crystal
	OSCCTRL->XOSCCTRL.bit.STARTUP = 5;
	OSCCTRL->XOSCCTRL.bit.GAIN = 2; // for 8MHz
	OSCCTRL->XOSCCTRL.bit.AMPGC = 1;
	OSCCTRL->XOSCCTRL.bit.XTALEN = 1; // enable XIN/XOUT pin
	OSCCTRL->XOSCCTRL.bit.ENABLE = 1;

	while (GCLK->SYNCBUSY.bit.SWRST);

	//Switch system main clk source
	GCLK->GENCTRL[0].bit.SRC = 0; //SOURCE=XOSC
	GCLK->GENCTRL[0].bit.IDC = 1;
	while (!OSCCTRL->STATUS.bit.XOSCRDY);

	SysTick_Config (7999);
}

void initGpio () {
	PORT->Group[0].DIRSET.reg = 1 << 15;
}
