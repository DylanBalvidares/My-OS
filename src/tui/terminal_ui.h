#ifndef TERMINAL_UI_H
#define TERMINAL_UI_H
#include "../drivers/vga.h"

typedef struct
{
    char *text_buffer;
    unsigned int terminal_cursor;//y & x
} TERMINAL;

void initialize_terminal();

#endif
