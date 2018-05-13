# interrupthandler.c - Defines interrupt handler
# vim:ts=4 noexpandtab

.text

.gloabl pic_handler
.global keyboard_handler
.global rtc_handler
.global system_call_handler

pic_handler:
	pushad
    cld
    call    pic_interrupt
    popad
    iret

keyboard_handler:
	pushad
    cld
    call    keyboard_interrupt
    popad
    iret

rtc_handler:
	pushad
    cld
    call    rtc_interrupt
    popad
    iret

system_call_handler:
	pushad
    cld
    call    system_call_interrupt
    popad
    iret