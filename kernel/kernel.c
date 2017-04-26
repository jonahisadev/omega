#include "common.h"
#include "../drivers/screen.h"

void kmain() {
	screen_setColor((u16)0x1F);
	screen_clear();
	screen_write("Hello world!\n");
	screen_write("Isn't this cool?");
}