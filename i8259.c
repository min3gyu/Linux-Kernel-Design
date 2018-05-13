/* i8259.c - Functions to interact with the 8259 interrupt controller
 * vim:ts=4 noexpandtab
 */

#include "i8259.h"
#include "lib.h"

#define MASTER_8259_PORT_2 (MASTER_8259_PORT+1)
#define SLAVE_8259_PORT_2 (SLAVE_8259_PORT+1)

#define MASKED_INT	0xFF

/* Interrupt masks to determine which interrupts are enabled and disabled */
uint8_t master_mask; /* IRQs 0-7  */
uint8_t slave_mask;  /* IRQs 8-15 */

/* Initialize the 8259 PIC */
void i8259_init(void) {
	unsigned char MASTER_, SLAVE_;

	master_mask = MASKED_INT;
	slave_mask = MASKED_INT;

	MASTER_ = inb(MASTER_8259_PORT_2);
	SLAVE_ = inb(SLAVE_8259_PORT_2);

	outb(ICW1, MASTER_8259_PORT);
	outb(ICW2_MASTER, MASTER_8259_PORT_2);
	outb(ICW3_MASTER, MASTER_8259_PORT_2);
	outb(ICW4, MASTER_8259_PORT_2);

	outb(ICW1, SLAVE_8259_PORT);
	outb(ICW2_SLAVE, SLAVE_8259_PORT_2);
	outb(ICW3_SLAVE, SLAVE_8259_PORT_2);
	outb(ICW4, SLAVE_8259_PORT_2);

	outb(MASTER_, MASTER_8259_PORT_2);
	outb(SLAVE_, SLAVE_8259_PORT_2);
}

/* Enable (unmask) the specified IRQ */
void enable_irq(uint32_t irq_num) {
	uint8_t unmasked_irq;

	unmasked_irq = MASKED_INT;

	if( (irq_num <= 7) || (irq_num >= 0) ){
		unmasked_irq ^= (1 << irq_num);

		master_mask &= unmasked_irq;
		outb(master_mask, MASTER_8259_PORT_2);
	}
	else if( (irq_num <= 15) || (irq_num >= 8) ){
		irq_num -= 8;

		unmasked_irq ^= (1 << irq_num);

		slave_mask &= unmasked_irq;
		OUTB(slave_mask, SLAVE_8259_PORT_2); 
	}

	return;
}

/* Disable (mask) the specified IRQ */
void disable_irq(uint32_t irq_num) {
	uint8_t masked_irq;

	if( (irq_num <= 7) || (irq_num >= 0) ){
		masked_irq = (1 << irq_num);

		master_mask |= masked_irq;
		outb(master_mask, MASTER_8259_PORT_2); 
	}
	else if( (irq_num <= 15) || (irq_num >= 8) ){
		irq_num -= 8;

		masked_irq = (1 << irq_num);

		slave_mask |= masked_irq;
		outb(slave_mask, SLAVE_8259_PORT_2);
	}

	return;
}

/* Send end-of-interrupt signal for the specified IRQ */
void send_eoi(uint32_t irq_num) {
	if( (irq_num <= 7) || (irq_num >= 0) ){
		outb( (EOI | irq_num), MASTER_8259_PORT);
	}
	else if( (irq_num <= 15) || (irq_num >= 8) ){
		irq_num -= 8;

		outb( (EOI | irq_num), SLAVE_8259_PORT);
		outb( (EOI | 0x02), MASTER_8259_PORT);
	}
}
