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
	
print_hex:
	pusha
	mov cx, 0
	
.loop:
	cmp cx, 4
	je .done
	
	mov ax, dx
	and ax, 0x000F
	add al, 0x30
	cmp al, 0x39
	jl .hexfmt
	add al, 7
	
.hexfmt:
	mov bx, HEX_OUT + 5
	sub bx, cx
	mov [bx], al
	inc cx
	shr dx, 4
	jmp .loop
	
.done:
	mov bx, HEX_OUT
	call print

	popa
	ret
	
HEX_OUT: db "0x0000",0