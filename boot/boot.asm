[ORG 0x7C00]

main:
	mov [BOOT_DRIVE], dl

	mov bp, 0x8000
	mov sp, bp
	
	mov bx, HELLO
	call print
	call print_nl
	
	mov dh, 2
	mov bx, 0x9000
	mov dl, [BOOT_DRIVE]
	call disk_load
	
	mov dx, [0x9000]
	call print_hex
	call print_nl
	
	mov dx, [0x9000 + 512]
	call print_hex
	
	jmp $
	
%include "boot/print.asm"
%include "boot/disk.asm"

HELLO: db "Hello BIOS!",0
BOOT_DRIVE: db 0
	
times 510 - ($ - $$) db 0
dw 0xAA55

times 256 dw 0xACDC
times 256 dw 0xFACE