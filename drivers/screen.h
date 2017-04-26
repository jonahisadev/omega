#ifndef SCREEN_H
#define SCREEN_H

#include "../kernel/common.h"

static u16 screen_color = 0x0F;
static u16 screen_x = 0;
static u16 screen_y = 0;

const static u16 VGA_WIDTH = 80;
const static u16 VGA_HEIGHT = 25;

static volatile u16* screen_vidmem = (u16*) 0xB8000;

void screen_clear();
void screen_putc(char c);
void screen_write(char* str);
void screen_setColor(u16 color);

#endif // SCREEN_H