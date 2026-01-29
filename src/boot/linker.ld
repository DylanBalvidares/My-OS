ENTRY(_start)
SECTIONS {
    . = 1M; /* Los kernels se cargan usualmente en 1MB */

    .text : {
        *(.multiboot) /* PRIMERO la cabecera Multiboot */
        *(.text)
    }
    .data : { *(.data) }
    .bss  : { *(.bss)  }
}