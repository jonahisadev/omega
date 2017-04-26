[ORG 0x7C00]

KERNEL_ENTRY equ 0x1000

main:
	mov [BOOT_DRIVE], dl

	mov bp, 0x8000
	mov sp, bp
	
	mov bx, LOADING
	call print
	call print_nl
	
	mov dh, 15
	mov bx, KERNEL_ENTRY
	mov dl, [BOOT_DRIVE]
	call disk_load
	
	call switch_mode
	
	jmp $
	
%include "boot/print.asm"
%include "boot/disk.asm"
%include "boot/gdt.asm"
%include "boot/switch.asm"

BEGIN_32:
	call KERNEL_ENTRY
	jmp $

LOADING: db "Loading kernel...",0
BOOT_DRIVE: db 0

times 510 - ($ - $$) db 0
dw 0xAA55