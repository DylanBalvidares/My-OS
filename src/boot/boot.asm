[BITS 32]           ;32 bits instructions

section .multiboot  ;multiboot header
    align 4         
    dd 0x1BADB002   ;magic number,required for identify multiboot standard
    dd 0x00         ;flag
    dd -(0x1BADB002 + 0x00);checksum, this should equal 0

section .text
    
global _start   ;exports _start symbol,so the linker know where starts the code
extern kernel_main  ;external function in a C file

_start:
    ;esp->expanded stack pointer
    mov esp, stack_top    ;Config stack 
    push ebx              ;Pass argument to C function(EBX reg contains a pointer),that contain system data
    call kernel_main      ;call kernel main 

.stop: ; when C returns,cpu stops
    hlt ;halt->stop cpu
    jmp .stop

section .bss
align 16           ; set the align to 16 bits,gcc works best that way

stack_bottom:
    resb 16384     ; reserves 16 KB for the stack
stack_top:         ; pointer to end of the stack

section .note.GNU-stack noalloc noexec nowrite progbits