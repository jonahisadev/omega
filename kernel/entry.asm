global _start
[BITS 32]

_start:
	[EXTERN kmain]
	call kmain
	jmp $