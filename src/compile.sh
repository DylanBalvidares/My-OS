#!/bin/bash
nasm -f elf32 ./boot/boot.asm -o ./bin/boot.o
gcc -m32 -c ./kernel/kernel.c  -o ./bin/kernel.o -ffreestanding -O2 -Wall
gcc -m32 -c ./drivers/vga.c -o ./bin/vga.o -ffreestanding -O2 -Wall
gcc -m32 -c ./tui/terminal_ui.c -o ./bin/terminal_ui.o -ffreestanding -O2 -Wall
gcc -m32 -c ./libs/strings.c -o ./bin/strings.o -ffreestanding -O2 -Wall
gcc -m32 -c ./drivers/keyboard.c -o ./bin/keyboard.o -ffreestanding -O2 -Wall

ld -m elf_i386 -T ./boot/linker.ld -o ./bin/kernel.bin    ./bin/boot.o    ./bin/kernel.o    ./bin/vga.o   ./bin/strings.o   ./bin/terminal_ui.o  ./bin/keyboard.o  --no-warn-rwx-segments

