#include "vga_graphics.h"
#include "../libs/strings.h"
// Each of the positions is 2 bytes,[1]=data,[2]=color

uint16_t *video_buffer = (uint16_t *)VGA_MEM_ADR; // VGA MODE

void put_str(char *str, int x, int y)
{
    int index = y * VGA_WIDTH + x;
    // int col = VGA_WIDTH - get_len(str);
    while (*str != '\0')
    {
        if (*str == '\n')
        {
            index = 0 * VGA_WIDTH + x;
        }
        video_buffer[index] = (uint16_t)*str | (uint16_t)VGA_COLOR_WHITE << 8;
        // put_char(*str, x, y);
        str++;
        index++;
    }
}

uint16_t vga_set_terminal_color(VGA_COLOR fg_color, VGA_COLOR bg_color)
{
    return (uint16_t)fg_color | ((uint16_t)bg_color << 4);
}

void put_char(char c, int x, int y)
{
    int index = y * VGA_WIDTH + x;
    video_buffer[index] = (uint16_t)c | ((uint16_t)VGA_COLOR_WHITE << 8);
}

uint16_t vga_entry(unsigned char uc, int color)
{
    return (uint16_t)uc | (uint16_t)color << 8; /*16 bits for each position(ej:color:00011111 data:00000000)
                                                 *move the color to "start"/"high bits" "<<"
                                                 * uses | because bits should not be modified,they should be combinated                                               */
}

void init_background()
{
    int terminal_color = vga_set_terminal_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);

    for (int row = 0; row < VGA_HEIGHT; row++)
    {
        for (int col = 0; col < VGA_WIDTH; col++)
        {
            int index = row * VGA_WIDTH + col;
            video_buffer[index] = (vga_entry(' ', terminal_color));
            // video_buffer[index] = ' ' | VGA_COLOR_BLACK << 8;
        }
    }
}

void test()
{
    int y = 0;
    int x = 0;
    int index = y * VGA_WIDTH + x;

    int TOTAL = VGA_WIDTH * VGA_HEIGHT;

    for (int i = 0; i <= TOTAL; i++)
    {
        put_char('0', x, y);
        if (i == VGA_WIDTH)
        {
            y++;
            x = 0;
        }
        else
        {
            x++;
        }
    }
}
