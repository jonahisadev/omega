[ORG 0x7C00]

main:
	mov [BOOT_DRIVE], dl

	mov bp, 0x8000
	mov sp, bp
	
	mov bx, HELLO
	call print
	call print_nl
	
	call switch_mode
	
	jmp $
	
%include "boot/print.asm"
%include "boot/disk.asm"
%include "boot/gdt.asm"
%include "boot/switch.asm"

BEGIN_32:
	mov ebx, HELLO32
	call print32
	
	jmp $

HELLO: db "Hello BIOS!",0
BOOT_DRIVE: db 0
HELLO32: db "Hello 32-bit!",0

times 510 - ($ - $$) db 0
dw 0xAA55

times 256 dw 0xACDC
times 256 dw 0xFACE