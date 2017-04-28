#include "common.h"
#include "../drivers/screen.h"
#include "runtime/mem.h"

void kmain() {
	screen_clear();
	
	u8 num = 42;
	
	screen_setColor(0x0A);
	screen_write("Omega OS v0.1\n\n");
	screen_setColor(0x0F);
	
	screen_write("Here's a cool number: ");
	screen_writeNum(num);
	screen_write("\nHere's a pointer to that number: ");
	screen_writeHex((u32)&num);
	
	u32* list = (u32*) kmalloc(sizeof(u32) * 5);
	for (int i = 0; i < 5; i++) {
		list[i] = (i + 1) * 5;
	}
	
	screen_write("\nCrappy memory managed list: ");
	for (int i = 0; i < 5; i++) {
		screen_writeNum(list[i]);
		if (i != 4)
			screen_write(", ");
	}
	screen_write("\n");
}