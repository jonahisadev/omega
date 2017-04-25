print:
	pusha
	mov ah, 0x0E
	
.loop:
	mov al, [bx]
	cmp al, 0
	jz .done
	int 0x10
	inc bx
	jmp .loop
	
.done:
	popa
	ret
	
print_nl:
	pusha
	mov ah, 0x0E
	mov al, 13
	int 0x10
	mov al, 10
	int 0x10
	popa
	ret