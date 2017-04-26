#include "common.h"

volatile u16* vidmem = (u16*) 0xB8000;

void kmain() {
	vidmem[0] = ((u16)0x0F << 8) | 'A';
}