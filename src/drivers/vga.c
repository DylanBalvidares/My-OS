#include "./vga.h"
#include "../libs/strings.h"

// Each of the positions is 2 bytes,[1]=data,[2]=color

uint16_t *video_buffer = (uint16_t *)VGA_MEM_ADR; // VGA MODE

void put_str(char *str, int x, int y) {
  int index = y * VGA_WIDTH + x;
  while (*str != '\0') {
    if (*str == '\n') {
      y++;
      x = 0;
      index = y * VGA_WIDTH + x - 1;
      video_buffer[index] = (uint16_t)' ' | (uint16_t)VGA_COLOR_WHITE << 8;
    } else {
      video_buffer[index] = (uint16_t)*str | (uint16_t)VGA_COLOR_WHITE << 8;
    }
    // put_char(*str, x, y);
    str++;
    index++;
  }
}

uint16_t vga_set_colors(VGA_COLOR fg, VGA_COLOR bg) {
  // bg_color = bg;
  // fg_color = fg;
  return (uint16_t)fg | ((uint16_t)bg << 4);
}

uint16_t get_cursor_pos() {
  uint16_t pos = 0;
  outb(0x3D4, 0x0F);                  // 0x0F:low byte of the cursor
  pos |= inb(0x3D5);                  // read low byte from 0x3D5
  outb(0x3D4, 0x0E);                  // 0x0E:high byte of the cursor
  pos |= ((uint16_t)inb(0x3D5)) << 8; //??
  return pos;
}

void put_char(char c, int x, int y) {
  int index = y * VGA_WIDTH + x;
  video_buffer[index] = (uint16_t)c | ((uint16_t)VGA_COLOR_WHITE << 8);
}

uint16_t vga_entry(unsigned char uc, int color) {
  return (uint16_t)uc |
         (uint16_t)color << 8; /*16 bits for each position(ej:color:00011111
                                *data:00000000) move the color to "start"/"high
                                *bits" "<<" uses | because bits should not be
                                *modified,they should be combinated */
}

void clear_bg() {
  int colors = vga_set_colors(VGA_COLOR_WHITE, VGA_COLOR_BLACK);

  for (int row = 0; row < VGA_HEIGHT; row++) {
    for (int col = 0; col < VGA_WIDTH; col++) {
      int index = row * VGA_WIDTH + col;
      video_buffer[index] = (vga_entry(' ', colors));
    }
  }
}
/*
void clear_fg(){

}
*/

/*
void test()
{
    int y = 0;
    int x = 0;

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
*/
