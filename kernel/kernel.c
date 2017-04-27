#include "common.h"
#include "../drivers/screen.h"

void kmain() {
	screen_clear();
	
	u8 num = 42;
	
	screen_write("Omega OS v0.1\n");
	screen_write("Here's a cool number: ");
	screen_writeNum(num);
	screen_write("\nHere's a pointer to that number: ");
	screen_writeHex((u32)&num);
}