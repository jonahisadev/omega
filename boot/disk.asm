disk_load:
	push dx
	
	mov ah, 0x02
	mov al, dh
	mov ch, 0x00
	mov dh, 0x00
	mov cl, 0x02
	int 0x13
	
	jc disk_error
	
	pop dx
	cmp al, dh
	jne disk_error
	
	ret
	
disk_error:
	mov bx, DISK_ERR
	call print
	jmp $
	
DISK_ERR: db "Error loading disk...",0