[BITS 16]
switch_mode:
	cli
	lgdt [gdt_desc]
	
	mov eax, cr0
	or eax, 0x1
	mov cr0, eax
	
	jmp CODE_SEG:init_mode
	
[BITS 32]	
init_mode:
	push ax
	mov ax, DATA_SEG
	
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	
	mov ebp, 0x90000
	mov esp, ebp
	
	jmp BEGIN_32