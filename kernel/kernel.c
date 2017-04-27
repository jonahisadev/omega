#include "common.h"
#include "../drivers/screen.h"

void kmain() {
	screen_clear();
	
	screen_write("This is a number I used to write more often: ");
	screen_writeNum(1209);
}