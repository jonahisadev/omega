#ifndef MEM_H
#define MEM_H

static void* KMEM = (void*)0x100000;
static u32 KMEM_OFFSET = 0;

void* kmalloc(u32 size);

//
//	IMPLEMENTATION
//

void* kmalloc(u32 size) {
	int* ptr = *(&KMEM + KMEM_OFFSET);
	KMEM_OFFSET += size;
	return ptr;
}

#endif // MEM_H