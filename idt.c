/* idt.c - function to initialize the Interrupt Descriptor Table
 * vim:ts=4 noexpandtab
 */
#include "lib.h"
#include "idt.h"
#include "x86_desc.h"

// Divide Error
void division_error () {
	printf("Division Error.");
}

// RESERVED
void reserved () {
	printf("Reserved.");
}

// NMI Interrupt
void NMI () {
	printf("Non-Maskable Interrupt Exception.");
}

// Breakpoint
void breakpoint () {
	printf("Breakpoint Exception.");
}

// Overflow
void overflow () {
	printf("Overflow Exception.");
}

// BOUND Range Exceeded
void bounds () {
	printf("Bounds Exception.");
}

// Invalid Opcode (Undefined Opcode)
void invalid_opcode () {
	printf("Invalid Opcode Exception.");
}

// Device Not Available (No Math Coprocessor)
void coprocessor_invalid () {
	printf("Invalid Coprocessor Exception.");
}

// Double Fault
void double_fault () {
	printf("Double Fault Exception.");
}

// Coprocessor Segment Overrun (reserved)
void coprocessor_segment_overrun () {
	printf("Coprocessor Segment Overrun Exception.");
}

// Invalid TSS
void invalid_task_state_segment () {
	printf("Invalid Task State Segment Exception.");
}

// Segment Not Present
void segment_not_present () {
	printf("Segment Not Present Exception.");
}

// Stack-Segment Fault
void stack_fault () {
	printf("Stack Fault Exception.");
}

// General Protection
void general_protection_fault () {
	printf("General Protection Fault Exception.");
}

// Page Fault
void page_fault () {
	printf("Page Fault Exception.");
}

// x87 FPU Floating-Point Error (Math Fault)
void math_fault () {
	printf("Math Fault Exception.");
}

// Alignment Check
void alignment_check () {
	printf("Alignment Check Exception.");
}

// Machine Check
void machine_check () {
	printf("Machine Check Exception.");
}

// SIMD Floating-Point Exception
void SIMD_floating_point () {
	printf("SIMD Floating Point Exception.");
}

/* Initialize the IDT */
void idt_init(void) {
	//int index;		/* index for loop */
	/*for (index = 0; i < NUM_VEC; i++) {
		idt[index].seg_selector = 0x0;	// should work on here later
		idt[index].reserved4 = 0x0;
		idt[index].reserved3 = 0x1;
		idt[index].reserved2 = 0x1;
		idt[index].reserved1 = 0x1;
		idt[index].reserved0 = 0x0;
		idt[index].size = 0x0;
		idt[index].dpl = 0x0;
		idt[index].present = 0x0;
	}
	idt[SYSTEM_CALL].dpl = 0x3;*/

	SET_IDT_ENTRY(idt[0], division_error);
	SET_IDT_ENTRY(idt[1], reserved);
	SET_IDT_ENTRY(idt[2], NMI);
	SET_IDT_ENTRY(idt[3], breakpoint);
	SET_IDT_ENTRY(idt[4], overflow);
	SET_IDT_ENTRY(idt[5], bounds);
	SET_IDT_ENTRY(idt[6], invalid_opcode);
	SET_IDT_ENTRY(idt[7], coprocessor_invalid);
	SET_IDT_ENTRY(idt[8], double_fault);
	SET_IDT_ENTRY(idt[9], coprocessor_segment_overrun);
	SET_IDT_ENTRY(idt[10], invalid_task_state_segment);
	SET_IDT_ENTRY(idt[11], segment_not_present);
	SET_IDT_ENTRY(idt[12], stack_fault);
	SET_IDT_ENTRY(idt[13], general_protection_fault);
	SET_IDT_ENTRY(idt[14], page_fault);
	SET_IDT_ENTRY(idt[16], math_fault);
	SET_IDT_ENTRY(idt[17], alignment_check);
	SET_IDT_ENTRY(idt[18], machine_check);
	SET_IDT_ENTRY(idt[19], SIMD_floating_point);

	/*SET_IDT_ENTRY(idt[PIC], pic_handler);
	SET_IDT_ENTRY(idt[KEYBOARD], keyboard_handler);
	SET_IDT_ENTRY(idt[RTC], rtc_handler);
	SET_IDT_ENTRY(idt[SYSTEM_CALL], system_call_handler);*/

	lidt(idt_desc_ptr);
}
