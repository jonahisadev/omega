#ifndef SCREEN_H
#define SCREEN_H

#include "../kernel/common.h"
#include "../kernel/runtime/string.h"
#include "../kernel/runtime/math.h"

static u16 screen_color = 0x0F;
static u16 screen_x = 0;
static u16 screen_y = 0;

const static u16 VGA_WIDTH = 80;
const static u16 VGA_HEIGHT = 25;

static volatile u16* screen_vidmem = (u16*) 0xB8000;

void screen_clear();
void screen_putc(char c);
void screen_write(char* str);
void screen_writeNum(u32 num);
<<<<<<< HEAD
void screen_writeHexPlace(u32 hex, u32 max);
=======
>>>>>>> 8c4574339de01b2bfb86612927423bc7503f11bb
void screen_writeHex(u32 hex);
void screen_setColor(u16 color);
void screen_scroll();

//
//	IMPLEMENTATION
//

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
	for (int i = 0; i < string_len(str); i++)
		screen_putc(str[i]);
}

void screen_writeNum(u32 num) {
	u32 base = 10;
	u32 x = 2;
	
	if (num < 10) {
		screen_putc((char)num + 0x30);
		return;
	}
	
	while (TRUE) {
		if (num - pow(base, x) >= num) {
			break;
		}
		x++;
	}
	x--;
	
	u8 done = FALSE;
	u32 val = num;
	while (!done) {
		u32 sub = pow(base, x);
		u16 count = 0;
		while (val >= sub) {
			val -= sub;
			count++;
		}
		screen_putc((char)count + 0x30);
		x--;
		if (val == 0)
			done = TRUE;
	}
}

void screen_writeHexPlace(u32 hex, u32 max) {
	screen_write("0x");
	for (int i = 1; i < max+1; i++) {
		u32 mask = (0xF << ((max - i) * 4));
		u32 c = (hex & mask) >> ((max - i) * 4);
		c += 0x30;
		if (c >= 0x39)
			c += 7;
		screen_putc((char)c);
	}
}

void screen_writeHex(u32 hex) {
	screen_writeHexPlace(hex, 8);
}

void screen_setColor(u16 color) {
	screen_color = color;
}

void screen_scroll() {
	for (int y = 0; y < VGA_HEIGHT-1; y++) {
		for (int x = 0; x < VGA_WIDTH; x++) {
			screen_vidmem[y * VGA_WIDTH + x] = screen_vidmem[(y * VGA_WIDTH + x) + 80];
		}
	}
	screen_y--;
}

#endif // SCREEN_H