/* interrupthandler.h - Defines interrupt handler
 * vim:ts=4 noexpandtab
 */

#ifndef _INTERRUPTHANDLER_H
#define _INTERRUPTHANDLER_H

extern void pic_handler();
extern void keyboard_handler();
extern void rtc_handler();
extern void system_call_handler();

#endif /* _INTERRUPTHANDLER_H */