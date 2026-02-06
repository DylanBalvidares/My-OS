#ifndef VGA_H
#include "../libs/types.h"
#include "../libs/regis.h"

#define VGA_H
#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_MEM_ADR 0xB8000

extern uint16_t *video_buffer; // VGA MODE
extern unsigned int bg_color;
extern unsigned int fg_color;
extern unsigned int cursor_pos;

typedef enum {
  VGA_COLOR_BLACK = 0,
  VGA_COLOR_BLUE = 1,
  VGA_COLOR_GREEN = 2,
  VGA_COLOR_CYAN = 3,
  VGA_COLOR_RED = 4,
  VGA_COLOR_MAGENTA = 5,
  VGA_COLOR_BROWN = 6,
  VGA_COLOR_LIGHT_GREY = 7,
  VGA_COLOR_DARK_GREY = 8,
  VGA_COLOR_LIGHT_BLUE = 9,
  VGA_COLOR_LIGHT_GREEN = 10,
  VGA_COLOR_LIGHT_CYAN = 11,
  VGA_COLOR_LIGHT_RED = 12,
  VGA_COLOR_LIGHT_MAGENTA = 13,
  VGA_COLOR_LIGHT_BROWN = 14,
  VGA_COLOR_WHITE = 15,
} VGA_COLOR;

// void test();
void put_str(char *str, int x, int y);
void put_char(char c, int x, int y);
void clear_bg();
uint16_t vga_set_colors(VGA_COLOR fg, VGA_COLOR bg);
uint16_t get_cursor_pos();
// void clear_fg();
// void set_bg();
// void set_fg();
static inline void disable_cursor() {
  // gas inline asm
  __asm__ volatile(
      "mov $0x3D4, %%dx   \n\t" // init dx register(0x3D4)
      "mov $0x0A, %%al    \n\t" // init al register(0x0A)
      "out %%al, %%dx     \n\t" // dx(0x3D4 port) point to fifth bit(0x0A)

      "inc %%dx           \n\t" // inc port to->(0x3D5)
      "mov $0x20, %%al    \n\t" // init al register(0x20(0010 0000)->fift bit is
                                // enabled(1))
      "out %%al, %%dx     \n\t" // dx(0x3D5 port) send al content(0x20(0010
                                // 0000))
      :
      :
      : "rax", "rdx"); // used registers
}

static inline void enable_cursor(int cursor_start, int cursor_end) {

  __asm__ volatile("movb $0x3D4, %%dx           \n\t"
                   "movb $0x0A, %%al            \n\t"
                   "out %%al, %%dx             \n\t"

                   "inc %%dx                   \n\t"
                   "movb $0x0E, %[start_pos]    \n\t"
                   "out %%al, %%dx      \n\t"

                   "dec %%dx                   \n\t"
                   "movb $0x0E, %%ah      \n\t"
                   "out %%ah, %dx        \n\t"

                   :
                   : [start_pos] "al"(cursor_start), [end_pos] "ah"(cursor_end)
                   : "ax", "dx");
}

#endif
