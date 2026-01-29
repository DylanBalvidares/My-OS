#include "graphics.h"

volatile char *video_memory = (volatile char *)0xB8000;

void print_string(char *str, int pos)
{
    while (*str != '\0')
    {
        video_memory[pos] = *str;
        video_memory[pos + 1] = 0x0F;
        str++;
        pos += 2;
    }
}

void set_background(void)
{

    for (int i = 0; i < 80 * 25 * 2; i += 2)
    {
        video_memory[i] = ' ';
        video_memory[i + 1] = 0x08; // Gris sobre negro
    }
}