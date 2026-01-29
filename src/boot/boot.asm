bits 32;instrucciones codificadas a 32 bits
section .multiboot
    align 4
    dd 0x1BADB002
    dd 0x00
    dd -(0x1BADB002 + 0x00)

section .text
global _start
extern kernel_main

_start:
    ; Configuramos la pila antes de llamar a C
    mov esp, stack_top    
    push ebx
    ; Llamamos a la función de C
    call kernel_main

    ; Si por alguna razón C retorna, congelamos el CPU
.hang:
    hlt
    jmp .hang

section .bss
align 16           ; La pila debe estar alineada a 16 bytes para GCC moderno
stack_bottom:
    resb 16384     ; 16 KB de espacio para la pila
stack_top:         ; El puntero de la pila apunta al FINAL (porque crece hacia abajo)

section .note.GNU-stack noalloc noexec nowrite progbits