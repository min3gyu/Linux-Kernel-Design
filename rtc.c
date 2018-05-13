/*	rtc.c
 *
 */

#include "rtc.h"
#include "lib.h"
#include "i8259.h"

void init_rtc(void){
	unsigned char Prev_RTC_DATA;

	outb( (UIP_MASK | REGISTER_B), RTC_ADDRESS_PORT);

	Prev_RTC_DATA = inb(RTC_DATA_PORT);

	outb( (UIP_MASK | REGISTER_B), RTC_ADDRESS_PORT);

	outb( (ENABLE_PEOR_UPDATE | Prev_RTC_DATA), RTC_DATA_PORT);

	enable_irq(RTC_IRQ_LINE);
}

/*
void rtc_int_handler(void){
	send_eoi(RTC_IRQ_LINE);

	OUTB_P(REGISTER_C, RTC_ADDRESS_PORT);
	INB(RTC_DATA_PORT);
}*/