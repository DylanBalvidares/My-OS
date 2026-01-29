#!/bin/bash
nasm -f elf32 ./boot/boot.asm -o ./bin/boot.o
gcc -m32 -c ./kernel/kernel.c  -o ./bin/kernel.o -ffreestanding -O2 -Wall
gcc -m32 -c ./drivers/graphics.c -o ./bin/graphics.o --freestanding -O2 -Wall

ld -m elf_i386 -T ./boot/linker.ld -o ./bin/kernel.bin    ./bin/boot.o    ./bin/kernel.o    ./bin/graphics.o    --no-warn-rwx-segments

