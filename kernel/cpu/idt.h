#ifndef IDT_H
#define IDT_H

#include "../common.h"

#define KERNEL_CS 0x08

typedef struct _idt_gate {
	u16 low;
	u16 sel;
	u8 nil;
	u8 flags;
	u16 high;
}__attribute__((packed)) idt_gate_t;

typedef struct _idt_register {
	u16 limit;
	u32 base;
}__attribute__((packed)) idt_register_t;

#define IDT_ENTRIES 256
idt_gate_t idt[IDT_ENTRIES];
idt_register_t idt_reg;

void set_idt_gate(int n, u32 handler);
void set_idt();

//
//	IMPLEMENTATIONS
//

void set_idt_gate(int n, u32 handler) {
	idt[n].low = (u16)(handler & 0xFFFF);
	idt[n].sel = KERNEL_CS;
	idt[n].nil = 0;
	idt[n].flags = 0x8E;
	idt[n].high = (u16)((handler >> 16) & 0xFFFF);
}

void set_idt() {
	idt_reg.base = (u32)&idt;
	idt_reg.limit = IDT_ENTRIES * sizeof(idt_gate_t) - 1;
	__asm__ __volatile__("lidtl (%0)" :: "r" (&idt_reg));
}

#endif // IDT_H