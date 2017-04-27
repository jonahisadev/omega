#ifndef COMMON_H
#define COMMON_H

typedef unsigned int 		u32;
typedef 		 int 		i32;
typedef unsigned short		u16;
typedef 		 short		i16;
typedef unsigned char 		u8;
typedef 		 char		i8;

#define FALSE 0
#define TRUE 1

void asm_outb(u16 port, u8 val);
u8 asm_inb(u16 port);
u16 asm_inw(u16 port);

//
//	IMPLEMENTATIONS
//

void asm_outb(u16 port, u8 val) {
	asm volatile("outb %1, %0" :: "dN"(port), "a"(val));
}

u8 asm_inb(u16 port) {
	u8 ret;
	asm volatile("inb %1, %0" : "=a"(ret) : "dN"(port));
	return ret;
}

u16 asm_inw(u16 port) {
	u16 ret;
	asm volatile("inw %1, %0" : "=a"(ret) : "dN"(port));
	return ret;
}

#endif // COMMON_H