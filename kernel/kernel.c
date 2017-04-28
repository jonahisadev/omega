#include "common.h"
#include "../drivers/screen.h"
#include "runtime/mem.h"
#include "cpu/idt.h"
#include "cpu/isr.h"

void kmain() {
	screen_clear();
	screen_write("Loading...\n");
	
	isr_install();
	
	screen_clear();
	screen_setColor(0x0A);
	screen_write("Omega OS v0.1\n\n");
	screen_setColor(0x0F);
	
	screen_write("Hello World!\n");
	
	asm volatile("int $8");
}