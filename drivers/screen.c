#include "screen.h"

void screen_clear() {
	for (int x = 0; x < VGA_WIDTH; x++) {
		for (int y = 0; y < VGA_HEIGHT; y++) {
			screen_vidmem[y * VGA_WIDTH + x] = (screen_color << 8) | ' ';
		}
	}
	
	screen_x = 0;
	screen_y = 0;
}

void screen_putc(char c) {
	if (c == '\n') {
		screen_x = 0;
		screen_y++;
	} else {
		screen_vidmem[screen_y * VGA_WIDTH + screen_x++] = (screen_color << 8) | c;
		
		if (screen_x > VGA_WIDTH) {
			screen_x = 0;
			screen_y++;
		}
	}
}

void screen_write(char* str) {
	for (int i = 0; str[i] != '\0'; i++)
		screen_putc(str[i]);
}

void screen_setColor(u16 color) {
	screen_color = color;
}