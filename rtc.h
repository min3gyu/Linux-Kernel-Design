/*	rtc.h
 *
 */

#ifndef _RTC_H
#define _RTC_H

#include "types.h"

#define RTC_ADDRESS_PORT	0x70
#define RTC_DATA_PORT	0x71

#define REGISTER_A	0xA
#define REGISTER_B	0xB
#define REGISTER_C	0xC

#define	UIP_MASK	0x80
#define ENABLE_PEOR_UPDATE 0x40

#define RTC_IRQ_LINE	0x8

void init_rtc(void);

void rtc_int_handler(void);

#endif