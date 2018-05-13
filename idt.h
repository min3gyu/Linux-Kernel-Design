/* idt.h - Defines Interrupt Descriptor Table
 *		   initialization part
 * vim:ts=4 noexpandtab
 */

#ifndef _IDT_H
#define _IDT_H

/* vectors for interrupts and system call */
#define PIC 		0x20
#define KEYBOARD	0x21
#define RTC			0x28
#define SYSTEM_CALL	0x80

/* Initialize idt */
extern void idt_init(void);

#endif /* _IDT_H */
