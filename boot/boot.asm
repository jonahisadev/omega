[ORG 0x7C00]

main:
	mov bp, 0x8000
	mov sp, bp
	
	mov bx, HELLO
	call print
	call print_nl
	
	jmp $
	
%include "boot/print.asm"

HELLO: db "Hello BIOS!",0
	
times 510 - ($ - $$) db 0
dw 0xAA55