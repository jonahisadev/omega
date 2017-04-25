[ORG 0x7C00]

main:
	jmp $
	
times 510 - ($ - $$) db 0
dw 0xAA55