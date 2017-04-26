#include "common.h"
#include "../drivers/screen.h"

void kmain() {
	screen_clear();
	
	screen_write("Line 1\n");
	screen_write("Line 2\n");
	screen_write("Line 3\n");
	
	screen_scroll();
	
	screen_write("Line 4\n");
}