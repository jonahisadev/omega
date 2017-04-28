C_SOURCES = $(wildcard kernel/*.c drivers/*.c kernel/cpu/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h kernel/runtime/*.h kernel/cpu/*.h)
OBJ = ${C_SOURCES:.c=.o kernel/cpu/int.o} 

CC = i386-elf-gcc
GDB = i386-elf-gdb
LD = i386-elf-ld
CFLAGS = -g -lgcc -std=gnu99

os-image: boot.bin kernel.bin
	cat $^ > os-image

kernel.bin: kernel/entry.o ${OBJ}
	${LD} -o $@ -Ttext 0x1000 $^ --oformat binary

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

boot.bin: boot/boot.asm
	nasm $< -f bin -o boot.bin

clean:
	rm -rf *.bin *.o os-image kernel/*.o drivers/*.o kernel/cpu/*.o